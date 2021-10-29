#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FlexCAN.h>

#include <Fonts/FreeMono9pt7b.h>

#include "Paddle.h"
#include "Ball.h"

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define JOY_DOWN 22
#define JOY_UP 23
#define JOY_CLICK 19
#define JOY_LEFT 18
#define JOY_RIGHT 17

#define OLED_DC     6
#define OLED_CS     10
#define OLED_RESET  5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

Paddle leftPaddle(LEFT);
Paddle rightPaddle(RIGHT);
Ball ball(RIGHT);

int joyUp, joyDown, joyClick, joyUpSlave, joyDownSlave, joyClickSlave;
bool gameState = false;
bool gameStart = true;
bool isMaster = false;
bool endGame = false;
bool updateGame = false;
int gruppeNr = 2;
int turn = 0;

unsigned long currentMillis;
unsigned long lastMillis = 0;
const int updateRate = 10; // ms
unsigned long millisDiff;

int scoreMaster = 0;
int scoreSlave = 0;

static CAN_message_t TX_Ball;
static CAN_message_t TX_Paddle;
static CAN_message_t TX_Joy;
static CAN_message_t RX_Ball;
static CAN_message_t RX_Paddle;
static CAN_message_t RX_Joy;


void setup() {
  Serial.begin(9600);
  Can0.begin(1000000);

  pinMode(JOY_DOWN, INPUT);
  pinMode(JOY_UP, INPUT);
  pinMode(JOY_CLICK, INPUT);
  pinMode(JOY_LEFT, INPUT);
  pinMode(JOY_RIGHT, INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.fillScreen(BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Paddle CAN message (for sending data to slave)
  TX_Paddle.id = gruppeNr + 20; // 22
  TX_Paddle.len = 7;
  TX_Paddle.buf[0] = leftPaddle.paddle_y;
  TX_Paddle.buf[1] = rightPaddle.paddle_y;
  TX_Paddle.buf[2] = joyClick;
  TX_Paddle.buf[3] = scoreMaster;
  TX_Paddle.buf[4] = scoreSlave;
  TX_Paddle.buf[5] = gameState;
  TX_Paddle.buf[6] = turn;
  
  // Ball CAN message (for sending data to slave)
  TX_Ball.id = gruppeNr + 50; // 52
  TX_Ball.len = 2;
  TX_Ball.buf[0] = ball.x;
  TX_Ball.buf[1] = ball.y;

  // Joy CAN message (for sending data to master)
  TX_Joy.id = 0;
  TX_Joy.len = 3;
  TX_Joy.buf[0] = joyUp;
  TX_Joy.buf[1] = joyDown;
  TX_Joy.buf[2] = joyClick;
}

void loop() {  
  currentMillis = millis();
  
  selectMaster();
  readJoy();
  receiveSlaveJoy();
  gameState = true;

    millisDiff = currentMillis - lastMillis;
    if(millisDiff >= updateRate)
    {
      updateGame = true;
    }
    // Game sequence
    while(gameState == true && updateGame == true)
    {
      if(isMaster)
      {
      movePaddle(); // Move paddles based on read data
      }
      draw(); // Draw
      if (gameOver())
      {
        endGame = true;
      }
      display.display();
      display.fillScreen(BLACK);
      //delay(10);
      lastMillis = millis();
      updateGame = false;
    }

}

void readJoy()
{
  joyUp = digitalRead(JOY_UP);
  joyDown = digitalRead(JOY_DOWN);
  joyClick = digitalRead(JOY_CLICK);

  if(!isMaster)
  {
    TX_Joy.buf[0] = joyUp;
    TX_Joy.buf[1] = joyDown;
    TX_Joy.buf[2] = joyClick;
    Can0.write(TX_Joy);
  }
}

void receiveSlaveJoy()
{
  if(isMaster){
      if(Can0.available())
      {
      Can0.read(RX_Joy);
      
      if (RX_Joy.id == 0)
      {
        joyUpSlave = RX_Joy.buf[0];
        joyDownSlave = RX_Joy.buf[1];
        joyClickSlave = RX_Joy.buf[2];
      }
   }
  }
}

void movePaddle()
{
    if(joyUp == 0)
    {
      leftPaddle.moveUp();
    }else if(joyDown == 0)
    {
      leftPaddle.moveDown();
    }
    if(joyUpSlave == 0)
    {
      rightPaddle.moveUp();
    }else if(joyDownSlave == 0)
    {
      rightPaddle.moveDown();
    }
}

void draw()
{
  display.drawRect(0, 0, 128, 64, WHITE); // Rectangle around whole display
  if(isMaster)
  {
    display.setCursor(1,1);
    display.print("MASTER");
    display.setCursor(SCREEN_WIDTH/2 - 20, 2);
    display.print("Slave: ");
    display.println(scoreSlave);
    display.setCursor(SCREEN_WIDTH/2 - 20, 10);
    display.print("Master: ");
    display.println(scoreMaster);
    
    display.fillRect(leftPaddle.paddle_x, leftPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE); // Left paddle
    display.fillRect(rightPaddle.paddle_x, rightPaddle.paddle_y, rightPaddle.paddleWidth, rightPaddle.paddleHeight,  WHITE); // Right paddle

    TX_Paddle.buf[0] = leftPaddle.paddle_y;
    TX_Paddle.buf[1] = rightPaddle.paddle_y;
    if(ball.turn == LEFT)
    {
      TX_Paddle.buf[6] = 1;
    }else
    {
      TX_Paddle.buf[6] = 0;
    }
    Can0.write(TX_Paddle);
  
    ball.moveBall();
    ball.limitCheck();
    
      // Right paddle settings
    if(ball.x > (SCREEN_WIDTH - 2*ball.r - rightPaddle.paddleWidth) && (ball.y > rightPaddle.paddle_y - ball.r && ball.y < rightPaddle.paddle_y+rightPaddle.paddleHeight + ball.r))
    {
      ball.xDir = ball.xDir*(-1);
      // Left paddle settings
    }else if(ball.x < (2*ball.r + leftPaddle.paddleWidth - 1) && (ball.y > leftPaddle.paddle_y - ball.r && ball.y < leftPaddle.paddle_y+leftPaddle.paddleHeight + ball.r))
    {
      ball.xDir = ball.xDir*(-1);
    }
    
    display.fillCircle(ball.x, ball.y, ball.r, WHITE); // Ball
    TX_Ball.buf[0] = ball.x;
    TX_Ball.buf[1] = ball.y;
    Can0.write(TX_Ball);
  }else
  {
    if(Can0.available())
      {
        Can0.read(RX_Paddle);
        
        if (RX_Paddle.id == 22)
        {
          leftPaddle.paddle_y = RX_Paddle.buf[0];
          rightPaddle.paddle_y = RX_Paddle.buf[1];
          scoreMaster = RX_Paddle.buf[3];
          scoreSlave = RX_Paddle.buf[4];

          display.setCursor(1,1);
          display.print("SLAVE");
          display.setCursor(SCREEN_WIDTH/2 - 20, 2);
          display.print("Slave: ");
          display.println(scoreSlave);
          display.setCursor(SCREEN_WIDTH/2 - 20, 10);
          display.print("Master: ");
          display.println(scoreMaster);
          
          display.fillRect(leftPaddle.paddle_x, leftPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE); // Left paddle
          display.fillRect(rightPaddle.paddle_x, rightPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE); // Right paddle
        }
      }

    if(Can0.available())
      {
        Can0.read(RX_Ball);
        
        if (RX_Ball.id == 52)
        {
          ball.x = RX_Ball.buf[0];
          ball.y = RX_Ball.buf[1];
          display.fillCircle(ball.x, ball.y, ball.r, WHITE); // Ball
        }
      }
  }
}

bool gameOver()
{
  if (ball.x < 0 || ball.x > SCREEN_WIDTH)
  {

    if(Can0.available())
      {
        Can0.read(RX_Paddle);
        
        if (RX_Paddle.id == 22)
        {
          turn = RX_Paddle.buf[6];
          Serial.print("Turn: ");
          Serial.println(turn);
        }
      }
    gameState = false;
    TX_Paddle.buf[5] = gameState; // Send gameState to slave
    display.fillScreen(BLACK);
    display.setCursor(25,25);
    if(isMaster)
    {
    if(ball.turn == RIGHT)
    {
      display.print("Point to Master");
      scoreMaster += 1;
    }else if(ball.turn == LEFT)
    {
      display.print("Point to Slave");
      scoreSlave += 1;
    }
    }else
    {
      if(turn == 0)
      {
        display.print("Point to Master");
      }else if(turn == 1)
      {
        display.print("Point to Slave");
      }
    }
  resetGame();
  TX_Paddle.buf[3] = scoreMaster;
  TX_Paddle.buf[4] = scoreSlave;
  Can0.write(TX_Paddle);
  display.display();
  delay(1000);
  return true;
  }else
  {
    return false;
  }
}

void selectMaster()
{
  // Loop for selecting master
  while(gameStart)
  {
    // Starting screen before selecting master
    display.setCursor(25,25);
    display.print("Press joy");
    display.setCursor(10,35);
    display.println("to select master");
    display.display();
  
    // Check if other device wants to be master
    if(Can0.available())
    {
      Can0.read(RX_Joy);
      
      if (RX_Joy.id == 0 && RX_Joy.buf[2] == 0)
      {
        isMaster = false;
        gameStart = false;
        display.setCursor(1,1);
        display.print("SLAVE");
        display.display();
      }
    }
    
    // Check if you want to be master
    readJoy();

    if(joyClick == 0)
    {
      TX_Joy.buf[2] = joyClick;
      isMaster = true;
      gameStart = false;

      Can0.write(TX_Joy);
      display.setCursor(1,1);
      display.print("MASTER");
      display.display();
    }
  }

//delay(1000);
}

void resetGame()
{
    ball.x = SCREEN_WIDTH/2;
    ball.y = SCREEN_HEIGHT/2 -11;

    leftPaddle.paddle_y = (SCREEN_HEIGHT/2)-(leftPaddle.paddleHeight/2);
    rightPaddle.paddle_y = (SCREEN_HEIGHT/2)-(rightPaddle.paddleHeight/2);

    TX_Ball.buf[0] = ball.x;
    TX_Ball.buf[1] = ball.y;

    TX_Paddle.buf[0] = leftPaddle.paddle_y;
    TX_Paddle.buf[1] = rightPaddle.paddle_y;
    
}

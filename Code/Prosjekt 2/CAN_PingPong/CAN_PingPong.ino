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

int joyUp, joyDown, joyClick;
bool gameState = false;
bool gameStart = true;
bool isMaster = false;
int gruppeNr = 2;

int scoreMaster = 0;
int scoreSlave = 0;

static CAN_message_t TX;
static CAN_message_t RX;

void setup() {
  Serial.begin(9600);
  Can0.begin(250000);

  pinMode(JOY_DOWN, INPUT);
  pinMode(JOY_UP, INPUT);
  pinMode(JOY_CLICK, INPUT);
  pinMode(JOY_LEFT, INPUT);
  pinMode(JOY_RIGHT, INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.fillScreen(BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);

}

void loop() {

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
      Can0.read(RX);
      
      if (RX.buf[2] == 0)
      {
        isMaster = false;
        gameStart = false;
      }
    }
    
    // Check if you want to be master
    readJoy();

    if(joyClick == 0)
    {
      isMaster = true;
      gameStart = false;

      sendCAN(); // Send CAN message to let othe device know that it is slave.
    }
  }

  readJoy();
  if(joyClick == 0 && isMaster)
  {
    // Set initial entity settings
    gameState = true;
    ball.x = SCREEN_WIDTH/2;
    ball.y = SCREEN_HEIGHT/2;

    leftPaddle.paddle_y = (SCREEN_HEIGHT/2)-(leftPaddle.paddleHeight/2);
    rightPaddle.paddle_y = (SCREEN_HEIGHT/2)-(rightPaddle.paddleHeight/2);
  }

  while(gameState == true){
  readJoy(); // Read device joystick
  if(!isMaster)
    {
      sendCAN();
    }
  receiveCAN(); // Read slave joystick
  movePaddle(); // Move paddles based on read data
  draw(); // Draw
  gameOver(); // End game if master or slave loses, and update scores.
 
  display.display();
  display.fillScreen(BLACK);
  delay(10);
  }
}

void readJoy()
{
  joyUp = digitalRead(JOY_UP);
  joyDown = digitalRead(JOY_DOWN);
  joyClick = digitalRead(JOY_CLICK);
}

void sendCAN()
{
  TX.id = gruppeNr + 20;
  TX.len = 8;
  TX.buf[0] = joyUp;
  TX.buf[1] = joyDown;
  TX.buf[2] = joyClick;
  Can0.write(TX);
}

void receiveCAN()
{
  if(Can0.available())
    {
      Can0.read(RX);
    }
}


void movePaddle()
{
  //if(ball.turn == RIGHT)
  //{
    if(RX.buf[0] == 1)
    {
      leftPaddle.moveUp();
    }else if(RX.buf[1] == 1)
    {
      leftPaddle.moveDown();
    }
  //}else if(ball.turn == LEFT)
  //{
    if(joyUp == 0)
    {
      rightPaddle.moveUp();
    }else if(joyDown == 0)
    {
      rightPaddle.moveDown();
   // }
  }
}

void draw()
{
  display.drawRect(0, 0, 128, 64, WHITE); // Rectangle around whole display
  if(isMaster)
  {
    display.setCursor(1,1);
    display.print("MASTER");
  }
  display.setCursor(SCREEN_WIDTH/2 - 20, 2);
  display.print("Slave: ");
  display.println(scoreSlave);
  display.setCursor(SCREEN_WIDTH/2 - 20, 10);
  display.print("Master: ");
  display.println(scoreMaster);
  
  display.fillRect(leftPaddle.paddle_x, leftPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE); // Left paddle
  display.fillRect(rightPaddle.paddle_x, rightPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE); // Right paddle

  ball.moveBall();
  ball.limitCheck();
    // Left paddle settings
  if(ball.x > (SCREEN_WIDTH - 2*ball.r - leftPaddle.paddleWidth) && (ball.y > leftPaddle.paddle_y && ball.y < leftPaddle.paddle_y+leftPaddle.paddleHeight))
  {
    ball.xDir = ball.xDir*(-1);
    // Right paddle settings
  }else if(ball.x < (2*ball.r + rightPaddle.paddleWidth) && (ball.y > rightPaddle.paddle_y && ball.y < rightPaddle.paddle_y+rightPaddle.paddleHeight))
  {
    ball.xDir = ball.xDir*(-1);
  }
  
  display.fillCircle(ball.x, ball.y, ball.r, WHITE); // Ball
}

void gameOver()
{
  if (ball.x < 0 || ball.x > SCREEN_WIDTH)
  {
    gameState = false;
    display.fillScreen(BLACK);
    display.setCursor(25,25);
    if(ball.turn == RIGHT)
    {
      display.print("Point to Master");
      scoreMaster += 1;
    }else if(ball.turn == LEFT)
    {
      display.print("Point to Slave");
      scoreSlave += 1;
    }
    display.display();
  }
}
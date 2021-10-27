#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Paddle.h>


#define JOY_DOWN 23
#define JOY_UP 22
#define JOY_CLICK 19
#define JOY_LEFT 18
#define JOY_RIGHT 17

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_DC     6
#define OLED_CS     10
#define OLED_RESET  5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.fillScreen(BLACK);
  display.display();

  pinMode(JOY_DOWN, INPUT);
  pinMode(JOY_UP, INPUT);
  pinMode(JOY_LEFT, INPUT);
  pinMode(JOY_RIGHT, INPUT);

  display.drawRect(0, 0, 128, 64, WHITE); // Rectangle around whole display
  display.fillCircle(128/2, 64/2, 3, WHITE); // Ball
  display.display();

  Paddle leftPaddle;
  Paddle rightPaddle;

}

void loop() {
  Serial.println(leftPaddle.paddle_x)
  display.fillRect(leftPaddle_x, leftPaddle_y, paddleWidth, paddleHeight, WHITE);
  display.fillRect(rightPaddle_x, rightPaddle_y, paddleWidth, paddleHeight,  WHITE);
  display.display();

}

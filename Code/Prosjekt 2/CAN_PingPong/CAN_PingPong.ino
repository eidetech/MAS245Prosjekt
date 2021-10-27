#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Paddle.h"
#include "Controller.h"


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_DC     6
#define OLED_CS     10
#define OLED_RESET  5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

Paddle leftPaddle(LEFT);
Paddle rightPaddle(RIGHT);

Controller ctrl(LEFT);

int x;

void setup() {
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.fillScreen(BLACK);
  display.display();

}

void loop() {
  display.drawRect(0, 0, 128, 64, WHITE); // Rectangle around whole display
  display.fillCircle(128/2, 64/2, 3, WHITE); // Ball

  
  //Serial.println(leftPaddle.paddle_x);
  display.fillRect(ctrl.paddle_x, ctrl.paddle_y, ctrl.paddleWidth, ctrl.paddleHeight, WHITE);
  //display.fillRect(rightPaddle.paddle_x, rightPaddle.paddle_y, leftPaddle.paddleWidth, leftPaddle.paddleHeight,  WHITE);
  
  x = digitalRead(JOY_UP);
  Serial.println(x);
  ctrl.up();
  ctrl.down();
  display.display();
  //leftPaddle.moveDown();
  //rightPaddle.moveUp();
  display.fillScreen(BLACK);
  delay(50);

}

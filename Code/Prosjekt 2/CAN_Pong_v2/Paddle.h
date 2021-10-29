#ifndef Paddle_h
#define Paddle_h

#define SCREEN_HEIGHT 64
#include "Arduino.h"

enum side
{
  LEFT = 1,
  RIGHT = 128-4
};

class Paddle
{
public:
  uint8_t paddleWidth;
  uint8_t paddleHeight;
  uint8_t paddle_x;
  uint8_t paddle_y;

  Paddle(side paddleSide);
  ~Paddle();

  void moveUp();
  void moveDown();
  
private:

};

#endif

#ifndef Ball_h
#define Ball_h

#include "Paddle.h"

class Ball : public Paddle
{
public:
  uint8_t x = 128/2;
  uint8_t y = 64/2;
  uint8_t xDir = 1;
  uint8_t yDir= 1;
  uint8_t r = 3;
  side turn = RIGHT;

  void moveBall();
  void limitCheck();


  Ball(side paddleSide);
  ~Ball();
  
private:

};

#endif

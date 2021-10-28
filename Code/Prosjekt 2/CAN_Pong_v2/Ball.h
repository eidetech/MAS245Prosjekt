#ifndef Ball_h
#define Ball_h

#include "Paddle.h"

class Ball : public Paddle
{
public:
  int x = 128/2;
  int y = 64/2;
  int xDir = 1;
  int yDir= 1;
  int r = 3;
  side turn = RIGHT;

  void moveBall();
  void limitCheck();


  Ball(side paddleSide);
  ~Ball();
  
private:

};

#endif

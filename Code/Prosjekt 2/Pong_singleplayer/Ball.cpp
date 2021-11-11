#include "Ball.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Constructor
Ball::Ball(side paddleSide) : Paddle(paddleSide)
{

}

Ball::~Ball()
{

}

void Ball::moveBall()
{
  if(xDir == 1)
  {
    x++;
    turn = LEFT;
  }else
  {
    x--;
    turn = RIGHT;
  }
  if(yDir == 1)
  {
    y--;
  }else
  {
    y++;
  }
}

void Ball::limitCheck()
{
  if(y > SCREEN_HEIGHT - 2*r)
  {
    yDir = yDir*(-1);
  }else if(y < 2*r)
  {
    yDir = yDir*(-1);
  }
}

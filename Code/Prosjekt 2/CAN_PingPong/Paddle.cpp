#include "Paddle.h"

// Constructor
Paddle::Paddle(side paddleSide)
{
  paddleWidth = 3;
  paddleHeight = 20;
  if(paddleSide == LEFT)
  {
  paddle_x = LEFT;
  }else if (paddleSide == RIGHT)
  {
  paddle_x = RIGHT;
  }else
  {
    paddle_x = 0;
  }
  paddle_y = (SCREEN_HEIGHT/2)-(paddleHeight/2);
}

// Destructor
Paddle::~Paddle()
{
  
}

// Function for moving paddle upwards
void Paddle::moveUp()
{
  if(paddle_y < (SCREEN_HEIGHT-paddleHeight-1))
  {
  paddle_y++;
  }
}

// Function for moving paddle downwards
void Paddle::moveDown()
{
  if(paddle_y > 1)
  {
  paddle_y--;
  }
}

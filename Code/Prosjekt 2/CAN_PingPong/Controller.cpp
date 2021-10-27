#include "Controller.h"
#include "Arduino.h"



Controller::Controller(side paddleSide) : Paddle(paddleSide)
{
  pinMode(JOY_DOWN, INPUT);
  pinMode(JOY_UP, INPUT);
  pinMode(JOY_LEFT, INPUT);
  pinMode(JOY_RIGHT, INPUT);
  
}

Controller::~Controller()
{
  
}

void Controller::up()
{
  if(digitalRead(JOY_UP) == 0)
  {
   moveUp();
  }
}

void Controller::down()
{
  if(digitalRead(JOY_DOWN) == 0)
  {
   moveDown();
  }
}

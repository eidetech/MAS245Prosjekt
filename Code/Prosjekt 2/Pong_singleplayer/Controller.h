#ifndef Controller_h
#define Controller_h

#include "Paddle.h"

#define JOY_DOWN 23
#define JOY_UP 22
#define JOY_CLICK 19
#define JOY_LEFT 18
#define JOY_RIGHT 17

class Controller : public Paddle
{
public:
  Controller(side paddleSide);
  ~Controller();

  void up();
  void down();
  
private:

};

#endif

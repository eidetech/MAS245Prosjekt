#ifndef Paddle_h
#define Paddle_h

#define SCREEN_HEIGHT 64

enum side
{
  LEFT = 128-3,
  RIGHT = 0
};

class Paddle
{
public:
  int paddleWidth;
  int paddleHeight;
  int paddle_x;
  int paddle_y;

  Paddle(side paddleSide);
  ~Paddle();

  void moveUp();
  void moveDown();
  
private:

};

#endif

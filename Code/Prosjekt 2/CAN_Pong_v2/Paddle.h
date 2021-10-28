#ifndef Paddle_h
#define Paddle_h

#define SCREEN_HEIGHT 64

enum side
{
  LEFT = 1,
  RIGHT = 128-4
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

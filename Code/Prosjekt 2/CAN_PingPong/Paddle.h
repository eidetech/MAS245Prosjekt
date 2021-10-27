class Paddle
{
private:
  /* data */
public:
int paddleWidth = 3;
int paddleHeight = 20;
int paddle_x = 0;
int paddle_y = (SCREEN_HEIGHT/2)-(paddleHeight/2);


  Paddle(/* args */);
  ~Paddle();
};

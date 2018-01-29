#define X 6
#define Y 7
#define __BLUE__ 6 //pin to control blue
#define __RED__ 7 //pin to control red
#define __GREEN__ 8 // pin to conttol green

int board[X][Y];
void setup()
{
  for (int i=0; i<X; ++i;)
    for (int j=0;j<Y;++j)
      board[i][j]=0;
  pinMode(__BLUE__, OUTPUT);
  pinMode(__RED__, OUTPUT);
  pinMode(__GREEN__, OUTPUT);
  
}

void loop()
{
  

}

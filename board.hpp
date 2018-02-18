#include <PololuLedStrip.h>

#ifndef __BOARD_H__
#define __BOARD_H__
 
#define SCORE 4
#define X 7
#define Y 6
#define verbose 0


const rgb_color PLAYER=rgb_color(100,00,00);
const rgb_color CPU=rgb_color(00,00,100);
const rgb_color EMPTY=rgb_color(00,00,00);
	PololuLedStrip<7> y0;
	PololuLedStrip<8> y1;
	PololuLedStrip<9> y2;
	PololuLedStrip<10> y3;
	PololuLedStrip<11> y4;
	PololuLedStrip<12> y5;
	PololuLedStrip<13> y6;

#define LED_COUNT 6
class board{
private:
	int matrix[X][Y];
	rgb_color colors[LED_COUNT];
public:
	board();
	void setToken(int col, int select);
	int checkVertical();
	int checkHorizontal();
	int checkLeftDiag();
	int checkRightDiag();
	int checkBoard();
	void update(int);
	int lastToken(int col);
	bool columnFull(int col);
	void flash_win(int, int, short, bool);
};



#endif
#ifndef __BOARD_H__
#define __BOARD_H__

#define SCORE 4
#define X 7
#define Y 6
#define verbose 0

class board{
private:
	int matrix[X][Y+1];
	int lastMove;
public:
	board();
	void setToken(int col, int select=2);
	int checkVertical();
	int checkHorizontal();
	int checkLeftDiag();
	int checkRightDiag();
	int checkBoard();
	void print();
	int topToken(int col);
	bool columnFull(int col);
	int ReadLastMove();
};

#endif
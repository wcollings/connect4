#ifndef __ROW_H__
#define __ROW_H__

#define SCORE 4
#define X 7
#define Y 6

class board{
private:
	int matrix[X][Y];
public:
	board();
	void setToken(int col, int select);
	bool checkVertical();
	bool checkHorizontal();
	bool checkLeftDiag();
	bool checkRightDiag();
	bool checkBoard();
	void print();
	int lastToken(int col);
};



#endif
#ifndef __ROW_H
#define __ROW_H

#define SCORE 4

struct row
{
	unsigned int r1: 2;
	unsigned int r2: 2;
	unsigned int r3: 2;
	unsigned int r4: 2;
	unsigned int r5: 2;
	unsigned int r6: 2;
	unsigned int player: 3;
	unsigned int cpu:3;
};

class board{
private:
	row matrix[7];
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
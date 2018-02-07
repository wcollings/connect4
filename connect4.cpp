#include <cmath>
#include <ctime>
#include <iostream>
#include "ai.hpp"

using namespace std;


int main(void)
{
	board Board;
	ai machine(&Board);
	srand(time(NULL));
	int r=0, random=0;
	Board.print();
	while (!Board.checkBoard())
	{
		random=rand()%6;
		cout <<"give me a row position: ";
		cin >>r;
		machine.logPlayerMove(r);
		Board.setToken(r, 1);
		Board.print();
		Board.checkBoard();
		Board.setToken(machine.place(), 2);
		Board.print();
		Board.checkBoard();
	}
}

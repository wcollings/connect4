#ifndef __AI_HPP__
#define __AI_HPP__

#include "row.hpp"

class ai{
	private:
	board *Board;
	int turns;
	int lastPlayerMoves[4];
	int lastAiMoves[4];
	public:
	int place();
	ai();
	ai(board*);
	void logPlayerMove(int column);
};

#endif
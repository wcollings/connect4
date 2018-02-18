#include "board.hpp"

#ifndef __AI_HPP__
#define __AI_HPP__


class ai{
	private:
	board *Board;
	int turns;
	int lastPlayerMoves[4];
	int lastAiMoves[4];
	int lastAttackPosition;
	bool play_up;
	public:
	int place();
	ai();
	ai(board*);
	void logPlayerMove(int column);
	int attack();
	int defend();
	void reset();
};


#endif
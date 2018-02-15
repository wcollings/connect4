#include "ai.hpp"

#include <cmath>
ai::ai()
{
	srand(10);
	for (int i=0; i < 4; ++i)
	{
		lastPlayerMoves[i]=-1;
		lastAiMoves[i]=-1;
	}
	turns=0;
}

ai::ai(board* Board)
{
	this->Board=Board;
	srand(10);
	for (int i=0; i < 4; ++i)
	{
		lastPlayerMoves[i]=-1;
		lastAiMoves[i]=-1;
	}
	turns=0;
}
/*
**each weight is random, but the difference classes have different upper or lower limits.
**that way the machine seems methodical, but not asshole-y.
**next step is programming it to try to win for itself, and not just stop you. 
*/
int ai::place()
{
	int random_move=rand()%6;
	int guess=0, lastWeight=0;
	if (turns==0)
		guess=random_move;
		//person keeps picking the same column
	else if (lastPlayerMoves[0] ==lastPlayerMoves[1])
	{
		if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0];
			lastWeight=rand()%5;
		}
	}
	//doing a sideways or diagonal pattern
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]+1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]-1;
			lastWeight=rand()%5;
		}   
	}
	//doing the other sideways/diagonal
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]-1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]+1;
			lastWeight=rand()%5;
		}   
	}
	//play a random move. just to add chaos
	if (rand()%4 > lastWeight)
		guess=random_move;
	if (guess <0 || guess > 6)
		guess=3;

	//push its choice onto its stack of last moves
	for (int i=3; i > 0; --i)
	{
		lastAiMoves[i]=lastAiMoves[i+1];
	}
	lastAiMoves[0]=guess;
	return guess;
}
/*
**records the last 4 moves made by player, to help deciding where to go
*/
void ai::logPlayerMove(int column)
{
	turns++;
	for (int i=3; i > 0; --i)
	{
		lastPlayerMoves[i]=lastPlayerMoves[i-1];
	}
	lastPlayerMoves[0]=column;
}


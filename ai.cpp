#include "ai.hpp"

#include <cmath>
#include <iostream>

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

int ai::place()
{
	int random_move=rand()%6;
	int guess=0, lastWeight=0;
	if (turns==0)
		guess=random_move;
	else if (lastPlayerMoves[0] ==lastPlayerMoves[1])
	{
		if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0];
			lastWeight=rand()%5;
		}
	}
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]+1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]-1;
			lastWeight=rand()%5;
		}   
	}
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]-1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]+1;
			lastWeight=rand()%5;
		}   
	}
	if (rand()%4 > lastWeight)
		guess=random_move;
	if (guess <0 || guess > 6)
		guess=3;

	for (int i=3; i > 0; --i)
	{
		lastAiMoves[i]=lastAiMoves[i+1];
	}
	lastAiMoves[0]=guess;
	return guess;
}

void ai::logPlayerMove(int column)
{
	turns++;
	for (int i=3; i > 0; --i)
	{
		lastPlayerMoves[i]=lastPlayerMoves[i-1];
	}
	lastPlayerMoves[0]=column;
}

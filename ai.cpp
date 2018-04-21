#include "ai.hpp"
#include <iostream>
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
	lastAttackPosition=0;
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
	lastAttackPosition=0;
}
/*
**each weight is random, but the difference classes have different upper or lower limits.
**that way the machine seems methodical, but not asshole-y.
**next step is programming it to try to win for itself, and not just stop you. 
*/
int ai::place()
{
	int choice;
	int random_move=rand()%6;
	int guess=-1, lastWeight=0;
	if (turns==0)
		guess=random_move;
		//person keeps picking the same column
	else if (lastPlayerMoves[0] ==lastPlayerMoves[1])
	{
		if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0];
			lastWeight=rand()%5;
			choice=0;
		}
	}
	//doing a sideways or diagonal pattern
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]+1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]-1;
			lastWeight=rand()%5;
			choice=1;
		}   
	}
	//doing the other sideways/diagonal
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]-1)
	{
	 if (lastWeight < 3)
		{
			guess=lastPlayerMoves[0]-1;
			lastWeight=rand()%5;
			choice=2;
		}   
	}
	//play a random move. just to add chaos
	if (rand()%4 > lastWeight)
	{
		guess=attack();
		choice=3;
	}
	if (guess == -1)
	{
		guess=rand()%6;
		choice=4;
	}
	if (guess <0 || guess > 6)
		guess=3;

	//push its choice onto its stack of last moves
	for (int i=3; i > 0; --i)
	{
		lastAiMoves[i]=lastAiMoves[i+1];
	}
	lastAiMoves[0]=guess;
	#if verbose==1
	std::cout <<"Went with choice " <<choice <<'\n';
	#endif
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

int ai::attack()
{
	if (Board->topToken(lastAttackPosition) != 2 ||  Board->columnFull(lastAttackPosition))
		lastAttackPosition++;
	if (lastAttackPosition >= 6)
		lastAttackPosition=0;
	return lastAttackPosition;
}


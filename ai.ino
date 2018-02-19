#include "ai.hpp"
ai::ai()
{
	randomSeed(10);
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
	randomSeed(10);
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
	int random_move=random(30);
	int guess=-1, lastWeight=0;
	if (turns<2)
		guess= attack();
	if (random_move >20  || turns%2==0)
		guess=defend();
	else if (random_move > 10)
		guess=attack();
	else 	//play a random move. just to add chaos
	{
		guess=random_move%7;
	}
	//push its choice onto its stack of last moves
	for (int i=3; i > 0; --i)
	{
		lastAiMoves[i]=lastAiMoves[i+1];
	}
	if (guess==-1) return 3;

	lastAiMoves[0]=guess;
	#if verbose==1
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
	if (play_up)
	{
		if (Board->lastToken(lastAttackPosition) != 2 ||  Board->columnFull(lastAttackPosition))
		{
			play_up=false;
		}
	}
	if (!play_up)
	{
		lastAttackPosition++;
		if (lastAttackPosition >= 6)
		{
			play_up=true;
				lastAttackPosition++;
				int cycles=0;
			while(Board->columnFull(lastAttackPosition))
			{
				cycles++;
				lastAttackPosition++;
				if (lastAttackPosition > 6) lastAttackPosition=0;
				if (cycles >= 7) return 3;
			}
		}
	}
	return lastAttackPosition;
}

int ai::defend()
{
if (lastPlayerMoves[0] ==lastPlayerMoves[1])
	{
			return lastPlayerMoves[0];
	}
	//doing a sideways or diagonal pattern
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]+1)
	{
			return lastPlayerMoves[0]+1;
	}
	//doing the other sideways/diagonal
	else if (lastPlayerMoves[0]==lastPlayerMoves[1]-1)
	{
			return lastPlayerMoves[0]-1;
	}

}
void ai::reset()
{
	turns=0;
	lastPlayerMoves[0]=0;
	lastPlayerMoves[1]=0;
	lastPlayerMoves[2]=0;
	lastPlayerMoves[3]=0;
	lastAttackPosition=random(7);
}
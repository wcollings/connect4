#include "row.hpp"
#include <iostream>

board::board()
{
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++j)
			matrix[i][j]=0;
	}
}

void board::print()
{
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++j)
		{
			std::cout <<matrix[i][j] <<' ';
		}
		std::cout <<'\n';
	}
}

bool board::checkVertical()
{
	int player_score=0, cpu_score=0;
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++i)
		{
			if (matrix[i][j] == 1)
			{
				player_score++;
				cpu_score=0;
			}
			else if (matrix[i][j] == 2)
			{
				player_score=0;
				cpu_score++;
			}
			if (player_score > 3)
				return true;
			if (cpu_score > 3)
				return true;
			cpu_score=player_score=0;
		}

	}
	return false;
}
/*
**TODO: optimize this. it's better, but not great
*/
bool board::checkHorizontal()
{
	int player_score=0, cpu_score=0;
	for (int i=0; i < Y; ++i)
	{
		for (int j=0; j < X; ++i)
		{
			if (matrix[i][j] == 1)
			{
				player_score++;
				cpu_score=0;
			}
			else if (matrix[i][j] == 2)
			{
				player_score=0;
				cpu_score++;
			}
			if (player_score > 3)
				return true;
			if (cpu_score > 3)
				return true;
		}

	cpu_score=player_score=0;
	}
	return false;
}

/*
**there's got to be a better way of doing this
*/
bool board::checkLeftDiag()
{
	int player_score=0, cpu_score=0;
	for (int i=0, j =0; i < X && j < Y; ++i,++j)
	{
		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]== 2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;
	}
	cpu_score=player_score=0;
	for (int i=0, j=1; i < X && j < Y; ++i,++j)
	{

		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]== 2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;

	}
	cpu_score=player_score=0;
	for (int i=1, j=0; i < X && j < Y; ++i,++j)
	{
		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]== 2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;
	}
	return false;
}

/*
**I mean seriously
*/
bool board::checkRightDiag()
{
	int player_score=0, cpu_score=0;
	for (int i=0, j=Y-1; i < X && Y > 0; ++i, --j)
	{
		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]==2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;
	}
	player_score=cpu_score=0;
	for (int i=1, j=Y-1; i < X && j > 0; ++i,--j)
	{
		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]==2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;
	}
	player_score=cpu_score=0;
	for (int i=1, j =Y-1; i < X && j > 0; ++i,--j)
	{

		if (matrix[i][j]==1)
		{
			player_score++;
			cpu_score=0;
		}
		else if (matrix[i][j]==2)
		{
			player_score=0;
			cpu_score++;
		}
		if (player_score > SCORE) return true;
		if (cpu_score > SCORE) return true;
	}
	return false;
}
/*
**gets the top token of a given column
*/
int board::lastToken(int col)
{
	int i=0;
	while (matrix[col][++i] == 0 );
	return matrix[col][i];
}

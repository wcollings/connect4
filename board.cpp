#include "board.hpp"
#include <iostream>

board::board()
{
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++j)
			matrix[i][j]=0;
	}
}

void board::setToken(int col, int select)
{
	int i=0;
	for (; i < Y && matrix[col][i]==0; i++);
	//std::cout <<"point is ("<<col <<',' <<i-1 <<")\n";
	matrix[col][i-1]=select;
}

void board::print()
{
	for (int i=0; i < Y; ++i)
	{
		for (int j=0; j < X; ++j)
		{
			#if verbose==1
			std::cout <<'(' <<j <<',' <<i <<',' <<matrix[j][i] <<')' <<' ';
			#else
			std::cout <<matrix[j][i] <<' ';
			#endif
		}
		std::cout <<'\n';
	}
	std::cout <<"\n\n";
}

int board::checkVertical()
{
	int player_score=0, cpu_score=0;
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++j)
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
			if (player_score >= SCORE)
				return 1;
			if (cpu_score >= SCORE)
				return 2;
		}
		cpu_score=player_score=0;
	}
	return 0;
}

int board::checkHorizontal()
{
	int player_score=0, cpu_score=0;
	for (int j=0; j < Y; ++j)
	{
		for (int i=0; i < X; ++i)
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
			if (player_score >= SCORE)
				return 1;
			if (cpu_score >= SCORE)
				return 2;
		}
	cpu_score=cpu_score;
	cpu_score=player_score=0;
	}
	return 0;
}


int board::checkLeftDiag()
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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;
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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;

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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;
	}
	return 0;
}


int board::checkRightDiag()
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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;
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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;
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
		if (player_score >= SCORE) return 1;
		if (cpu_score >= SCORE) return 2;
	}
	return 0;
}
/*
**gets the top token of a given column
*/

int board::checkBoard()
{
	int win;
	win=checkRightDiag();
	if (win !=0)
		return win;
	win=checkLeftDiag();
	if (win !=0)
		return win;
	win=checkHorizontal();
	if (win !=0)
		return win;
	win=checkVertical();
	if (win !=0)
		return win;
	return 0;
}

int board::lastToken(int col)
{
	int i=0;
	while (matrix[col][++i] == 0 && i < Y);
	return matrix[col][i];
}

bool board::columnFull(int col)
{
	return !(matrix[col][0] != 0);
}
#include "board.hpp"

board::board()
{
	for (int i=0; i < X; ++i)
	{
		for (int j=0; j < Y; ++j)
			matrix[i][j]=0;
		update(i);
	}
}

void board::setToken(int col, int select)
{
	int i=0;
	for (; i < Y && matrix[col][i]==0; i++);
	matrix[col][i-1]=select;
	update(col);
}

void board::update(int col)
{
	for (uint16_t i=0; i < LED_COUNT; ++i)
	{
		colors[i]=EMPTY;
		if (matrix[col][i/3]==1)
			colors[i]=PLAYER;
		else if (matrix[col][i/3]==2)
			colors[i]=CPU;
	}
	switch (col)
	{
		case 0:y0.write(colors, LED_COUNT);
			break;
		case 1:y1.write(colors, LED_COUNT);
			break;
		case 2:y2.write(colors, LED_COUNT);
			break;
		case 3:y3.write(colors, LED_COUNT);
			break;
		case 4:y4.write(colors, LED_COUNT);
			break;
		case 5:y5.write(colors, LED_COUNT);
			break;
		case 6:y6.write(colors, LED_COUNT);
			break;
	}

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
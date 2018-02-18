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
	if (columnFull(col))
	return;
	for (; i < Y && matrix[col][i]==0; ++i);
	matrix[col][i-1]=select;
	update(col);
}

void board::update(int col)
{
	for (uint16_t i=0; i< LED_COUNT; i++)
	{
		colors[i]=EMPTY;
		if (matrix[col][i]==1)
			colors[i]=CPU;
		else if (matrix[col][i]==2)
			colors[i]=PLAYER;
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
		else if (matrix[i][j]==0)
		{
			player_score=0;
			cpu_score=0;
		}
			if (player_score >= SCORE)
			{
				flash_win(i,j,1, false);
				return 1;
			}
			if (cpu_score >= SCORE)
			{
				flash_win(i,j,1,true);
				return 2;
			}
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
		else if (matrix[i][j]==0)
		{
			player_score=0;
			cpu_score=0;
		}
			if (player_score >= SCORE)
				{
					flash_win(i,j,2,false);
					return 1;
				}
			if (cpu_score >= SCORE)
				{
					flash_win(i,j,2, true);
					return 2;
				}
		}
	cpu_score=cpu_score;
	cpu_score=player_score=0;
	}
	return 0;
}

int board::checkLeftDiag()
{
	int player_score=0, cpu_score=0;
	int i,j;
	for (int it=0; it < 6; ++it)
	{
		i=0;
		j=2-it;
		if (j <0)
		{
			j=0;
			i=it-2;
		}
		for (;j <=Y && i <=X; ++i,++j )
		{
			if (matrix[i][j] ==1)
			{
				player_score++;
				cpu_score=0;
			}
			else if (matrix[i][j] == 2)
			{
				player_score=0;
				cpu_score++;
			}
			else
			{
				player_score=0;
				cpu_score=0;
			}
			if (player_score >= SCORE)
			{
				flash_win(i,j,3,false);
				return 1;
			}
			if (cpu_score >= SCORE)
			{
				flash_win(i,j,3,true);
				return 2;
			}
		}
	}
	return 0;
}

int board::checkRightDiag()
{
	int i,j; 
	int player_score=0, cpu_score=0;
	for(int it=0; it < 7; ++it)
	{
		i=it+2;
		j=0;
		if ( i >=X)
		{
			j=i-6;
			i=6;
		}
		while (j <6 && i > -1)
		{
			if (matrix[i][j] == 1)
			{
				player_score++;
				cpu_score=0;
			}
			else if (matrix[i][j] ==2)
			{
				player_score=0;
				cpu_score++;
			}
			else
			{
				player_score=cpu_score=0;
			}
			if (player_score >= SCORE)
			{
				flash_win(i,j,4,false);
				return 1;
			}
			if (cpu_score >= SCORE)
			{
				flash_win(i,j,4,true);
				return 2;
			}
			j++;
			i--;
		}
		player_score=cpu_score=0;
	}
	return 0;
}
int board::checkBoard()
{
	int win;
	win=checkRightDiag();
	if (win !=0)
	{
		//Serial.println("right diag sucess");
		return win;
	}
	win=checkLeftDiag();
	if (win !=0)
	{
		//Serial.println("left diag sucess");
		return win;
	}

	win=checkHorizontal();
	if (win !=0)
	{
		Serial.println("horizontal sucess");
		return win;
	}
	win=checkVertical();
	if (win !=0)
	{
		Serial.println("vertical sucess");
		return win;
	}
	win=0;
	for (int i=0; i < 7; ++i)
	{
		if (columnFull(i))
			win++;
	}
	if (win ==7)
		return 3;
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
	return (matrix[col][0] != 0);
}

void board::flash_win(int x, int y, short strat, bool cpu_won)
{
	int affected_pins[4][2];
	switch (strat)
	{
		case 1:
		{
			affected_pins[0][0]=x;
			affected_pins[0][1]=y;
			affected_pins[1][0]=x;
			affected_pins[1][1]=y-1;
			affected_pins[2][0]=x;
			affected_pins[2][1]=y-2;
			affected_pins[3][0]=x;
			affected_pins[3][1]=y-3;
		}
			break;
		case 2:
		{
			affected_pins[0][0]=x;
			affected_pins[0][1]=y;
			affected_pins[1][0]=x-1;
			affected_pins[1][1]=y;
			affected_pins[2][0]=x-2;
			affected_pins[2][1]=y;
			affected_pins[3][0]=x-3;
			affected_pins[3][1]=y;
		}
			break;
		case 3:
		{
			affected_pins[0][0]=x;
			affected_pins[0][1]=y;
			affected_pins[1][0]=x-1;
			affected_pins[1][1]=y-1;
			affected_pins[2][0]=x-2;
			affected_pins[2][1]=y-2;
			affected_pins[3][0]=x-3;
			affected_pins[3][1]=y-3;
		}
		break;
		case 4:
		{
			affected_pins[0][0]=x;
			affected_pins[0][1]=y;
			affected_pins[1][0]=x+1;
			affected_pins[1][1]=y-1;
			affected_pins[2][0]=x+2;
			affected_pins[2][1]=y-2;
			affected_pins[3][0]=x+3;
			affected_pins[3][1]=y-3;
		}
	}
	for(int i=0; i < 3; ++i)
	{
	for (int i=0; i < 4; ++i)
	{
		matrix[affected_pins[i][0]][affected_pins[i][1]]=0;
	}
		for (int i=0; i< 7; ++i)
			update(i);
		delay(200);
		for (int i=0; i < 4; ++i)
			matrix[affected_pins[i][0]][affected_pins[i][1]]=cpu_won +1;
		for (int i=0; i < 7; ++i)
			update(i);
		delay(200);
	}
}
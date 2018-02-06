#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


#define SCORE 4

struct row
{
	unsigned int r1: 2;
	unsigned int r2: 2;
	unsigned int r3: 2;
	unsigned int r4: 2;
	unsigned int r5: 2;
	unsigned int r6: 2;
	unsigned int player: 3;
	unsigned int cpu:3;
} board[7];

void setToken(int col, int select);
bool checkVertical();
bool checkHorizontal();
bool checkLeftDiag();
bool checkRightDiag();
bool checkBoard();
void print()
{
	printf("\n\n%d %d %d %d %d %d %d\n", board[0].r1, board[1].r1, board[2].r1, board[3].r1, board[4].r1, board[5].r1, board[6].r1, board[7].r1);
	printf("%d %d %d %d %d %d %d\n", board[0].r2, board[1].r2, board[2].r2, board[3].r2, board[4].r2, board[5].r2, board[6].r2, board[7].r2);
	printf("%d %d %d %d %d %d %d\n", board[0].r3, board[1].r3, board[2].r3, board[3].r3, board[4].r3, board[5].r3, board[6].r3, board[7].r3);
	printf("%d %d %d %d %d %d %d\n", board[0].r4, board[1].r4, board[2].r4, board[3].r4, board[4].r4, board[5].r4, board[6].r4, board[7].r4);
	printf("%d %d %d %d %d %d %d\n", board[0].r5, board[1].r5, board[2].r5, board[3].r5, board[4].r5, board[5].r5, board[6].r5, board[7].r5);
	printf("%d %d %d %d %d %d %d\n", board[0].r6, board[1].r6, board[2].r6, board[3].r6, board[4].r6, board[5].r6, board[6].r6, board[7].r6);

}

int main(void)
{
	srand(time(NULL));
	int r=0, random=0;
	for (int i=0; i < 7; ++i)
	{
		board[i].r1=0;
		board[i].r2=0;
		board[i].r3=0;
		board[i].r4=0;
		board[i].r5=0;
		board[i].r6=0;
		board[i].player=0;
		board[i].cpu=0;
	}
	while (!checkBoard())
	{
		random=rand()%6;
		printf("give me a row number: ");
		scanf("%d", &r);
		setToken(r, 1);
		print();
		checkBoard();
		setToken(random, 2);
		print();
		checkBoard();
	}
}

bool checkVertical()
{
	for (int i=0; i < 7; ++i)
	{
		if (board[i].player >= SCORE || board[i].cpu >= SCORE)
			return true;
	}
	return false;
}

bool checkHorizontal()
{
	int player=0, cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r1 == 1) player++;
		else if (board[j].r1 == 2) cpu++;
		if (player >= SCORE || cpu >= SCORE) return true;
	}


	player=cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r2 == 1) player++;
		else if (board[j].r2 == 2) cpu++;
		if (player >4 || cpu > 4) return true;
	}


	player=cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r3 == 1) player++;
		else if (board[j].r3 == 2) cpu++;
		if (player >4 || cpu > 4) return true;
	}


	player=cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r4 == 1) player++;
		else if (board[j].r4 == 2) cpu++;
		if (player >4 || cpu > 4) return true;
	}


	player=cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r5 == 1) player++;
		else if (board[j].r5 == 2) cpu++;
		if (player >4 || cpu > 4) return true;
	}


	player=cpu=0;
	for (int j=0; j < 7; ++j)
	{
		if (board[j].r6 == 1) player++;
		else if (board[j].r6 == 2) cpu++;
		if (player >4 || cpu > 4) return true;
	}

	return false;
}

bool checkLeftDiag()
{
	int player=0, cpu=0;
	for (int i=0; i < 3;++i)
	{
		if (board[i].r6==1) player++;
		else if (board[i].r6==2) cpu++;
		if (board[i+1].r5==1) player++;
		else if (board[i+1].r5==2) cpu++;
		if (board[i+2].r4==1) player++;
		else if (board[i+2].r4==2) cpu++;
		if (board[i+3].r3==1) player++;
		else if (board[i+3].r3==2) cpu++;
		if (board[i+4].r2==1) player++;
		else if (board[i+4].r2==2) cpu++;
		if (board[i+5].r1==1) player++;
		else if (board[i+5].r1==2) cpu++;

		if (player >= SCORE|| cpu >= SCORE ) return true;

		player=cpu=0;
	}
	if (board[0].r5==1) player++;
	else if (board[0].r5==2) cpu++;


	if (board[1].r4==1) player++;
	else if (board[1].r4==2) cpu++;


	if (board[2].r3==1) player++;
	else if (board[2].r3==2) cpu++;


	if (board[2].r2==1) player++;
	else if (board[2].r2==2) cpu++;


	if (board[3].r1==1) player++;
	else if (board[3].r1==2) cpu++;

	if (player >= SCORE|| cpu >= SCORE) return true;

	return false;
}

bool checkRightDiag()
{
	int player=0, cpu=0;
	for (int i=6; i > 5;--i)
	{
		if (board[i].r6==1) player++;
		else if (board[i].r6==2) cpu++;
		if (board[i-1].r5==1) player++;
		else if (board[i-1].r5==2) cpu++;
		if (board[i-2].r4==1) player++;
		else if (board[i-2].r4==2) cpu++;
		if (board[i-3].r3==1) player++;
		else if (board[i-3].r3==2) cpu++;
		if (board[i-4].r2==1) player++;
		else if (board[i-4].r2==2) cpu++;
		if (board[i-5].r1==1) player++;
		else if (board[i-5].r1==2) cpu++;

		if (player >= SCORE || cpu >= SCORE ) return true;

		player=cpu=0;
	}
	if (board[6].r5==1) player++;
	else if (board[6].r5==2) cpu++;


	if (board[5].r4==1) player++;
	else if (board[5].r4==2) cpu++;


	if (board[4].r3==1) player++;
	else if (board[4].r3==2) cpu++;


	if (board[3].r2==1) player++;
	else if (board[3].r2==2) cpu++;


	if (board[2].r1==1) player++;
	else if (board[2].r1==2) cpu++;

	if (player >= SCORE || cpu >= SCORE ) return true;

	return false;
}

bool checkBoard()
{
	bool good=false;
	if (checkVertical() || good) good=true;
	if (checkHorizontal() || good) good=true;
	if (checkLeftDiag() || good) good=true;
	if (checkRightDiag() || good) good=true;
	return good;
}

void setToken(int col, int select)
{
	if (board[col].r1 != 0)
	{
		printf("That line is full\n");
		return;
	}
	else if (board[col].r6==0) board[col].r6=select;
	else if (board[col].r5==0) board[col].r5=select;
	else if (board[col].r4==0) board[col].r4=select;
	else if (board[col].r3==0) board[col].r3=select;
	else if (board[col].r2==0) board[col].r2=select;
	else if (board[col].r1==0) board[col].r1=select;

	if (select == 1) board[col].player++;
	else board[col].cpu++;

	return;
}

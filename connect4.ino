
#include "ai.hpp"


int buttonPins[7]={0,1,2,3,4,5,6};
int change=10;
board * Board;
ai * machine;
void setup()
{
	Board=new board();
	machine = new ai(Board);
	//pinMode(2, OUTPUT);
	for (int i=0; i < 7;++i)
		pinMode(buttonPins[i], INPUT);
	pinMode(13, OUTPUT);
}

void loop()
{
	digitalWrite(13, HIGH);
	int button_pressed;
	for (int i=0; i < X; ++i)
	{
		if (digitalRead(buttonPins[i]) == HIGH)
			{
				digitalWrite(13, LOW);
	   			Board->setToken(i, 1);
				//proceed(i);
				if (Board->checkBoard()!=0)
					return;
			}
	}
}

void proceed(int pressed)
{
	machine->logPlayerMove(pressed);
	Board->setToken(pressed, 1);
	if (Board->checkBoard() !=0)
		return;
	delay(3000);
	Board->setToken(machine->place(), 2);
	if (Board->checkBoard() !=0)
		return;
	return;
}
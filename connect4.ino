
#include "ai.hpp"


int buttonPins[7];
board * Board;
ai * machine;
void setup()
{
	Board=new board();
	machine = new ai(Board);
	for (int i=0; i < 7;++i)
		pinMode(buttonPins[i], INPUT);
}

void loop()
{
	int button_pressed;
	for (int i=0; i < 7; ++i)
	{
		if (digitalRead(buttonPins[i]) == HIGH)
		{
			button_pressed=i;
			break;
		}
	}
		machine->logPlayerMove(button_pressed);
		Board->setToken(button_pressed, 1);
		if (Board->checkBoard() !=0)
			return;
		Board->setToken(machine->place(), 2);
		if (Board->checkBoard() !=0)
			return;

}

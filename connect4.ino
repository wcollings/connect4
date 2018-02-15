
#include "ai.hpp"


int buttonPins[7]={2,4,7,8,12};
board * Board;
ai * machine;
void setup()
{
	Board=new board();
	machine = new ai(Board);
  pinMode(13, OUTPUT);
	for (int i=0; i < 7;++i)
		pinMode(buttonPins[i], INPUT_PULLUP);
}

void loop()
{
	int button_pressed;
	for (int i=0; i < 7; ++i)
	{
		if (digitalRead(buttonPins[i]) == LOW)
		{
			digitalWrite(13, HIGH);
     
 delay(1000);
    digitalWrite(13, LOW);
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

#include "ai.hpp"

int buttonPins[7]={0,1,2,3,4,5,6};
int change=10;
board * Board;
ai * machine;
void proceed(int pressed);
#define AIDISABLED 0
void setup()
{
	rgb_color row[6];
	Board=new board();
	machine = new ai(Board);
	for(int i=0; i < 6;++i)
	{
		row[i]=rgb_color(0,0,0);
	}
	y6.write(row, 6);
	//pinMode(2, OUTPUT);
	for (int i=0; i < 7;++i)
		pinMode(buttonPins[i], INPUT_PULLUP);
	Serial.begin(9600);
}

void loop()
{
	//digitalWrite(13, HIGH);
	int button_pressed;
	for (int i=0; i < X; ++i)
	{
		if (digitalRead(buttonPins[i]) == LOW)
			{
				//Serial.print("button ");
				//Serial.print(i);
				//Serial.println(" pressed");
	   			Board->setToken(i, 1);
				if (Board->checkBoard()!= 0)
				{
					victory();
					continue;
				}
				delay(1000);
				machine->logPlayerMove(i);
				Board->setToken(machine->place(), 2);
				delay(1000);
				if (Board->checkBoard()!=0)
					victory();
			}
	}
}

void proceed(int pressed)
{
	#if AIDISABLED
			delay(1000);
		while (1){
	for (int i=0; i < 7; ++i)
		if (digitalRead(buttonPins[i]) == LOW)
		{
			Board->setToken(i, 2);
			return;
		}
		}
		#else
	delay(1000);
	machine->logPlayerMove(pressed);
//	Board->setToken(pressed, 1);
	Board->setToken(machine->place(), 2);
	delay(100);
	#endif
	return;
}

void victory()
{
	bool pressed=false;
	int selector=0;
	if (Board->checkBoard()==3)
	{
		rgb_color colors[6], possible_colors[3];
		possible_colors[0]=rgb_color(0x50, 0, 0);
		possible_colors[1]=rgb_color(0, 0x50, 0);
		possible_colors[2]=rgb_color(0, 0, 0x50);
		for (int i=0; i < 10; ++i)
		{
			for (uint16_t i=0; i < LED_COUNT; ++i)
			{
				colors[i]=possible_colors[(selector++)%3];
			}
			y0.write(colors, LED_COUNT);
			y1.write(colors, LED_COUNT);
			y2.write(colors, LED_COUNT);
			y3.write(colors, LED_COUNT);
			y4.write(colors, LED_COUNT);
			y5.write(colors, LED_COUNT);
			y6.write(colors, LED_COUNT);
		}
	}
	machine->reset();
	delay(200);
	while (!pressed)
	{
		for (int i=0; i < 7; ++i)
		{
			if (digitalRead(buttonPins[i])==LOW)
			{
				pressed=true;
				Board = new board();
				delay(500);
			}
		}
	}
}
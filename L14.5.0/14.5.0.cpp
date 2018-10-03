#include <Windows.h>
#include <iostream>
#include <time.h>
#include "sect.h"
#include "ringlist.h"
using namespace std;

void show_list();

void main()
{
	_fullscreen();

while(100)
	{
		show_list();
	}
	
	cin.get();
}

void show_list()
{
	ringlist rl1;
	COORD window = outputsize();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		rl1.add({ window.X / 2, window.Y / 2 }, 30 * i, PS_SOLID, 5, RGB(rand() % 256, rand() % 256, rand() % 256));
	}
	rl1.display();
}
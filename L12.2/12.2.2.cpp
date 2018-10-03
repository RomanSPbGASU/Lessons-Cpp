#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "rect.h"
#include <ctime>
using namespace std;

int main()
{
	//открываем окно вывода на весь экран
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
		GetLargestConsoleWindowSize(hStdout).Y - 1 }; //poluchit' maximal'no vozmozhniy razmer okna konsoli
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	const int xsize = 42;
	const int ysize = 14;
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	int cellsizex = (cr.right) / xsize;
	int cellsizey = (cr.bottom) / ysize;
	int x, y, x2, y2, points = 0, a, b, a2, b2, flag = 0;
	color Square[ysize][xsize];
	//zapolnili matricu
	for (y = 0; y < ysize; y++)
	{
		for (x = 0; x < xsize; x++)
		{
			Square[y][x] = { -1, -1, -1 };
		}
	}

	srand(time(NULL));
	while (points < (xsize*ysize))
	{
		y = rand() % ysize;
		x = rand() % xsize;
		y2 = rand() % ysize;
		x2 = rand() % xsize;
		flag = 0;
		a = (y > y2) ? y2 : y;
		b = (y > y2) ? y : y2;
		a2 = (x > x2) ? x2 : x;
		b2 = (x > x2) ? x : x2;
		for (int i = a; i <= b; i++)
		{
			for (int j = a2; j <= b2; j++)
			{
				if (Square[i][j].blue != -1)
				{
						flag = 1;
						break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0)
		{
			color rectColor = { rand() % 206 + 50, rand() % 206 + 50, rand() % 206 + 50 };
			for (int i = a; i <= b; i++)
			{
				for (int j = a2; j <= b2; j++)
				{
					Square[i][j] = rectColor;
					points++;
				}
			}
		}
	}
	for (y = 0; y < ysize; y++)
	{
		for (x = 0; x < xsize; x++)
		{
			rect* r;
			r = new rect;
			r->set_rect(x*cellsizex, (y + 1)*cellsizey, (x + 1)*cellsizex, y * cellsizey,
				Square[y][x].red, Square[y][x].green, Square[y][x].blue);
			r->draw_rect();
		}
	}
	_getche();
}
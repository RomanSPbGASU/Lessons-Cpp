#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include "circle.h"

using namespace std;

void main()
{
	//открываем окно вывода на весь экран
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
		GetLargestConsoleWindowSize(hStdout).Y - 1 }; //poluchit' maximal'no vozmozhniy razmer okna konsoli
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3);

	//рисуем мишень
	COLORREF color[] = { RGB(255,255,255), RGB(0,0,0) };
	short maxtargetradius = 686*4/10;
	COORD targetcenter = { 1365 / 2, 686 / 2 };
	circle c1(targetcenter, maxtargetradius, color[0]);
	c1.draw_circle();
	for (float r = maxtargetradius;
		r > float(3)/9 *  maxtargetradius; r -= float(1) / 9 * maxtargetradius)
	{
		c1.set_circle(targetcenter, r, color[1]);
		c1.draw_circle();
		c1.set_circle(targetcenter, r - 2, color[0]);
		c1.draw_circle();
	}
	for (float r = float(3) / 9 * maxtargetradius;
		r >= 0; r -= float(1) / 9 * maxtargetradius)
	{
		c1.set_circle(targetcenter, r + 2, color[0]);
		c1.draw_circle();
		c1.set_circle(targetcenter, r, color[1]);
		c1.draw_circle();
	}
	 //пишем цифры
	for (int i = 0; i < 6; i++)
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_RED + BACKGROUND_BLUE + BACKGROUND_GREEN + BACKGROUND_INTENSITY);
		SetConsoleCursorPosition(hStdout, 
			PixToSymb({ targetcenter.X, targetcenter.Y - static_cast<short>(maxtargetradius * (17-2*i) / 18 )}));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X, targetcenter.Y + static_cast<short>(maxtargetradius * (17 - 2 * i) / 18) }));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X - static_cast<short>(maxtargetradius * (17 - 2 * i) / 18), targetcenter.Y }));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X + static_cast<short>(maxtargetradius * (17 - 2 * i) / 18), targetcenter.Y }));
		cout << i + 1;
	}
	for (int i = 6; i < 9; i++)
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X, targetcenter.Y - static_cast<short>(maxtargetradius * (17 - 2 * i) / 18) }));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X, targetcenter.Y + static_cast<short>(maxtargetradius * (17 - 2 * i) / 18) }));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X - static_cast<short>(maxtargetradius * (17 - 2 * i) / 18), targetcenter.Y }));
		cout << i + 1;
		SetConsoleCursorPosition(hStdout,
			PixToSymb({ targetcenter.X + static_cast<short>(maxtargetradius * (17 - 2 * i) / 18), targetcenter.Y }));
		cout << i + 1;
	}

	_getche();
}

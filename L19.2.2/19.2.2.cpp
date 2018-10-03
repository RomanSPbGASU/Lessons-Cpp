#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "rect.h"

using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
						GetLargestConsoleWindowSize(hStdout).Y - 1 };	// получить максимально возможный размер окна консоли
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3);

	rect r1;
	for (int i=0; i<=10; i++)
	{
		Increase(&r1, { rand() % 256, rand() % 256, rand() % 256 });
	Sleep(100);
	}
	for (int i = 0; i <= 10; i++)
	{
		Decrease(&r1, { rand() % 256, rand() % 256, rand() % 256 });
		Sleep(100);
	}
	_getche();
}
#include "shape.h"

shape::shape() : point({ 680, 350 }), color_type(RGB( 255, 0, 0 ))
{}
shape::shape(COORD basepoint, COLORREF color) : point(basepoint), color_type(color)
{}

int _fullscreen()//открываем окно вывода на весь экран
{
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
	GetLargestConsoleWindowSize(hStdout).Y - 1 }; //poluchit' maximal'no vozmozhniy razmer okna konsoli
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3);
	return 0;
}
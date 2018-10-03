// classes.cpp: определяет точку входа для консольного приложения.
#include <conio.h> //
//#include "stdafx.h"
// подключаем класс line
#include "line.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
		GetLargestConsoleWindowSize(hStdout).Y - 1 };
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

	COORD vertices[] = { { 400,100 },{ 300,300 },{ 400, 400 },{ 500,300 },{ 400,100 },{ 400,400 } };
	line l2(vertices[1], vertices[3], RGB(255, 100, 100), PS_DASH, 1); //как изменить фон пунктира?
	l2.draw_line();
	for (int i = 0; i < 5; i++)
	{
		line l1(vertices[i], vertices[i + 1], RGB(255, 100, 100), PS_SOLID, 1);  //КАК ПОЛЬЗОВАТЕЛЮ КЛАССА ПОЛУЧИТЬ КОНСТАНТЫ ДЛЯ ТИПА ЛИНИИ?
		l1.draw_line();
	}
	_getche();
}
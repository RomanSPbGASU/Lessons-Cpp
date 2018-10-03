#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void main()
{
	//открываем окно вывода на весь экран
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	//делаем перо невидимым
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(hStdout, &curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curs);
	//подготовка к рисованию
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	COLORREF color[] = { RGB(255, 0, 0), RGB(0, 0, 0), RGB(255,255,255) };
	//закрашиваем кубик
	hPen = CreatePen(PS_SOLID, 1, color[0]);
	SelectObject(hDeviceContext, hPen);
	COORD point[] = { { 300, 100 }, { 900, 100 }, { 100, 200 }, { 700, 200 },
	{ 300, 400 }, { 900, 400 }, { 100, 500 }, { 700, 500 } };
	int high = point[4].Y - point[0].Y;
	for (int j = 0; j < high; j++)
	{
		MoveToEx(hDeviceContext, point[0].X, point[0].Y + j, NULL);
		LineTo(hDeviceContext, point[1].X, point[1].Y + j);
		MoveToEx(hDeviceContext, point[2].X, point[2].Y + j, NULL);
		LineTo(hDeviceContext, point[3].X, point[3].Y + j);
	}
	int width_top = point[1].X - point[0].X;
	for (int j = 0; j < width_top; j++)
	{
		MoveToEx(hDeviceContext, point[2].X + j, point[2].Y, NULL);
		LineTo(hDeviceContext, point[0].X + j, point[0].Y);
	}
	int high_right = point[7].Y - point[3].Y;
	for (int j = 0; j < high_right; j++)
	{
		MoveToEx(hDeviceContext, point[3].X, point[3].Y + j, NULL);
		LineTo(hDeviceContext, point[1].X, point[1].Y + j);
	}
	//рисуем невидимые (пунктирные) контуры
	hPen = CreatePen(PS_DASH, 1, color[2]);
	SelectObject(hDeviceContext, hPen);
	int inv_lines[3][2] = { { 4, 0 }, { 6, 4 }, { 4, 5 } }; //вспомогательный массив для невидимого контура
	for (int j = 0; j < 3; j++)
	{
		MoveToEx(hDeviceContext, point[inv_lines[j][0]].X, point[inv_lines[j][0]].Y, NULL);
		LineTo(hDeviceContext, point[inv_lines[j][1]].X, point[inv_lines[j][1]].Y);
	}
	//рисуем видимые контуры
	hPen = CreatePen(PS_SOLID, 0.9, color[1]);
	SelectObject(hDeviceContext, hPen);
	int lines[9][2] = { { 2, 0 }, { 3, 1 }, { 0, 1 }, { 2, 3 }, 
	{ 2, 6 }, { 6, 7 }, { 7, 5 }, { 5, 1 }, { 3, 7 } }; //вспомогательный массив для видимого контура
	for (int j = 0; j < 9; j++)
	{
		MoveToEx(hDeviceContext, point[lines[j][0]].X, point[lines[j][0]].Y, NULL);
		LineTo(hDeviceContext, point[lines[j][1]].X, point[lines[j][1]].Y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	_getche();
}
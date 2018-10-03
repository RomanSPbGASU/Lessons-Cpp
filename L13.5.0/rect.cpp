#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <ctime>
#include "rect.h"

using namespace std;

rect::rect() : left_bottom(), right_top(), color_type()
{
	/*HWND hWnd = GetForegroundWindow();
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD max = GetLargestConsoleWindowSize(hStdout); //poluchit' maximal'no vozmozhniy razmer okna konsoli
	max = SymbToPix(max);
	left_bottom = { 0, max.Y};
	right_top = { max.X, 0 };
	color_type = { 255, 200, 220 };*/
}
rect::rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
	byte ColorTypeR, byte ColorTypeG, byte ColorTypeB)
{
	left_bottom.X = LeftBottomX;
	left_bottom.Y = LeftBottomY;
	right_top.X = RightTopX;
	right_top.Y = RightTopY;
	color_type = RGB( ColorTypeR, ColorTypeG, ColorTypeB );
}
rect::rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
	COLORREF ColorType)
{
	left_bottom.X = LeftBottomX;
	left_bottom.Y = LeftBottomY;
	right_top.X = RightTopX;
	right_top.Y = RightTopY;
	color_type = ColorType;
}
rect::~rect(){} // лень писать
void rect::set_rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
	byte ColorTypeR, byte ColorTypeG, byte ColorTypeB)
{
	left_bottom.X = LeftBottomX;
	left_bottom.Y = LeftBottomY;
	right_top.X = RightTopX;
	right_top.Y = RightTopY;
	color_type = RGB(ColorTypeR, ColorTypeG, ColorTypeB);
}
void rect::set_rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY, COLORREF ColorType)
{
	left_bottom.X = LeftBottomX;
	left_bottom.Y = LeftBottomY;
	right_top.X = RightTopX;
	right_top.Y = RightTopY;
	color_type = ColorType;
}
void rect::draw_rect()
{
	//подготовка к рисованию
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	//рисуем прямоугольник
	hPen = CreatePen(PS_SOLID, 2, color_type);
	SelectObject(hDeviceContext, hPen);
	for (int i = left_bottom.X; i <= right_top.X; i++)
	{
		MoveToEx(hDeviceContext, i, right_top.Y, NULL);
		LineTo(hDeviceContext, i, left_bottom.Y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}
/* fragment coda iz konstructora
//делаем перо невидимым
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
COLORREF color = RGB(color_type.red, color_type.green, color_type.blue);
//рисуем прямоугольник
hPen = CreatePen(PS_SOLID, 2, color);
SelectObject(hDeviceContext, hPen);
for (int i = 0; i <= right_top.X; i++)
{
MoveToEx(hDeviceContext, i, 0, NULL);
LineTo(hDeviceContext, i, left_bottom.Y);
}*/

/*
CONSOLE_SCREEN_BUFFER_INFO sbi;
GetConsoleScreenBufferInfo(hStdout, &sbi);
SMALL_RECT StdSize;
StdSize = sbi.srWindow; // poluchili koordinaty uglov rabochey oblasti okna
RECT cr;
GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
cout << cr.bottom <<" " << cr.right;
GetWindowRect(hWnd, &cr); //poluchenie razmerov okna standartnogo vyvoda
cout << "\n";
cout << cr.bottom << " " << cr.right;
MoveWindow(hWnd, 0, 0, 500, 400, 1); //izmenyaet razmery i polozhenie okna
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD max = GetLargestConsoleWindowSize(hStdout); //poluchit' maximal'no vozmozhniy razmer okna konsoli
cout << "\n" << max.X << " " << max.Y;
SMALL_RECT StdSize = { 0, 0, max.X, max.Y };
SetConsoleWindowInfo(hStdout, 1, &StdSize); //izmeniaet razmer i polozhenie okna (v simvolah)
*/
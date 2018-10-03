#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "rect.h"
#include <ctime>
using namespace std;

struct color
{
	int red;
	int green;
	int blue;
};

class rect
{
private:
	COORD left_bottom;
	COORD right_top;
	color color_type;
public:
	rect()
	{
		HWND hWnd = GetForegroundWindow();
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD max = GetLargestConsoleWindowSize(hStdout); //poluchit' maximal'no vozmozhniy razmer okna konsoli
		max = SymbToPix(max);
		left_bottom = { 0, max.Y};
		right_top = { max.X, 0 };
		color_type = { 255, 200, 220 };
	}
	void set_rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB)
	{
		left_bottom.X = LeftBottomX;
		left_bottom.Y = LeftBottomY;
		right_top.X = RightTopX;
		right_top.Y = RightTopY;
		color_type = { ColorTypeR, ColorTypeG, ColorTypeB };
	}
	void draw_rect()
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
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
		//рисуем пр€моугольник
		hPen = CreatePen(PS_SOLID, 2, color);
		SelectObject(hDeviceContext, hPen);
		for (int i = left_bottom.X; i <= right_top.X; i++)
		{
			MoveToEx(hDeviceContext, i, right_top.Y, NULL);
			LineTo(hDeviceContext, i, left_bottom.Y);
		}
		//удал€ем перо, освобождаем контекст
		DeleteObject(hPen);
		ReleaseDC(hWindow, hDeviceContext);
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	//открываем окно вывода на весь экран
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	const int xsize = 1345/16;
	const int ysize = 685/24;
	int x, y, x2, y2, points = 0, a, b, a2, b2, Square[ysize][xsize], flag = 0;
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	int cellsizex = (cr.right) / xsize;
	int cellsizey = (cr.bottom) / ysize;
	//zapolnili matricu nuliami
	for (y = 0; y < ysize; y++)
	{
		for (x = 0; x < xsize; x++)
		{
			Square[y][x] = 0;
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
				if (Square[i][j] != 0)
				{
						flag = 1;
						break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0)
		{
			for (int i = a; i <= b; i++)
			{
				for (int j = a2; j <= b2; j++)
				{
					Square[i][j] = 1;
					points++;
				}
			}
			rect* r;
			r = new rect;
			r->set_rect(a2*cellsizex, (b+1)*cellsizey, (b2+1)*cellsizex, a * cellsizey, 
				0, 0, rand()%206+50);
			r->draw_rect();
			Sleep(10000 / (points) ^ 3/2);
		}
	}
	_getche();
}
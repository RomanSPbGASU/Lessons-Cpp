#include <Windows.h>
//#include <conio.h>
//#define _USE_MATH_DEFINES
//#include <cmath>
#include "ring.h"

ring::ring() {}
ring::ring(COORD center, short radius, int linestyle, int linewidth, COLORREF color)
{
	ringcenter = center;
	ringradius = radius;
	ringlinestyle = linestyle;
	ringlinewidth = linewidth;
	ringcolor = color;

}
void ring::set_ring(COORD center, short radius, int linestyle, int linewidth, COLORREF color)
{
	ringcenter = center;
	ringradius = radius;
	ringlinestyle = linestyle;
	ringlinewidth = linewidth;
	ringcolor = color;
}
void ring::draw_ring()
{
	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);
	HPEN hPen = CreatePen(ringlinestyle, ringlinewidth, ringcolor);
	SelectObject(hDeviceContext, hPen);

	////мой вариант
	//MoveToEx(hDeviceContext, ringcenter.X + ringradius, ringcenter.Y, NULL);
	//for (double angle = 0; angle <= 2 * M_PI + 0.1; angle += M_PI / 20 ) // без 0,1 не дорисовывает одну прямую
	//{
	//	LineTo(hDeviceContext, ringcenter.X + ringradius * cos(angle), ringcenter.Y - ringradius * sin(angle) );
	//}

	// алгоритм Брезенхэма https://ru.wikipedia.org/wiki/Алгоритм_Брезенхэма
	int x = 0;
	int y = ringradius;
	int delta = 1 - 2 * ringradius;
	int error = 0;
	MoveToEx(hDeviceContext, ringcenter.X, ringcenter.Y + ringradius, NULL);
	while (y >= 0)
	{
		MoveToEx(hDeviceContext, ringcenter.X + x, ringcenter.Y + y, NULL); //Так будет очень медленно?
		LineTo(hDeviceContext, ringcenter.X + x, ringcenter.Y + y);
		MoveToEx(hDeviceContext, ringcenter.X + x, ringcenter.Y - y, NULL);
		LineTo(hDeviceContext, ringcenter.X + x, ringcenter.Y - y);
		MoveToEx(hDeviceContext, ringcenter.X - x, ringcenter.Y + y, NULL);
		LineTo(hDeviceContext, ringcenter.X - x, ringcenter.Y + y);
		MoveToEx(hDeviceContext, ringcenter.X - x, ringcenter.Y - y, NULL);
		LineTo(hDeviceContext, ringcenter.X - x, ringcenter.Y - y);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if ((delta > 0) && (error > 0))
		{
			delta += 1 - 2 * --y;
			continue;
		}
		x++;
		delta += 2 * (x - y);
		y--;
	}

	////так круги получаются заполненными белым
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_CURSOR_INFO curs;
	//GetConsoleCursorInfo(hStdout, &curs);
	//curs.bVisible = FALSE;
	//SetConsoleCursorInfo(hStdout, &curs);

	//DrawEllipse(hDeviceContext, ringcenter.X - ringradius, ringcenter.Y - ringradius, 
	//						ringcenter.X + ringradius, ringcenter.Y + ringradius);

	//// алгоритм Брезенхэма - вариант с SetPixel (не подходит, так как нельзя выбрать толщину)
	//int x = 0;
	//int y = ringradius;
	//int delta = 1 - 2 * ringradius;
	//int error = 0;
	//MoveToEx(hDeviceContext, ringcenter.X, ringcenter.Y + ringradius, NULL);
	//while (y >= 0)
	//{
	//	SetPixel(hDeviceContext, ringcenter.X + x, ringcenter.Y + y, ringcolor);
	//	SetPixel(hDeviceContext, ringcenter.X + x, ringcenter.Y - y, ringcolor);
	//	SetPixel(hDeviceContext, ringcenter.X - x, ringcenter.Y + y, ringcolor);
	//	SetPixel(hDeviceContext, ringcenter.X - x, ringcenter.Y - y, ringcolor);
	//	error = 2 * (delta + y) - 1;
	//	if ((delta < 0) && (error <= 0))
	//	{
	//		delta += 2 * ++x + 1;
	//		continue;
	//	}
	//	error = 2 * (delta - x) - 1;
	//	if ((delta > 0) && (error > 0))
	//	{
	//		delta += 1 - 2 * --y;
	//		continue;
	//	}
	//	x++;
	//	delta += 2 * (x - y);
	//	y--;
	//}

	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}
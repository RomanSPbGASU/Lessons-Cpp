// файл реализации класса line.cpp
// подключаем интерфейс класса к файлу его реализации
#include "line.h"

line::line() {}
line::line(COORD startpoint, COORD endpoint, COLORREF linecolor, int linestyle, int linewidth)
{
	lineends = { startpoint, endpoint };
	color = linecolor;
	penstyle = linestyle;
	width = linewidth;
}
void line::set_line(COORD startpoint, COORD endpoint, COLORREF linecolor, int linestyle, int linewidth)
{
	lineends = { startpoint, endpoint };
	color = linecolor;
	penstyle = linestyle;
	width = linewidth;
}
void line::draw_line()
{
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	//рисуем линию
	hPen = CreatePen(penstyle, width, color);
	SelectObject(hDeviceContext, hPen);
	MoveToEx(hDeviceContext, lineends.alpha.X, lineends.alpha.Y, NULL); //как работает последний аргумент?
	LineTo(hDeviceContext, lineends.omega.X, lineends.omega.Y);
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}
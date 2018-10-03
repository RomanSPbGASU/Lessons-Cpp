#include "circle.h"

circle::circle() : shape (), radius(686 * 0.4)
{}
circle::circle(COORD ce = { 1365 / 2, 686 / 2 },
	COLORREF co = ( 255, 0, 0 ), int ra = 686 * 0.4) : shape(ce, co), radius(ra)
{}
void circle::set(COORD circlecenter, COLORREF circlecolor, int rad)
{
	point = circlecenter;
	color_type = circlecolor;
	radius = rad;
}
void circle::draw()
{
	//подготовка к рисованию
	HPEN hPen;
	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);
	//рисуем круг
	hPen = CreatePen(PS_SOLID, 2, color_type);
	SelectObject(hDeviceContext, hPen);
	for (int y = point.Y - radius; y <= point.Y + radius; y++)
	{
		int undersqrt = static_cast<int>(sqrt(radius*radius - (y - point.Y)*(y - point.Y)));
		MoveToEx(hDeviceContext, point.X - undersqrt, y, NULL);
		LineTo(hDeviceContext, point.X + undersqrt, y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}

COORD SymbToPix(COORD Symb)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	return{ (2 * Symb.X * consolefont.dwFontSize.X + 1) / 2, (2 * Symb.Y * consolefont.dwFontSize.Y + 1) / 2 };
}
COORD PixToSymb(COORD Pix)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	short x = Pix.X / consolefont.dwFontSize.X;
	short y = Pix.Y / consolefont.dwFontSize.Y;
	return{ x, y };
}
short PixToSymbX(short x)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	x = x / consolefont.dwFontSize.X;
	return(x);
}
short PixToSymbY(short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	y = y / consolefont.dwFontSize.Y;
	return(y);
}
void PrintInCoord(COORD coordinates, char *text)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, coordinates);
	cout << text;
}

// алгоритм отсюда: https://ru.wikibooks.org/wiki/Реализации_алгоритмов/Алгоритм_Брезенхэма
//int x = 0;
//int y = radius;
//int delta = 1 - 2 * radius;
//int error = 0;
//while (y >= 0)
//{
//	SetPixel(hDeviceContext, center.X + x, center.Y + y, color);
//	SetPixel(hDeviceContext, center.X + x, center.Y - y, color);
//	SetPixel(hDeviceContext, center.X - x, center.Y + y, color);
//	SetPixel(hDeviceContext, center.X - x, center.Y - y, color);
//	error = 2 * (delta + y) - 1;
//	if (delta < 0 && error <= 0) {
//		++x;
//		delta += 2 * x + 1;
//		continue;
//	}
//	error = 2 * (delta - x) - 1;
//	if (delta > 0 && error > 0) {
//		--y;
//		delta += 1 - 2 * y;
//		continue;
//	}
//	++x;
//	delta += 2 * (x - y);
//	--y;
//}

///* Вспомогательная функция, печатает точки, определяющие окружность */
//void plot_circle(int x, int y, int x_center, int  y_center, int color_code)
//{
//	HWND hWindow = GetConsoleWindow();
//	HDC hDeviceContext = GetDC(hWindow);
//
//	SetPixel(hDeviceContext, x_center + x, y_center + y, color_code);
//	SetPixel(hDeviceContext, x_center + x, y_center - y, color_code);
//	SetPixel(hDeviceContext, x_center - x, y_center + y, color_code);
//	SetPixel(hDeviceContext, x_center - x, y_center - y, color_code);
//}
//
///* Вычерчивание окружности с использованием алгоритма Брезенхэма */
//void circle(int x_center, int y_center, int radius, int color_code)
//{
//	int x, y, delta;
//	x = 0;
//	y = radius;
//	delta = 3 - 2 * radius;
//	while (x<y) {
//		plot_circle(x, y, x_center, y_center, color_code);
//		plot_circle(y, x, x_center, y_center, color_code);
//		if (delta<0)
//			delta += 4 * x + 6;
//		else {
//			delta += 4 * (x - y) + 10;
//			y--;
//		}
//		x++;
//	}
//
//	if (x == y) plot_circle(x, y, x_center, y_center, color_code);
//}
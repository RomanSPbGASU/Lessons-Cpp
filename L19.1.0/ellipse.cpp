#include "ellipse.h"

ellipse::ellipse() : shape(), radius(786 * 0.4), secondradius(786 * 0.2)
{}
ellipse::ellipse(COORD circlecenter = { 300, 400 }, COLORREF circlecolor = RGB( 255, 0, 0 ), int rad = 200, int secrad = 100) :
	shape(circlecenter, circlecolor), radius(rad), secondradius(secrad)
{}
void ellipse::set(COORD circlecenter, int rad, int secrad, COLORREF circlecolor)
{
	point = circlecenter;
	radius = rad;
	secondradius = secrad;
	color_type = circlecolor;
}
void ellipse::draw()
{
	////подготовка к рисованию
	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);

	//рисуем эллипс:

	//1. функцией из <Windows.h>

	//HPEN hPen = CreatePen(PS_SOLID, 2, color);
	//SelectObject(hDeviceContext, hPen);
	//HBRUSH hBrush = CreateSolidBrush(color);
	//SelectObject(hDeviceContext, hBrush);
	//Ellipse(hDeviceContext, center.X - radius / 2, center.Y - secondradius / 2,
	//						center.X + radius / 2, center.Y + secondradius / 2);
	////удаляем перо
	//DeleteObject(hPen);
	//DeleteObject(hBrush);

	//2. по определению эллипса

	// обозначим фокусы эллипса
	COORD F1, F2;
	if (radius > secondradius)
	{
		F1 = { (short)sqrt(pow(radius, 2) - pow(secondradius, 2)), 0 };
		F2 = { -(short)sqrt(pow(radius, 2) - pow(secondradius, 2)), 0 };
	}
	else
	{
		F1 = { 0, -(short)sqrt(pow(secondradius, 2) - pow(radius, 2)) };
		F2 = { 0, (short)sqrt(pow(secondradius, 2) - pow(radius, 2)) };
	}
	int primeradius = (radius > secondradius ? radius : secondradius);
	// закрасим область удовлетворяющую условию: расстояние от любой точки до фокусов не должно превышать 2 * больший радиус
	for (int i = 0; i < radius; i++)
	{
		for (int j = 0; j > -secondradius; j--)
		{
			if (sqrt(pow(F1.X - i, 2) + pow(F1.Y - j, 2))
				+ sqrt(pow(F2.X - i, 2) + pow(F2.Y - j, 2))
				<= 2 * primeradius)
			{
				SetPixel(hDeviceContext, point.X + i, point.Y + j, color_type);
				SetPixel(hDeviceContext, point.X - i, point.Y + j, color_type);
				SetPixel(hDeviceContext, point.X + i, point.Y - j, color_type);
				SetPixel(hDeviceContext, point.X - i, point.Y - j, color_type);
			}
			else
			{
				continue;
			}
		}
	}

	// освобождаем контекст
	ReleaseDC(hWindow, hDeviceContext);
}


//#include <conio.h>
//#include <stdlib.h>
//
////############################ Вывод точки ##################################
//void putpixel(unsigned int X, unsigned int Y, unsigned char Color)
//{
//	asm{
//		mov ax,[Y]
//		mov dx, 320
//		imul dx
//		add ax,[X]
//		mov di, ax
//		push es
//		mov ax, 0xA000
//		mov es, ax
//		mov al,[Color]
//		stosb
//		pop es
//	}
//}
//
////################ Алгорит Брезенхема для рисования эллипса #################
//void ellipse(int x, int y, int a, int b, int color)
//{
//	int col, i, row, bnew;
//	long a_square, b_square, two_a_square, two_b_square, four_a_square, four_b_square, d;
//
//	b_square = b*b;
//	a_square = a*a;
//	row = b;
//	col = 0;
//	two_a_square = a_square << 1;
//	four_a_square = a_square << 2;
//	four_b_square = b_square << 2;
//	two_b_square = b_square << 1;
//	d = two_a_square*((row - 1)*(row)) + a_square + two_b_square*(1 - a_square);
//	while (a_square*(row)>b_square*(col))
//	{
//		putpixel(col + x, row + y, color);
//		putpixel(col + x, y - row, color);
//		putpixel(x - col, row + y, color);
//		putpixel(x - col, y - row, color);
//		if (d >= 0)
//		{
//			row--;
//			d -= four_a_square*(row);
//		}
//		d += two_b_square*(3 + (col << 1));
//		col++;
//	}
//	d = two_b_square*(col + 1)*col + two_a_square*(row*(row - 2) + 1) + (1 - two_a_square)*b_square;
//	while ((row)+1)
//	{
//		putpixel(col + x, row + y, color);
//		putpixel(col + x, y - row, color);
//		putpixel(x - col, row + y, color);
//		putpixel(x - col, y - row, color);
//		if (d <= 0)
//		{
//			col++;
//			d += four_b_square*col;
//		}
//		row--;
//		d += two_a_square*(3 - (row << 1));
//	}
//}
//
//void main(void)
//{
//	int X, Y;
//
//	asm mov ax, 0x0013
//		asm int 0x10
//		while (!kbhit()) putpixel(random(320), random(200), random(255));
//	getch();
//	while (!kbhit())
//	{
//		X = 50 + random(220);
//		Y = 50 + random(100);
//		ellipse(X, Y, 1 + random(48), 1 + random(48), random(255));
//	}
//	getch();
//}
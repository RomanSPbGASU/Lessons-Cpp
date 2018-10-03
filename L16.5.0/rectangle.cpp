#include "rectangle.h"

rectangle::rectangle() : shape(), rightbottom({ 100,100 })
{}
rectangle::rectangle(COORD leftup, COLORREF color, COORD rightdown):
	shape(leftup, color), rightbottom(rightdown)
{}
void rectangle::set_rectangle(COORD leftup, COLORREF color, COORD rightdown)
{
	point = leftup;
	color_type = color;
	rightbottom = rightdown;
}
void rectangle::draw_rectangle()
{
	HWND hW = GetConsoleWindow();
	HDC hDC = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 1, color_type);
	SelectObject(hDC, hPen);

	for (int i = point.Y; i != point.Y + rightbottom.Y; i++)
	{
		MoveToEx(hDC, point.X, i, NULL);
		LineTo(hDC, point.X + rightbottom.X, i);
	}

	DeleteObject(hPen);
	ReleaseDC(hW, hDC);
}
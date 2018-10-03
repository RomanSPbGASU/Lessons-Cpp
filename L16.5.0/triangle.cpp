#include "triangle.h"

triangle::triangle() : shape(), point2({ 100,200 }), point3({ 300, 400 })
{}
triangle::triangle(COORD basepoint = { 100,600 }, COLORREF color = RGB(0, 0, 255), 
	COORD secondpoint = { 100,200 }, COORD thirdpoint = { 300, 400 }) : 
	shape(basepoint, color), point2(secondpoint), point3(thirdpoint)
{}
void triangle::set_triangle(COORD basepoint, COLORREF color, COORD secondpoint, COORD thirdpoint)
{
	point = basepoint;
	color_type = color;
	point2 = secondpoint;
	point3 = thirdpoint;
}
boolean triangle::draw_triangle()
{
	if (point.Y == point2.Y || point.Y == point3.Y || point2.Y == point3.Y) return 0;

	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);
	HPEN hPen = CreatePen(PS_SOLID, 1, color_type);
	SelectObject(hDeviceContext, hPen);

	COORD up, under, another;
	if (point.Y < point2.Y && point.Y < point3.Y)
	{
		up = point;
		if (point2.Y > point3.Y)
		{
			under = point2;
			another = point3;
		}
		else
		{
			under = point3;
			another = point2;
		}
	}
	else if (point2.Y < point3.Y)
	{
		up = point2;
		if (point.Y > point3.Y)
		{
			under = point;
			another = point3;
		}
		else
		{
			under = point3;
			another = point;
		}
	}
	else
	{
		up = point3;
		if (point.Y > point2.Y)
		{
			under = point;
			another = point2;
		}
		else
		{
			under = point2;
			another = point;
		}
	}

	float A, B; // константы для первой прямой
	A = (under.X - up.X) / (float)(under.Y - up.Y);
	B = (up.X * under.Y - up.Y * under.X) / (float)(under.Y - up.Y);
	float C, D; // константы для второй прямой
	C = (another.X - up.X) / (float)(another.Y - up.Y);
	D = (up.X * another.Y - up.Y * another.X) / (float)(another.Y - up.Y);
	float E, F; // константы для третьей прямой
	E = (under.X - another.X) / (float)(under.Y - another.Y);
	F = (another.X * under.Y - another.Y * under.X) / (float)(under.Y - another.Y);

	for (int i = up.Y; i < another.Y; i++)
	{
		MoveToEx(hDeviceContext, i * A + B, i, NULL);
		LineTo(hDeviceContext, i * C + D, i);
	}
	for (int i = another.Y; i <= under.Y; i++)
	{
		MoveToEx(hDeviceContext, i * A + B, i, NULL);
		LineTo(hDeviceContext, i * E + F, i);
	}

	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	return 1;
}
#include "polygon.h"

polygon::polygon() : shape(), radius(200), angles(5)
{}
polygon::polygon(COORD center, COLORREF color, int polygonradius, int n) :
	shape(center, color), radius(polygonradius), angles(n)
{}
void polygon::set(COORD center, COLORREF color, int polygonradius, int n)
{
	point = center;
	color_type = color;
	radius = polygonradius;
	angles = n;
}
void polygon::draw()
{
	HWND hW = GetConsoleWindow();
	HDC hDC = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 2, color_type);
	SelectObject(hDC, hPen);

	struct DCOORD
	{
		double X;
		double Y;
	};
	DCOORD * angle = new DCOORD [angles];
	for (int i = 0; i <= angles; i++)
	{
		angle[i] = { (sin(2 * M_PI * (double)i / angles)), 
					 (-cos(2 * M_PI * (double)i / angles)) };
	}
	for (int i = radius; i >= 0; i--)
	{
		MoveToEx(hDC, i * angle[0].X + point.X, i * angle[0].Y + point.Y, NULL);
		for (int j = 1; j <= angles; j++)
		{
			LineTo(hDC, i * angle[j].X + point.X, i * angle[j].Y + point.Y);
		}
	}

	//delete [] angle; // вызывает срабатывание точки останова
	DeleteObject(hPen);
	ReleaseDC(hW, hDC);
}
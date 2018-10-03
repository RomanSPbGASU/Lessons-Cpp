#include "rhombus.h"

rhombus::rhombus() : shape(), diagonal(400), seconddiagonal(200)
{}
rhombus::rhombus(COORD center, COLORREF color, int diag, int secdiag) : 
	shape (center, color), diagonal(diag), seconddiagonal(secdiag)
{}
void rhombus::set_rhombus(COORD center, COLORREF color, int diag, int secdiag)
{
	point = center;
	color_type = color;
	diagonal = diag;
	seconddiagonal = secdiag;
}
int rhombus::draw_rhombus()
{
	if (diagonal == 0) return 0;
	HWND hWindow = GetConsoleWindow();
	HDC hDC = GetDC(hWindow);
	HPEN hPen = CreatePen(PS_SOLID, 1, color_type);
	SelectObject(hDC, hPen);

	float A = -(float)diagonal / seconddiagonal;
	seconddiagonal >>= 1;
	diagonal = (diagonal >> 1) + point.X;
	float B = point.X + (seconddiagonal - point.Y) * A;
	float C = diagonal + (seconddiagonal - point.Y) * A;
	double D = 1 / sqrt(A * A + 1);

	for (double y = point.Y - seconddiagonal; y <= point.Y; y+= D)
	{
		MoveToEx(hDC, y * A + B, y, NULL);
		LineTo(hDC, y * A + C, y + seconddiagonal);
	}

	DeleteObject(hPen);
	ReleaseDC(hWindow, hDC);
	return 1;
}
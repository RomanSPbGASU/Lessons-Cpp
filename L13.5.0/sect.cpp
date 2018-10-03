#include "sect.h"

sect::sect(COORD chartcenter, int sectorradius, float sectorangle, COLORREF sectorcolor)
{
	center = chartcenter;
	radius = sectorradius;
	angle = sectorangle;
	color = sectorcolor;
}
void sect::set_sect(COORD chartcenter, int sectorradius, float sectorangle, COLORREF sectorcolor)
{
	center = chartcenter;
	radius = sectorradius;
	angle = sectorangle;
	color = sectorcolor;
}
void sect::get_sect(COORD * chartcenter, int * sectorradius, float * sectorangle, COLORREF * sectorcolor)
{
	*chartcenter = center;
	*sectorradius = radius;
	*sectorangle = angle;
	*sectorcolor = color;
}
void sect::draw_sect() // как можно нарисовать несколько секторов, если каждому следующему ничего не известно о предыдущем?
{
	//подготовка к рисованию
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	hPen = CreatePen(PS_SOLID, 2, color);
	SelectObject(hDeviceContext, hPen);
	double deltaa = 180 / (radius * M_PI);
	for (double a = 0; a <= angle; a+=deltaa) //acos(cos(a / 180 * M_PI) + 1 / radius) / M_PI * 180 - a)
	{
		MoveToEx(hDeviceContext, center.X, center.Y, NULL);
		LineTo(hDeviceContext, center.X + radius * cos(a / 180 * M_PI), center.Y + radius * sin(a / 180 * M_PI));
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	//double i = cos(30. / 180 * M_PI);
	//cout << acos(i)/M_PI*180;
}


void _fullscreen()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
		GetLargestConsoleWindowSize(hStdout).Y - 1 };
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}
COORD outputsize()
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	return{ static_cast<short>(cr.right - cr.left), static_cast<short>(cr.bottom - cr.top) };
}
void Colorgradient(int numberofelements, float * intensity, COLORREF * gcolor)
{
	int elementsnumber = numberofelements;
	double x;
	int r, g, b;

	for (int i = 0; i < elementsnumber; i++)
	{
		x = (double(i) / elementsnumber);
		r = static_cast<int>(((1. - x) > 0.334? (1. - x): 0) * intensity[i] * 2.55);
		g = static_cast<int>((abs(0.5 - x) < 0.177? abs(0.5 - x) : 0) * intensity[i] * 2.55);
		b = static_cast<int>((x > 0.334? x : 0) * intensity[i] * 2.55);
		gcolor[i] = RGB(r*3, g*3, b*3);
	}
}

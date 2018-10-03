#include "circlesector.h"

circlesector::circlesector() {}
circlesector::circlesector(COORD chartcenter, int sectorradius, float initialangle, float endangle, COLORREF sectorcolor)
{
	center = chartcenter;
	radius = sectorradius;
	startangle = initialangle;
	finishangle = endangle;
	color = sectorcolor;
}
void circlesector::set_sect(COORD chartcenter, int sectorradius, float initialangle, float endangle, COLORREF sectorcolor)
{
	center = chartcenter;
	radius = sectorradius;
	startangle = initialangle;
	finishangle = endangle;
	color = sectorcolor;
}
void circlesector::get_sect(COORD * chartcenter, int * sectorradius, float * initialangle, float * endangle, COLORREF * sectorcolor)
{
	*chartcenter = center;
	*sectorradius = radius;
	*initialangle = startangle;
	*endangle = finishangle;
	*sectorcolor = color;
}
void circlesector::get_angle(float * angle)
{
	*angle = finishangle;
}
void circlesector::draw_sect()
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
	double cosinus, sinus, ocosinus, osinus;
	for (double a = startangle + 3 * deltaa; a <= finishangle - 3 * deltaa; a += deltaa)
	{
		cosinus = cos(a / 180 * M_PI);
		sinus = sin(a / 180 * M_PI);
		ocosinus = cos(((startangle + finishangle) / 2) / 180 * M_PI);
		osinus = sin(((startangle + finishangle) / 2) / 180 * M_PI);
		MoveToEx(hDeviceContext, center.X + 5 * ocosinus, center.Y - 5 * osinus, NULL);
		LineTo(hDeviceContext, center.X + (radius - 5) * cosinus, center.Y - (radius - 5) * sinus);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}


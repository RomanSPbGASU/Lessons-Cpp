#include "rect.h"

rect::rect() : left_bottom(), right_top(), color_type()
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr);										// получение размеров рабочей области окна стандартного вывода
	color_type = { rand() % 256, rand() % 256, rand() % 256 };
	left_bottom = { static_cast<short>(cr.right / 2), static_cast<short>(cr.bottom / 2) };
	right_top = { static_cast<short>(cr.right / 2), static_cast<short>(cr.bottom / 2) };
}

rect::rect(COORD LeBo, COORD RiTo, color Color) :
	left_bottom(LeBo), right_top(RiTo), color_type(Color)
{}

void rect::set_rect(short LeftBottomX, short LeftBottomY,
	short RightTopX, short RightTopY,
	byte ColorTypeR, byte ColorTypeG, byte ColorTypeB)
{
	left_bottom.X = LeftBottomX;
	left_bottom.Y = LeftBottomY;
	right_top.X = RightTopX;
	right_top.Y = RightTopY;
	color_type = { ColorTypeR, ColorTypeG, ColorTypeB };
}

void rect::set_rect(COORD LeftBottom, COORD RightTop)
{
	left_bottom.X = LeftBottom.X;
	left_bottom.Y = LeftBottom.Y;
	right_top.X = RightTop.X;
	right_top.Y = RightTop.Y;
}

void rect::get_rect(COORD * leftbottom, COORD * righttop)
{
	*leftbottom = left_bottom;
	*righttop = right_top;
}

void rect::draw_rect()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//подготовка к рисованию
	HWND hWindow = GetConsoleWindow();
	HDC hDeviceContext = GetDC(hWindow);
	COLORREF color = RGB(color_type.red, color_type.green, color_type.blue);
	HPEN hPen = CreatePen(PS_SOLID, 2, color);
	SelectObject(hDeviceContext, hPen);
	//рисуем прямоугольник
	for (int i = left_bottom.X; i <= right_top.X; i++)
	{
		MoveToEx(hDeviceContext, i, right_top.Y, NULL);
		LineTo(hDeviceContext, i, left_bottom.Y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}

void Increase(rect &r, rect::color color)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr);											// получение размеров рабочей области окна стандартного вывода
	COORD clirect = { (short)cr.right, (short)cr.bottom };
	COORD lebo, rito;
	lebo = r.left_bottom;
	rito = r.right_top;
	if (lebo.Y <= rito.Y) { lebo.Y -= clirect.Y / 20; rito.Y += clirect.Y / 20; }
	else { lebo.Y += clirect.Y / 20; rito.Y -= clirect.Y / 20; }
	if (lebo.X <= rito.X) { lebo.X -= clirect.X / 20; rito.X += clirect.X / 20; }
	else { lebo.X += clirect.X / 20; rito.X -= clirect.X / 20; }
	r.set_rect( lebo.X, lebo.Y , rito.X, rito.Y, color.red, color.green, color.blue );
	r.draw_rect();
}

void Decrease(rect &r, rect::color color)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr);											// получение размеров рабочей области окна стандартного вывода
	COORD clirect = { (short)cr.right, (short)cr.bottom };
	COORD lebo, rito;
	lebo = r.left_bottom;
	rito = r.right_top;
	if (lebo.Y <= rito.Y) { lebo.Y += clirect.Y / 20; rito.Y -= clirect.Y / 20; }
	else { lebo.Y -= clirect.Y / 20; rito.Y += clirect.Y / 20; }
	if (lebo.X <= rito.X) { lebo.X += clirect.X / 20; rito.X -= clirect.X / 20; }
	else { lebo.X -= clirect.X / 20; rito.X += clirect.X / 20; }
	r.set_rect(lebo.X, lebo.Y, rito.X, rito.Y, color.red, color.green, color.blue);
	r.draw_rect();
}

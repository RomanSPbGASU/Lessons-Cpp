#include "rect.h"

rect::rect() : left_bottom(), right_top(), color_type() // создает прямоугольник в центре рабочей области размером 0х0
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); // получение размеров рабочей области окна стандартного вывода
	srand(time(0));
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
{													// Так как функция get_rect не возвращает
	left_bottom.X = LeftBottom.X;					// цвет прямоугольника (по заданию), а функция
	left_bottom.Y = LeftBottom.Y;					// set_rect из задания 10.2 требует задания цвета,
	right_top.X = RightTop.X;						// пришлось её перегружать
	right_top.Y = RightTop.Y;
}
void rect::get_rect(COORD * leftbottom, COORD * righttop) //очень долго до меня доходило, как это сделать
{
	*leftbottom = left_bottom;
	*righttop = right_top;
}
void rect::draw_rect()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//делаем перо невидимым
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(hStdout, &curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curs);
	//подготовка к рисованию
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	COLORREF color = RGB(color_type.red, color_type.green, color_type.blue);
	//рисуем прямоугольник
	hPen = CreatePen(PS_SOLID, 2, color);
	SelectObject(hDeviceContext, hPen);
	for (int i = left_bottom.X; i <= right_top.X; i++)
	{
		MoveToEx(hDeviceContext, i, right_top.Y, NULL);
		LineTo(hDeviceContext, i, left_bottom.Y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}
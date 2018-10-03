#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

struct color
{
	int red;
	int green;
	int blue;
};
struct add
{
	int addx;
	int addy;
};

class rect
{
private:
	COORD left_bottom;
	COORD right_top;
	color color_type;
public:
	rect() : left_bottom(), right_top(), color_type()
	{
		HWND hWnd = GetForegroundWindow();
		RECT cr;
		GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
		color_type = { rand() % 256, rand() % 256, rand() % 256 };
		left_bottom = { static_cast<short>(cr.right / 2), static_cast<short>(cr.bottom / 2) };
		right_top = { static_cast<short>(cr.right / 2), static_cast<short>(cr.bottom / 2) };
	}
	rect(COORD LeBo, COORD RiTo, color Color) :
		left_bottom(LeBo), right_top(RiTo), color_type(Color)
	{}
	//rect(COORD LeBo = { 1345 / 2, 685 / 2 },
	//	COORD RiTo = {1345 / 2 + 2, 685 / 2 - 2 },
	//	color Color = { 255,100,100 }) :
	//	left_bottom(LeBo), right_top(RiTo), color_type(Color)
	//{}
	void set_rect(short LeftBottomX, short LeftBottomY,
		short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB)
	{
		left_bottom.X = LeftBottomX;
		left_bottom.Y = LeftBottomY;
		right_top.X = RightTopX;
		right_top.Y = RightTopY;
		color_type = { ColorTypeR, ColorTypeG, ColorTypeB };
	}
	void set_rect(COORD LeftBottom, COORD RightTop)
	{													// Так как функция get_rect не возвращает
		left_bottom.X = LeftBottom.X;					// цвет прямоугольника (по заданию), а функция
		left_bottom.Y = LeftBottom.Y;					// set_rect из задания 10.2 требует задания цвета,
		right_top.X = RightTop.X;						// пришлось её перегружать
		right_top.Y = RightTop.Y;
	}
	void get_rect(COORD * leftbottom, COORD * righttop) //очень долго до меня доходило, как это сделать
	{
		*leftbottom = left_bottom;
		*righttop = right_top;
	}
	void draw_rect()
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
};

void Increase(COORD * leftbottom, COORD * righttop);
void Decrease(COORD * leftbottom, COORD * righttop);

void main()
{
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
						GetLargestConsoleWindowSize(hStdout).Y - 1 }; //poluchit' maximal'no vozmozhniy razmer okna konsoli
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3);

	rect r1;
	for (int i=0; i<=10; i++)
	{
	r1.draw_rect();
	COORD lb, rt;
	r1.get_rect(&lb, &rt);
	Increase(&lb, &rt);
	r1.set_rect(lb.X, lb.Y, rt.X, rt.Y, rand()%256,rand()%256, rand()%256);
	Sleep(100);
	}
	for (int i = 0; i <= 10; i++)
	{
		r1.draw_rect();
		COORD lb, rt;
		r1.get_rect(&lb, &rt);
		Decrease(&lb, &rt);
		r1.set_rect(lb.X, lb.Y, rt.X, rt.Y, rand() % 256, rand() % 256, rand() % 256);
		Sleep(100);
	}
	_getche();
}

void Increase(COORD * leftbottom, COORD * righttop)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	COORD clirect = { static_cast<short>(cr.right), static_cast<short>(cr.bottom) };
	COORD lebo, rito;
	lebo = *leftbottom;
	rito = *righttop;
	if (lebo.Y <= rito.Y) { lebo.Y -= clirect.Y / 20; rito.Y += clirect.Y / 20; }
	else { lebo.Y += clirect.Y / 20; rito.Y -= clirect.Y / 20; }
	if (lebo.X <= rito.X) { lebo.X -= clirect.X / 20; rito.X += clirect.X / 20; }
	else {	lebo.X += clirect.X / 20; rito.X -= clirect.X / 20;	}
	*leftbottom = { lebo.X, lebo.Y };
	*righttop = { rito.X, rito.Y };
}

void Decrease(COORD * leftbottom, COORD * righttop)
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
	COORD clirect = { static_cast<short>(cr.right), static_cast<short>(cr.bottom) };
	COORD lebo, rito;
	lebo = *leftbottom;
	rito = *righttop;
	if (lebo.Y <= rito.Y) { lebo.Y += clirect.Y / 20; rito.Y -= clirect.Y / 20; }
	else { lebo.Y -= clirect.Y / 20; rito.Y += clirect.Y / 20; }
	if (lebo.X <= rito.X) { lebo.X += clirect.X / 20; rito.X -= clirect.X / 20; }
	else { lebo.X -= clirect.X / 20; rito.X += clirect.X / 20; }
	*leftbottom = { lebo.X, lebo.Y };
	*righttop = { rito.X, rito.Y };
}
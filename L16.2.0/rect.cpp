#include "rect.h"

rect::rect() : left_bottom(), right_top(), color_type() // ������� ������������� � ������ ������� ������� �������� 0�0
{
	HWND hWnd = GetForegroundWindow();
	RECT cr;
	GetClientRect(hWnd, &cr); // ��������� �������� ������� ������� ���� ������������ ������
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
{													// ��� ��� ������� get_rect �� ����������
	left_bottom.X = LeftBottom.X;					// ���� �������������� (�� �������), � �������
	left_bottom.Y = LeftBottom.Y;					// set_rect �� ������� 10.2 ������� ������� �����,
	right_top.X = RightTop.X;						// �������� � �����������
	right_top.Y = RightTop.Y;
}
void rect::get_rect(COORD * leftbottom, COORD * righttop) //����� ����� �� ���� ��������, ��� ��� �������
{
	*leftbottom = left_bottom;
	*righttop = right_top;
}
void rect::draw_rect()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//������ ���� ���������
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(hStdout, &curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curs);
	//���������� � ���������
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	COLORREF color = RGB(color_type.red, color_type.green, color_type.blue);
	//������ �������������
	hPen = CreatePen(PS_SOLID, 2, color);
	SelectObject(hDeviceContext, hPen);
	for (int i = left_bottom.X; i <= right_top.X; i++)
	{
		MoveToEx(hDeviceContext, i, right_top.Y, NULL);
		LineTo(hDeviceContext, i, left_bottom.Y);
	}
	//������� ����, ����������� ��������
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}
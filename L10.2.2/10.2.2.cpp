#include <Windows.h>
#include <conio.h>

using namespace std;

void main()
{
	//открываем окно вывода на весь экран
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	//делаем перо невидимым
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
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
	COLORREF color[] = { RGB(100, 100, 100), RGB(200, 200, 200) };
	//рисуем верхнюю половинку ромба
	hPen = CreatePen(PS_SOLID, 1, color[0]);
	SelectObject(hDeviceContext, hPen);
	COORD point[] = { { 300, 50 }, { 50, 150 }, { 550, 150 }, { 300, 250 } };
	int center_line = point[2].X-point[1].X;
	for (int j = 0; j < center_line; j++)
	{
		MoveToEx(hDeviceContext, point[0].X, point[0].Y, NULL);
		LineTo(hDeviceContext, point[1].X + j, point[1].Y);
	}
	//рисуем нижнюю половину ромба
	hPen = CreatePen(PS_SOLID, 1, color[1]);
	SelectObject(hDeviceContext, hPen);
	for (int j = 0; j < center_line; j++)
	{
		MoveToEx(hDeviceContext, point[3].X, point[3].Y, NULL);
		LineTo(hDeviceContext, point[1].X + j, point[1].Y);
	}
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	_getche();
}

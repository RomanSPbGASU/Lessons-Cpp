#include <Windows.h>
#include <conio.h>

using namespace std;

void main()
{
	//��������� ���� ������ �� ���� �����
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	//������ ���� ���������
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
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
	COLORREF color[] = { RGB(0, 0, 100), RGB(100, 100, 255), RGB(200, 200, 245) };
	COORD point[] = { { 450, 100 }, { 150, 200 }, { 750, 200 }, 
	{ 450, 300 }, { 150, 400 }, { 750, 400 }, { 450, 500 } };
	//������ ������� �������
	hPen = CreatePen(PS_SOLID, 1, color[2]);
	SelectObject(hDeviceContext, hPen);
	int diagX = point[3].X - point[1].X; //�������� ����� ������� �������
	int diagY = point[3].Y - point[1].Y;
	int diag = diagY/diagX;
	for (int j = 0; j < diagX; j++)
	{
		MoveToEx(hDeviceContext, point[1].X + j, point[1].Y + j/3, NULL);
		LineTo(hDeviceContext, point[0].X + j, point[0].Y + j/3);
	}
	// ������ �������� �������
	hPen = CreatePen(PS_SOLID, 1, color[1]);
	SelectObject(hDeviceContext, hPen);
	int width = point[4].Y - point[1].Y;
	for (float j = 0; j < width; j++)
	{
		MoveToEx(hDeviceContext, point[1].X, point[1].Y + j, NULL);
		LineTo(hDeviceContext, point[3].X, point[3].Y + j);
	}
	//������ ������ �������
	hPen = CreatePen(PS_SOLID, 1, color[0]);
	SelectObject(hDeviceContext, hPen);
	for (int j = 0; j < width; j++)
	{
		MoveToEx(hDeviceContext, point[3].X, point[3].Y + j, NULL);
		LineTo(hDeviceContext, point[2].X, point[2].Y + j);
	}
	//������� ����, ����������� ��������
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	_getche();
}
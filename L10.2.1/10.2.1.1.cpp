#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int FullScreen()
{
	//��������� ���� ������ �� ���� �����
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}
int InvisiblePen()
{
	//������ ���� ���������
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(hStdout, &curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curs);
}
int ReadyToPainting()
{
	//���������� � ���������
	HWND hWindow = NULL;
	HDC hDeviceContext;
	HPEN hPen;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
}
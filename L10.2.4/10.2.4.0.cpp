#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

void main()
{
	//��������� ���� ������ �� ���� �����
	HWND hWnd = GetForegroundWindow();						// �������� ���������� ���� ( ���-�� ���� ������������������ ������)
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);						// ������� ���� �� ���� �����
	//���������� � ���������
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);		// �������� ���������� ������� ������� ���� ������������ ������ (�������)
	HWND hWindow = GetConsoleWindow();						// ���������� �������
	HDC hDeviceContext = GetDC(hWindow);					// �������� ���������� - ������� ( ��� �� ����� ������������ ��������� ����������)
	COLORREF color[] = { RGB(0, 0, 0), RGB(255, 255, 255) };
	COORD center = { 695, 350 };
	float radius = 270.0;
	//������ ����� ������
	HPEN hPen = CreatePen(PS_SOLID, 2, color[1]);			// ������� ������ - ����
	
	SelectObject(hDeviceContext, hPen);						// ������� ����
	for (float x = 0; x <= 2*M_PI; x += 0.001f)
	{
		MoveToEx(hDeviceContext, center.X, center.Y, NULL);	// ��������� ���� � ����� �����
		LineTo(hDeviceContext, radius*sin(x) + center.X, radius*cos(x) + center.Y);	// ���������� ����� � ����� ����������
	}
	//������ ������ �������
	hPen = CreatePen(PS_SOLID, 2, color[0]);
	SelectObject(hDeviceContext, hPen);
	for (float j = 0.901; j>=0.3; j-=0.1f)
	{
		for (float x = 0; x <= 2*M_PI; x += 0.001)
		{
			MoveToEx(hDeviceContext, radius*j*sin(x) + center.X, radius*j*cos(x) + center.Y, NULL);
			LineTo(hDeviceContext, radius*j*sin(x) + center.X, radius*j*cos(x) + center.Y);
		}
	}
	//������ ������ ������
	hPen = CreatePen(PS_SOLID, 2, color[0]);
	SelectObject(hDeviceContext, hPen);
	for (float x = -0.3*radius; x <= 0.3*radius; x += 0.03)
	{
		MoveToEx(hDeviceContext, center.X, center.Y, NULL);
		LineTo(hDeviceContext, 0.3*radius*sin(x) + center.X, 0.3*radius*cos(x) + center.Y);
	}
	//������ ����� �������
	hPen = CreatePen(PS_SOLID, 2, color[1]);
	SelectObject(hDeviceContext, hPen);
	for (float j = 0.301; j >= 0; j -= 0.1)
	{
		for (float x = -j*radius; x <= j*radius; x += 0.03)
		{
			MoveToEx(hDeviceContext, radius*j*sin(x) + center.X, radius*j*cos(x) + center.Y, NULL);
			LineTo(hDeviceContext, radius*j*sin(x) + center.X, radius*j*cos(x) + center.Y);
		}
	}
	//����� �����
	//center = { center.X * 80 / 1280, center.Y * 25 / 1024 };
	//radius = radius * 80 / 1280;
	center = { 87, 29 }; //��������� �������� ��� �������
	int radiusy = 24; //��������� �������� ��� �������
	int radiusx = 36; //��������� �������� ��� �������
	SetConsoleTextAttribute(hStdout, BACKGROUND_RED + BACKGROUND_BLUE+ BACKGROUND_GREEN);
	for (float n = 0.9; n > 0.2; n-=0.1)
	{
		COORD left_side = { center.X - radiusx*n, center.Y };
		SetConsoleCursorPosition(hStdout, left_side);
		cout << 10 - 10 * n;
		COORD right_side = { center.X + radiusx*n, center.Y };
		SetConsoleCursorPosition(hStdout, right_side);
		cout << 10 - 10 * n;
		COORD top_side = { center.X, center.Y - radiusy*n };
		SetConsoleCursorPosition(hStdout, top_side);
		cout << 10 - 10 * n;
		COORD buttom_side = { center.X, center.Y + radiusy*n };
		SetConsoleCursorPosition(hStdout, buttom_side);
		cout << 10 - 10 * n;
	}
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_GREEN + 0);
	for (float n = 0.2; n > 0.1; n -= 0.1)
	{
		COORD left_side = { center.X - radiusx*n, center.Y };
		SetConsoleCursorPosition(hStdout, left_side);
		cout << 10 - 10 * n;
		COORD right_side = { center.X + radiusx*n, center.Y };
		SetConsoleCursorPosition(hStdout, right_side);
		cout << 10 - 10 * n;
		COORD top_side = { center.X, center.Y - radiusy*n };
		SetConsoleCursorPosition(hStdout, top_side);
		cout << 10 - 10 * n;
		COORD buttom_side = { center.X, center.Y + radiusy*n };
		SetConsoleCursorPosition(hStdout, buttom_side);
		cout << 10 - 10 * n;
	}
	//������� ����, ����������� ��������
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
	_getche();
}
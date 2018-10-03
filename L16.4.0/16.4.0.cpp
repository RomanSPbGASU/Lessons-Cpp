#include "ellipse.h"
#include "circle.h"

void main()
{
	//открываем окно вывода на весь экран
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X - 1,
		GetLargestConsoleWindowSize(hStdout).Y - 1 }; //poluchit' maximal'no vozmozhniy razmer okna konsoli
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3);

	ellipse e1, e2;
	e2.set_ellipse({ 680, 350 }, 100, 200, RGB(200, 100, 255));
	e1.draw_ellipse();
	e2.draw_ellipse();
	cin.get();
}
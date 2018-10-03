#include "move_rect.h"
#include "rect.h"

void main()
{
	SetConsoleOutputCP(1251);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD max = { GetLargestConsoleWindowSize(hStdout).X,
						GetLargestConsoleWindowSize(hStdout).Y }; // получить максимально возможный размер окна консоли
	SetConsoleScreenBufferSize(hStdout, max);
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, 3); // 3 = SW_MAXIMIZE

	srand(time(0)); // чтобы значения в rand() каждый раз были разными
	do
	{
		move_rect r1;
		r1.draw_rect();
		for (int i = 0; i < 10; i++)
		{
			color color_type = { rand() % 256, rand() % 256, rand() % 256 };
			r1.increase(color_type);
			Sleep(100);
		}
		for (int i = 0; i < 10; i++)
		{
			color color_type = { rand() % 256, rand() % 256, rand() % 256 };
			r1.decrease(color_type);
			Sleep(100);
		}
	} while (1);
}

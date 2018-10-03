#include "circle.h"

circle::circle()
{}
circle::circle(COORD ce = { 1365 / 2, 686 / 2 }, int ra = 686 * 0.4,
	COLORREF co = RGB(255, 0, 0)) : center(ce), radius(ra), color(co)
{}
void circle::set_circle(COORD circlecenter,
	int rad, COLORREF circlecolor)
{
	center = circlecenter;
	radius = rad;
	color = circlecolor;
}
void circle::draw_circle()
{
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
	//рисуем круг
	hPen = CreatePen(PS_SOLID, 2, color);
	SelectObject(hDeviceContext, hPen);
	for (int y = center.Y - radius; y <= center.Y + radius; y++)
	{
		int undersqrt = static_cast<int>(sqrt(radius*radius - (y - center.Y)*(y - center.Y)));
		MoveToEx(hDeviceContext, center.X - undersqrt, y, NULL);
		LineTo(hDeviceContext, center.X + undersqrt, y);
	}
	//удаляем перо, освобождаем контекст
	DeleteObject(hPen);
	ReleaseDC(hWindow, hDeviceContext);
}

COORD SymbToPix(COORD Symb)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	return{ (2 * Symb.X * consolefont.dwFontSize.X + 1) / 2, (2 * Symb.Y * consolefont.dwFontSize.Y + 1) / 2 };
}
COORD PixToSymb(COORD Pix)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	short x = Pix.X / consolefont.dwFontSize.X;
	short y = Pix.Y / consolefont.dwFontSize.Y;
	return{ x, y };
}
short PixToSymbX(short x)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	x = x / consolefont.dwFontSize.X;
	return(x);
}
short PixToSymbY(short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consolefont;
	GetCurrentConsoleFont(hStdout, 0, &consolefont);
	y = y / consolefont.dwFontSize.Y;
	return(y);
}
void PrintInCoord(COORD coordinates, char *text)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, coordinates);
	cout << text;
}



/*
CONSOLE_SCREEN_BUFFER_INFO sbi;
GetConsoleScreenBufferInfo(hStdout, &sbi);
SMALL_RECT StdSize;
StdSize = sbi.srWindow; // poluchili koordinaty uglov rabochey oblasti okna
RECT cr;
GetClientRect(hWnd, &cr); //poluchenie razmerov rabochey oblasti okna standartnogo vyvoda
cout << cr.bottom <<" " << cr.right;
GetWindowRect(hWnd, &cr); //poluchenie razmerov okna standartnogo vyvoda
cout << "\n";
cout << cr.bottom << " " << cr.right;
MoveWindow(hWnd, 0, 0, 500, 400, 1); //izmenyaet razmery i polozhenie okna
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD max = GetLargestConsoleWindowSize(hStdout); //poluchit' maximal'no vozmozhniy razmer okna konsoli
cout << "\n" << max.X << " " << max.Y;
SMALL_RECT StdSize = { 0, 0, max.X, max.Y };
SetConsoleWindowInfo(hStdout, 1, &StdSize); //izmeniaet razmer i polozhenie okna (v simvolah)
*/
#include <Windows.h>
#include <conio.h> // МОЖНО ЛИ ПОДКЛЮЧИТЬ НЕ ВСЕ МЕТОДЫ ЗАГОЛОВОЧНОГО ФАЙЛА (ЕСЛИ ИХ ОЧЕНЬ МНОГО), А ТОЛЬКО НУЖНЫЕ?
#include <iostream>
#include <iomanip>
#include "rect.h"
#include "circle.h"
#include "line.h"
#include "sect.h"

using namespace std;

void main()
{
	_fullscreen();
	setlocale(LC_ALL, "Russian");

	COORD window = outputsize();
	COORD framecoord[] = { {window.Y / 7, window.Y / 7}, {window.X - window.Y / 7, window.Y / 7},
							{window.X - window.Y / 7, 6 * window.Y / 7}, {window.Y / 7, 6 * window.Y / 7} };
	line frameline;
	for (int i = 0; i < 4; i++) //рисуем рамку
	{
		frameline.set_line(framecoord[i], i == 3 ? framecoord[0] : framecoord[i + 1], RGB(255, 0, 0), PS_SOLID, 2);
		frameline.draw_line();
	}
	line levelline;
	for (short i = 0; i < 4; i++) //рисуем уровни
	{
		levelline.set_line({ window.Y / 7, short(2. / 7 * window.Y) + i * window.Y / 7 },
			{ window.X - window.Y / 7,  short(2. / 7 * window.Y) + i * window.Y / 7 }, RGB(255,0,0), PS_DASH, 1);
		levelline.draw_line();
	}
	cout << "\n\n" << setw(100) << right << "СТРУКТУРА ИНВЕСТИЦИОННОГО ПОРТФЕЛЯ";
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < 6; i++) //подписываем ось Y
	{
		SetConsoleCursorPosition(hStdout, PixToSymb({ window.Y / 14,  window.Y / 7 + i * window.Y / 7 }));
		cout << setw(2) << right << 100 - 20 * i;
	}
	portfolio investment[5] = { { "Ростелеком", 20, 255,0,0 },{ "Мегафон", 15, 255,255,0 }, // КАК ВЫНЕСТИ МАССИВ В ЗАГОЛОВОЧНЫЙ ФАЙЛ?
	{ "МТС", 35, 0,255,0 },{ "АФК Система", 10, 255,0,255 },{ "Башкирэнерго", 20, 0,0,255 } };
	rect chart;
	for (short i = 0; i < 5; i++) //рисуем столбики с подписями
	{
		chart.set_rect( short(2. / 13 * (i + 1) * window.X), short(6. / 7 * window.Y),
			short((2. / 13 * (i + 1) + 1. / 13) * window.X), short((6. / 7 -  5. / 700 * investment[i].percent) * window.Y),
			RGB(investment[i].colorR, investment[i].colorG, investment[i].colorB));
		chart.draw_rect();
		SetConsoleCursorPosition(hStdout, PixToSymb({ short(2. / 13 * (i + 1) * window.X),
													  short(13. / 14 * window.Y) }));
		cout << investment[i].issuer;
	}
	_getche(); // ЧЕМ ЗАМЕНИТЬ _getche()? (НЕ ИЗ conio.h)
}
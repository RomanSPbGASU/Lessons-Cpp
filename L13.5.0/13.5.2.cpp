//свой вариант с "блэкджеком и ..."
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "13.5.h"
#include "12.4.h"
#include "12.2.h"

using namespace std;

void main()
{
	_fullscreen();
	setlocale(LC_ALL, "Russian");

	struct portfolio
	{
		char * issuer;
		float percent;
	};
	portfolio investment[] = { { "Ростелеком", 20 },{ "Мегафон", 15 },
	{ "МТС", 35 },{ "АФК Система", 10 },{ "Башкирэнерго", 20 } };

	COORD windowsize = outputsize();
	const int portfoliosize = sizeof(investment) / sizeof(portfolio);
	int chartradius = static_cast<int>(0.3 * windowsize.Y);
	// рисуем белые основания
	circle c1({ windowsize.X / 2, windowsize.Y / 2 }, chartradius, RGB(255, 255, 255));
	c1.draw_circle();
	rect r1, legend(static_cast<short>(windowsize.X * 0.75), 100 + portfoliosize * 30,
		static_cast<short>(windowsize.X * 0.95), 100, 255, 255, 255);
	legend.draw_rect();
	//
	COLORREF color[portfoliosize]; //массив цветов соответствующих массиву значений
	float intensity[portfoliosize]; //массив значений
	for (int i = 0; i < portfoliosize; i++) //заполняем массивы
	{
		intensity[i] = investment[i].percent;
		color[i] = 0;
	}
	Colorgradient(portfoliosize, intensity, color); //функция значения -> цвета
	circlesector s1({ windowsize.X, windowsize.Y }, chartradius - 5, 0, 0, RGB(255, 255, 255));
	float angle;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, PixToSymb({ 500, 100 }));
	cout << "СТРУКТУРА ИНВЕСТИЦИОННОГО ПОРТФЕЛЯ";
	for (int i = 0; i < portfoliosize; i++)
	{
		SetConsoleCursorPosition(hStdout, PixToSymb({ static_cast<short>(windowsize.X * 0.83),
			static_cast<short>(115 + i * 30) }));
		cout << investment[i].issuer << " - " << investment[i].percent << "%";
		s1.get_angle(&angle);
		s1.set_sect({ static_cast<short>(windowsize.X / 2), static_cast<short>(windowsize.Y / 2)},
			chartradius, angle, angle + investment[i].percent * float(3.6), color[i]); //цвет берем из массива
		s1.draw_sect();
		r1.set_rect(static_cast<short>(windowsize.X * 0.76), 125 + i * 30,
			static_cast<short>(windowsize.X * 0.81), 105 + i * 30, color[i]);
		r1.draw_rect();
	}

	_getche();
}
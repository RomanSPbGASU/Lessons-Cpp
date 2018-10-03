// по заданию
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <locale.h>
#include "sect.h"
#include "circle.h"
#include "rect.h"

using namespace std;

int main()
{
	_fullscreen();
	setlocale(LC_ALL, "Russian");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, PixToSymb({ 500, 100 }));
	cout << "СТРУКТУРА ИНВЕСТИЦИОННОГО ПОРТФЕЛЯ";

	portfolio investment[5] = { { "Ростелеком", 20, 255,0,0 },{ "Мегафон", 15, 255,255,0 },
	{ "МТС", 35, 0,255,0 },{ "АФК Система", 10, 255,0,255 },{ "Башкирэнерго", 20, 0,0,255 } };
	// пишем легенду
	rect r1;
	for (int i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(hStdout, PixToSymb({ 1050, static_cast<short>(140 + i * 50) }));
		cout << investment[i].issuer << " - " << investment[i].percent << "%";
		r1.set_rect(950, 150 + i * 50, 1000, 130 + i * 50, investment[i].colorR, investment[i].colorG, investment[i].colorB);
		r1.draw_rect();
	}
	// рисуем диаграмму
	sect s1({ 512,384 }, 200, 360, RGB(investment[0].colorR, investment[0].colorG, investment[0].colorB));
	s1.draw_sect();
	float emptyangle = 360;
	for (int i = 0; i < 4; i++)
	{
		emptyangle -= investment[i].percent*360/100;
		s1.set_sect({ 512,384 }, 200, emptyangle, RGB(investment[i+1].colorR, investment[i+1].colorG, investment[i+1].colorB));
		s1.draw_sect();
	}
	_getche();
}
#pragma once
#include <iostream>
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

//класс по заданию
class sect
{
private:
	COORD center;
	int radius;
	float angle;
	COLORREF color;
public:
	sect(COORD chartcenter, int sectorradius, float sectorangle, COLORREF sectorcolor);
	void set_sect(COORD chartcenter, int sectorradius, float sectorangle, COLORREF sectorcolor);
	void get_sect(COORD * chartcenter, int * sectorradius, float * sectorangle, COLORREF * sectorcolor);
	void draw_sect();
};

struct portfolio
{
	char * issuer;
	float percent;
	byte colorR;
	byte colorG;
	byte colorB;
};

void _fullscreen();
COORD outputsize();
void Colorgradient(int numberofelements, float * intensity, COLORREF * gcolor); // принимает массив чисел (0-100), возвращает массив цветов
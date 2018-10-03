#pragma once
#include <iostream>
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class circlesector
{
private:
	COORD center;
	int radius;
	float startangle;
	float finishangle;
	COLORREF color;
public:
	circlesector();
	circlesector(COORD chartcenter, int sectorradius, float initialangle, float endangle, COLORREF sectorcolor);
	void set_sect(COORD chartcenter, int sectorradius, float initialangle, float endangle, COLORREF sectorcolor);
	void get_sect(COORD * chartcenter, int * sectorradius, float * initialangle, float * endangle, COLORREF * sectorcolor);
	void get_angle(float * angle);
	void draw_sect();
};

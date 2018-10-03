#pragma once
#include "shape.h"
#define _USE_MATH_DEFINES
#include <math.h>

class polygon : public shape
{
private:
	int radius;
	int angles;
public:
	polygon();
	polygon(COORD, COLORREF, int, int);
	void set(COORD, COLORREF, int, int);
	void draw();
};
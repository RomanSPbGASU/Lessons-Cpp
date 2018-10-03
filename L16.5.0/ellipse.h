#pragma once
#include "shape.h"
#include <math.h>

class ellipse : public shape
{
private:
	int radius;
	int secondradius;
public:
	ellipse();
	ellipse(COORD, COLORREF, int, int);
	void set_ellipse(COORD, int, int, COLORREF);
	void draw_ellipse();
};

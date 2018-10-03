#pragma once
#include "circle.h"
#include <math.h>

class ellipse : public circle
{
private:
	int secondradius;
public:
	ellipse();
	void set_ellipse(COORD, int, int, COLORREF);
	void draw_ellipse();
};
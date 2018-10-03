#pragma once
#include "shape.h"

class triangle : public shape
{
private:
	COORD point2, point3;
public:
	triangle();
	triangle(COORD, COLORREF, COORD, COORD);
	void set_triangle(COORD, COLORREF, COORD, COORD);
	boolean draw_triangle();
};

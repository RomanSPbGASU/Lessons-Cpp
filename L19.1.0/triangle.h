#pragma once
#include "shape.h"

class triangle : public shape
{
private:
	COORD point2, point3;
public:
	triangle();
	triangle(COORD, COLORREF, COORD, COORD);
	void set(COORD, COLORREF, COORD, COORD);
	void draw();
};

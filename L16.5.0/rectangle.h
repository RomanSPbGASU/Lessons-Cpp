#pragma once
#include "shape.h"

class rectangle : public shape
{
private:
	COORD rightbottom;
public:
	rectangle();
	rectangle(COORD, COLORREF, COORD);
	void set_rectangle(COORD, COLORREF, COORD);
	void draw_rectangle();
};
#pragma once
#include "shape.h"
#include <math.h>

class rhombus : public shape
{
private:
	int diagonal;
	int seconddiagonal;
public:
	rhombus();
	rhombus(COORD, COLORREF, int, int); // построение ромба по двум диагоналям
	void set(COORD, COLORREF, int, int);
	void draw();
};
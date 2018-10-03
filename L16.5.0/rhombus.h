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
	rhombus(COORD, COLORREF, int, int); // ���������� ����� �� ���� ����������
	void set_rhombus(COORD, COLORREF, int, int);
	int draw_rhombus();
};
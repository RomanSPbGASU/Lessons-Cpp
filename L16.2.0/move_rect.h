#pragma once
#include "rect.h"

class move_rect : public rect
{
public:
	move_rect();
	move_rect(COORD, COORD, color);
	void increase(color); // ����������� ������������� � ������� ��� �� �����
	void decrease(color); // ��������� ������������� � ������� ��� �� �����
};
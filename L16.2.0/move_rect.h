#pragma once
#include "rect.h"

class move_rect : public rect
{
public:
	move_rect();
	move_rect(COORD, COORD, color);
	void increase(color); // увеличивает прямоугольник и выводит его на экран
	void decrease(color); // уменьшает прямоугольник и выводит его на экран
};
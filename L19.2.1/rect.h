#pragma once
#include <Windows.h>

class rect
{
private:
	COORD left_bottom;
	COORD right_top;
	struct color
	{
		int red;
		int green;
		int blue;
	} color_type;
public:
	rect();
	rect(COORD LeBo, COORD RiTo, color Color);
	void set_rect(short LeftBottomX, short LeftBottomY,
		short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB);
	void set_rect(COORD LeftBottom, COORD RightTop);
	void get_rect(COORD * leftbottom, COORD * righttop);
	void draw_rect();
	friend void Increase(rect&, color);
	friend void Decrease(rect&, color);
};

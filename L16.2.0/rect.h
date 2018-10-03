#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

struct color
{
	int red;
	int green;
	int blue;
};
struct add
{
	int addx;
	int addy;
};

class rect
{
private:
	COORD left_bottom;
	COORD right_top;
	color color_type;
public:
	rect();
	rect(COORD, COORD, color);
	void set_rect(short LeftBottomX, short LeftBottomY,
		short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB);
	void set_rect(COORD LeftBottom, COORD RightTop);
	void get_rect(COORD * leftbottom, COORD * righttop);
	void draw_rect();
};
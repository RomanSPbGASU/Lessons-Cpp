
struct color
{
	int red;
	int green;
	int blue;
};

class rect
{
private:
	COORD left_bottom;
	COORD right_top;
	COLORREF color_type;
public:
	rect();
	rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB);
	rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY, COLORREF ColorType);
	~rect();
	void set_rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY,
		byte ColorTypeR, byte ColorTypeG, byte ColorTypeB);
	void set_rect(short LeftBottomX, short LeftBottomY, short RightTopX, short RightTopY, COLORREF ColorType);
	void draw_rect();
};
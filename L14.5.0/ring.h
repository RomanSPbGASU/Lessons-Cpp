#include <Windows.h>

class ring
{
protected:
	COORD ringcenter;
	short ringradius;
	int ringlinestyle;
	int ringlinewidth;
	COLORREF ringcolor;
public:
	ring();
	ring(COORD center, short radius, int linestyle, int linewidth, COLORREF color);
	void set_ring(COORD center, short radius, int linestyle, int linewidth, COLORREF color);
	void draw_ring();
};


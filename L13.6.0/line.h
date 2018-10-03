#include <Windows.h>
#include <iostream>
using namespace std;

class line
{
private:
	struct ends
	{
		COORD alpha;
		COORD omega;
	};
	ends lineends;
	COLORREF color;
	int penstyle;
	int width;
public:
	line();
	line(COORD startpoint, COORD endpoint, COLORREF linecolor, int linestyle, int linewidth);
	void set_line(COORD startpoint, COORD endpoint, COLORREF linecolor, int linestyle, int linewidth);
	void draw_line();
};
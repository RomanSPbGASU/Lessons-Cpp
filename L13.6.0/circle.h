#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

class circle
{
private:
	COORD center;
	int radius;
	COLORREF color;
public:
	circle();
	circle(COORD ce, int ra, COLORREF co);
	void set_circle(COORD circlecenter, int rad, COLORREF circlecolor);
	void draw_circle();
};

COORD SymbToPix(COORD Symb);
COORD PixToSymb(COORD Pix);
short PixToSymbX(short x);
short PixToSymbY(short y);
void PrintInCoord(COORD coordinates, char *text);
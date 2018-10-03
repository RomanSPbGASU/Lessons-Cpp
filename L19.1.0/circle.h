#pragma once
#include "shape.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

class circle : public shape
{
private:
	int radius;
public:
	circle();
	circle(COORD ce, COLORREF co, int ra);
	void set(COORD circlecenter, COLORREF circlecolor,  int rad);
	void draw();
};

COORD SymbToPix(COORD Symb);
COORD PixToSymb(COORD Pix);
short PixToSymbX(short x);
short PixToSymbY(short y);
void PrintInCoord(COORD coordinates, char *text);
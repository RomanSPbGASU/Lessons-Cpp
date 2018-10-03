#pragma once
#include <Windows.h>

class shape
{
protected:
	COORD point;
	COLORREF color_type;
public:
	shape();
	shape(COORD, COLORREF);
};

int _fullscreen();
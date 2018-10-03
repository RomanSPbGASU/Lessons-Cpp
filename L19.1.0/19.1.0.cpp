#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "rhombus.h"
#include "shape.h"
#include "triangle.h"
#include "polygon.h"

void main()
{
	_fullscreen();
	shape *ptrshape[6];										// массив указателей на базовый класс

	circle circle1;
	ptrshape[0] = &circle1;									// инициализировали указатель адресом объекта
	ellipse ellipse1({ 700,750 }, RGB(0,255,0), 200, 100);
	ptrshape[1] = &ellipse1;
	polygon polygon1({ 350, 600 }, RGB(200, 0, 200), 200, 5);
	ptrshape[2] = &polygon1;
	rectangle rectangle1({ 700,500 }, RGB(100, 100, 100), { 200,200 });
	ptrshape[3] = &rectangle1;
	rhombus rhombus1({ 400, 200 }, RGB(255,255,0), 200, 400);
	ptrshape[4] = &rhombus1;
	triangle triangle1({ 350, 650 }, RGB(0, 255, 255), { 450, 450 }, { 650, 550 });
	ptrshape[5] = &triangle1;

	for (int i = 0; i < 5; i++) ptrshape[i]->draw();
	cin.get();
}
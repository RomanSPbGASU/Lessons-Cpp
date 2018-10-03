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
	circle circle1;
	circle1.draw_circle();
	ellipse ellipse1({ 700,750 }, RGB(0,255,0), 200, 100);
	ellipse1.draw_ellipse();
	polygon polygon1({ 350, 600 }, RGB(200, 0, 200), 200, 5);
	polygon1.draw_polygon();
	rectangle rectangle1({ 700,500 }, RGB(100, 100, 100), { 200,200 });
	rectangle1.draw_rectangle();
	rhombus rhombus1({ 400, 200 }, RGB(255,255,0), 200, 400);
	rhombus1.draw_rhombus();
	triangle triangle1({ 350, 650 }, RGB(0, 255, 255), { 450, 450 }, { 650, 550 });
	triangle1.draw_triangle();
	cin.get();
}
#include <Windows.h>
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
	head = NULL;
}
Stack::~Stack()
{
	while (head)
	{
		remove();
	}
}
void Stack::add(COORD centre, int radius, COLORREF color)
{
	link*newlink = new link;
	newlink->Circle.set_circle(centre, radius, color);
	newlink->next = head;
	head = newlink;
}
void Stack::remove()
{
		link *newfirst = head -> next;
		delete head;
		head = newfirst;
}
void Stack::display()
{
	link * current = head;
	while (current)
	{
		link * newfirst = current->next;
		current->Circle.draw_circle();
		current = newfirst;
	}
}



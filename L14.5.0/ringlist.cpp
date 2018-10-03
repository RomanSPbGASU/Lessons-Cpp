#include <Windows.h>
#include "ringlist.h"

ringlist::ringlist() 
{
	head = NULL;
}
ringlist::~ringlist()
{
	while (head)
	{
		remove();
	}
}
void ringlist::add(COORD center, short radius, int linestyle, int linewidth, COLORREF color)
{
	link*newlink = new link;
	newlink->Ring.set_ring(center, radius, linestyle, linewidth, color);
	newlink->next = head;
	head = newlink;
}
void ringlist::remove()
{
	link *newfirst = head->next;
	delete head;
	head = newfirst;
}
void ringlist::display()
{
	link * current = head;
	while (current)
	{
		link * newfirst = current->next;
		current->Ring.draw_ring();
		current = newfirst;
	}
}
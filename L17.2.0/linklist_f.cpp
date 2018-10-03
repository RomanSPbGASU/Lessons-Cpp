#include "linklist_f.h"

linklist_f::~linklist_f()
{
	while (first)
	{
		link *newfirst = first->next;
		cout << "Элемент " << first->data << " удален" << endl;
		delete first;
		first = newfirst;
	}
}
void linklist_f::additem(int d) // смотрел здесь http://blog.kislenko.net/show.php?id=1276
{
	link * newlink = new link;
	newlink->data = d;
	newlink->next = NULL;

	link * lastitem = NULL;
	if (first != NULL)
	{
		lastitem = first;
		while (lastitem->next != NULL) lastitem = lastitem->next;
		lastitem->next = newlink;
	}
	else first = newlink;
}

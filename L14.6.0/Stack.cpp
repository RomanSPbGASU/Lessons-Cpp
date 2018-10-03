#include <Windows.h>
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

void Stack::add(char * name, char * type, int amount, float price) //push
{
	link * newlink = new link;
	newlink->Stock.set_investment(name, type, amount, price);
	newlink->next = head;
	head = newlink;
}

void Stack::remove() //pop2
{
	link *newfirst = head->next;
	delete head;
	head = newfirst;
}
void Stack::display() const
{
	link * current = head;
	while (current)
	{
		link * newfirst = current->next;
		current->Stock.show_investment();
		current = newfirst;
	}
}
stock Stack::get() const //pop1
{
	stock last(head->Stock.get_name(), head->Stock.get_type(), head->Stock.get_amount(), head->Stock.get_price());
	return last;
}


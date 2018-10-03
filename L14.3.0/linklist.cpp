// делал по этому примеру http://itnotesblog.ru/note.php?id=178
#include <iostream>
#include "linklist.h"
using namespace std;

linklist::linklist()
{
	first = NULL;
}

linklist::~linklist() //ПРАВИЛО ТРЕХ - если создается деструктор, то должен быть конструктор копирования и оператор присваивания копированием?
{					  //ПРАВИЛО ПЯТИ -~- конструктор перемещения, оператор присваивания перемещением
	while (first)
	{
		link *newfirst = first->next;
		cout << "Элемент " << first->data << " удален" << endl;
		delete first;
		first = newfirst;
	}
}

void linklist::additem(int d)
{
	link*newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}

void linklist::display()
{
	link* current = first;
	while (current)
	{
		cout << current->data << endl;
		current = current->next;
	}
}
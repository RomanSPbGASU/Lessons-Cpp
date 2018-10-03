// ����� �� ����� ������� http://itnotesblog.ru/note.php?id=178
#include <iostream>
#include "linklist.h"
using namespace std;

linklist::linklist()
{
	first = NULL;
}

linklist::~linklist() //������� ���� - ���� ��������� ����������, �� ������ ���� ����������� ����������� � �������� ������������ ������������?
{					  //������� ���� -~- ����������� �����������, �������� ������������ ������������
	while (first)
	{
		link *newfirst = first->next;
		cout << "������� " << first->data << " ������" << endl;
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
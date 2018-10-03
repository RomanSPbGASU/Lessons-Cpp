#include <iostream>
#include <Windows.h>
#include "linklist_f.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	linklist l1;
	linklist_f l2;

	l1.additem(25);	l2.additem(25);
	l1.additem(36);	l2.additem(36);
	l1.additem(49);	l2.additem(49);
	l1.additem(64);	l2.additem(64);

	l1.display();	l2.display();

	l2.~linklist_f();
	l1.~linklist();

	// применение обоих методов additem() (базового и производного классов)
	// к объекту производного класса

	linklist_f l3;

	l3.additem(3);
	l3.additem(2);
	l3.additem(1);

	l3.linklist::additem(4);
	l3.linklist::additem(5);
	l3.linklist::additem(6);

	l3.display();

	l3.~linklist_f();

	cin.get();
}
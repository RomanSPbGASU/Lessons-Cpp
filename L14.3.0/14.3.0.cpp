#include <iostream>
#include <Windows.h> //��� �� ���������� ���� ������������ ���� ���� ����� �������?
#include "linklist.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	linklist list;

	list.additem(25);
	list.additem(36);
	list.additem(49);
	list.additem(64);

	list.display();

	list.~linklist(); // ���� �������� ����������. ��� ����� �� ��� ����� ���������� ��� �������� ����.

	cin.get();
}
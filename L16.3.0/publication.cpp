#include "publication.h"

void publication::getdata()
{
	cout << "������� ���������: "; cin >> title;
	cout << "������� ����: "; cin >> price; 
}
void publication::putdata()
{
	cout << "���������: " << title << endl;
	cout << "����: " << price << endl;
}
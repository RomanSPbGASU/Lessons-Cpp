#include "book.h"

void book::getdata()
{
	publication::getdata();
	cout << "������� ����� �������: "; cin >> pages;
	sales::getdata();
}
void book::putdata()
{
	publication::putdata();
	cout << "�������: " << pages << endl;
	sales::putdata();
}
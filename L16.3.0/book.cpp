#include "book.h"

void book::getdata()
{
	publication::getdata();
	cout << "������� ����� �������: "; cin >> pages; cout << "\n";
}
void book::putdata()
{
	publication::putdata();
	cout << "�������: " << pages << endl;
}
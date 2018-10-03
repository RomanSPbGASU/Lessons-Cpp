#include "book.h"

void book::getdata()
{
	publication::getdata();
	cout << "Введите число страниц: "; cin >> pages;
	sales::getdata();
}
void book::putdata()
{
	publication::putdata();
	cout << "Страниц: " << pages << endl;
	sales::putdata();
}
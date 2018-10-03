#include "book.h"

void book::getdata()
{
	publication::getdata();
	cout << "Введите число страниц: "; cin >> pages; cout << "\n";
}
void book::putdata()
{
	publication::putdata();
	cout << "Страниц: " << pages << endl;
}
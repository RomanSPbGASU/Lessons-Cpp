#include "publication.h"

void publication::getdata()
{
	cout << "Введите заголовок: "; cin >> title;
	cout << "Введите цену: "; cin >> price; 
}
void publication::putdata()
{
	cout << "Заголовок: " << title << endl;
	cout << "Цена: " << price << endl;
}
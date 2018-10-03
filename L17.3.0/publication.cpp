#include "publication.h"

void publication::getdata()
{
	cout << "Введите заголовок: ";
	title[0] = NULL;					// как сделать ввод из нескольких слов по-нормальному?
	cin.getline(title, MAX); 
	if (strlen(title) == 0) 
	{
		cin.ignore(0, 1);
		cin.getline(title, MAX);
	}
	cout << "Введите цену: "; cin >> price; 
}
void publication::putdata()
{
	cout << "Заголовок: " << title << endl;
	cout << "Цена: " << price << endl;
}
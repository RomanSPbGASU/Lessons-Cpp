#include "nameslist.h"

nameslist::nameslist()
{
	first = NULL;
}

int nameslist::all_names(char* filename)
{
	fstream myfile(filename, ios::in);
	int count = 0;
	names *next;
	while (1)
	{
		next = first;
		first = new names;							// выделение памяти под новый элемент
		myfile >> first->REGN;						// считывание регистрационного номера
		myfile.get();								// считывание разделителя (чтобы убрать его из потока)
		getline(myfile, first->NAME_B);				// считывание названия банка
		first->next = next;
		if (!myfile)
		{
			first = first->next;
			break;
		}
		count++;
	}
	return count;
}

void nameslist::display()
{
	names *current = first;
	while (current)
	{
		cout << current->REGN << " " << current->NAME_B << endl;
		current = current->next;
	}
}

string nameslist::get_single(int number)
{
	names * current = first;
	while (current->REGN != number)
	{
		current = current->next;
		if (current->next == NULL)
		{
			cout << "Ошибка. Банк не найден" << endl;
			return "\0";
		}
	}
	return current->NAME_B;
}

nameslist::~nameslist()
{
	names* current = first;							// установить указатель на первый элемент
	while (current != 0)							// выход по достижении последнего элемента
	{
		names* temp = current;						// сохранить указатель на данный элемент
		current = current->next;					// получить ссылку на следующий элемент
		delete temp;								// удалить текущий элемент
	}
	cout << "Удаление записей таблицы NAMES" << endl;
}
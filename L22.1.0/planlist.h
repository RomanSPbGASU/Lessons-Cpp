#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class planlist
{
private:
	struct plan
	{
		string PLAN, NUM_SC, NAME;
		plan * next;
	} *first;
public:
	planlist();
	int all_names(char* filename);			// создает список
	void display();							// вывод списка на экран
	string get_single(string NUM_SC);	// вовзвращает и выводит на экран наименование денежного счёта (NAME)
	~planlist();
};

planlist::planlist()
{
	first = NULL;
}

int planlist::all_names(char* filename)
{
	fstream myfile(filename, ios::in);
	int count = 0;
	//plan *next;
	while (1)
	{
		next = first;
		first = new plan;							// выделение памяти под новый элемент
		getline(myfile, first->PLAN, ';');			// считывание буквенного обозначения плана
		getline(myfile, first->NUM_SC, ';');		// считывание номера счёта
		getline(myfile, first->NAME);				// считывание названия плана
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

void planlist::display()
{
	plan *current = first;
	while (current)
	{
		cout << current->PLAN << " " << setw(5) << left << current->NUM_SC << " " << current->NAME << endl;
		current = current->next;
	}
}
string planlist::get_single(string number)
{
	plan * current = first;
	while (current->NUM_SC != number)
	{
		current = current->next;
		if (current->next == NULL)
		{
			cout << "Ошибка. План не найден" << endl;
			return "\0";
		}
	}
	return current->NAME;
}

planlist::~planlist()
{
	plan* current = first;							// установить указатель на первый элемент
	while (current != NULL)						// выход по достижении последнего элемента
	{
		plan* temp = current;						// сохранить указатель на данный элемент
		current = current->next;					// получить ссылку на следующий элемент
		delete temp;								// удалить текущий элемент
	}
	cout << "Удаление записей таблицы PLAN" << endl;
}
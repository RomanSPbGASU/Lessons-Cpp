#pragma once
#include <Windows.h>

template<class Type>											// класс linklist<Type>
class linklist													// связанный список (внутри этого класса Linklist означает linklist<Type>)
{
private:
	template<class Type>										// структура link<Type>
	struct link													// элемент списка (внутри этой структуры определение link означает link<Type>)
	{
		Type data;												// элемент данных
		link* next;												// указатель на следующий элемент
	}; 
	link<Type> *first;											// указатель на начало списка
public:
	linklist();													// конструктор без аргументов
	void additem(Type d);										// добавить один элемент списка
	void display();												// вывести весь список
};


template<class Type>
linklist<Type>::linklist()
{
	first = NULL;												// список пуст
}

template<class Type>
void linklist<Type>::additem(Type d)							// добавление данных
{
	if (first == NULL)											// если первый элемент отсутствует
	{
		first = new link<Type>;									// выделяем память под первый элемент
		first->data = d;										// сохраняем данные в первом элементе
		first->next = NULL;										// ссылка на следующий элемент равна NULL
	}
	else														// если первый элемент создан
	{
		link<Type> *current = first;							// текущий элемент - первый
		while (current->next != NULL) current = current->next;	// доходим до последнего элемента
		current->next = new link<Type>;							// выделяем память под новый элемент (следующий за последним)
		current->next->data = d;								// сохраняем данные в новый элемент
		current->next->next = NULL;								// ссылка на следующий элемент равна NULL
	}
}

template<class Type>
void linklist<Type>::display()									// вывод всего списка
{
	link<Type>* current = first;								// указатель - на начало списка
	while (current != NULL)										// пройти весь список
	{
		cout << current->data << endl;							// вывести на экран данные
		current = current->next;								// перейти к следующему элементу
	}
}
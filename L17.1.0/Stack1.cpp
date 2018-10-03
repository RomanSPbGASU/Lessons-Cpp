#include "Stack1.h"

void Stack1::put(int var)
{
	if (top >= MAX - 1)	// если стек полон, то ошибка
	{
		cout << "Ошибка: стек полон" << endl; exit(1);
	}
	Stack::put(var);	// вызов функции put класса Stack
}
int Stack1::pop()		// извлечение числа из стека
{
	if (top < 0)		// если стек пуст, то ошибка
	{
		cout << "Ошибка: стек пуст\n"; exit(1);
	}
	Stack::pop();	// вызов функции pop класса Stack(можно без return)
}
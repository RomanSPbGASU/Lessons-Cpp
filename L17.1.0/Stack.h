#pragma once
// перегрузка функций базового и производного классов
#include <iostream>
#include <Windows.h>
using namespace std;
#include <process.h>		 // для exit()

class Stack
{
protected:					// Замечание: использовать private нельзя
	enum { MAX = 4 };		// размер стека
	int st[MAX];			// данные, хранящиеся в стеке
	int top;				// индекс последнего элемента в стеке
public:
	Stack();				// конструктор
	void put(int);			// помещение числа в стек
	int pop();				// извлечение числа из стека

};
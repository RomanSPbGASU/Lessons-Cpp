#pragma once
#include "Stack.h"

class Stack1 : public Stack
{
public:
	void put(int); // помещение числа в стек
	int pop();	// извлечение числа из стека
};

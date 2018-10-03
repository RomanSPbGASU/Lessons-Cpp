#include "Stack2.h"

void Stack2::put(COORD coord)
{
	Stack1::put(coord.X);
	Stack1::put(coord.Y);
	cout << "“очка с координатами ( " << coord.X << ", " << coord.Y << ") помещена в стек" << endl;
}

void Stack2::pop()
{
	COORD coord = { Stack1::pop(), Stack1::pop() };
	cout << "“очка с координатами ( " << coord.Y << ", " << coord.X << ") извлечена из стека" << endl;
}
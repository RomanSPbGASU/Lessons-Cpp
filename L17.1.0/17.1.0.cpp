#include "Stack2.h"

int main()
{
	SetConsoleOutputCP(1251);
	Stack2 s2;	// сздание объекта s1 производного класса Stack1

	COORD point1 = { 1, 2 }, point2 = { 3, 4 };
	s2.put(point1);
	s2.put(point2);
	s2.pop();
	s2.pop();

	s2.put(point1);
	s2.put(point2);
	s2.put(point1);
	
	s2.pop();

	system("pause");
}
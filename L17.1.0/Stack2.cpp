#include "Stack2.h"

void Stack2::put(COORD coord)
{
	Stack1::put(coord.X);
	Stack1::put(coord.Y);
	cout << "����� � ������������ ( " << coord.X << ", " << coord.Y << ") �������� � ����" << endl;
}

void Stack2::pop()
{
	COORD coord = { Stack1::pop(), Stack1::pop() };
	cout << "����� � ������������ ( " << coord.Y << ", " << coord.X << ") ��������� �� �����" << endl;
}
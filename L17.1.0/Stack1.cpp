#include "Stack1.h"

void Stack1::put(int var)
{
	if (top >= MAX - 1)	// ���� ���� �����, �� ������
	{
		cout << "������: ���� �����" << endl; exit(1);
	}
	Stack::put(var);	// ����� ������� put ������ Stack
}
int Stack1::pop()		// ���������� ����� �� �����
{
	if (top < 0)		// ���� ���� ����, �� ������
	{
		cout << "������: ���� ����\n"; exit(1);
	}
	Stack::pop();	// ����� ������� pop ������ Stack(����� ��� return)
}
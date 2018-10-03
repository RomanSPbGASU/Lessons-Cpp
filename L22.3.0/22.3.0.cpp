#include <iostream>
#include <Windows.h>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	stack<COORD> COORDstack;
	COORD COORDmas[] = { {rand(),rand()}, {rand(),rand()}, {rand(),rand()}, {rand(),rand()} };
	for(int i = 0; i < 4; i++) 
	{ 
		COORDstack.push(COORDmas[i]);
		cout << "����� � ������������ (" << COORDstack.top().X << ", " << COORDstack.top().Y <<  ") �������� � ����" << endl;
	}

	cout << "� ���������� ��������� " << COORDstack.size() << " ��������" << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "����� � ������������ (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") ��������� �� �����" << endl;
		COORDstack.pop();
	}

	cout << "� ���������� ��������� " << COORDstack.size() << " ��������" << endl;

	for (int i = 0; i < 4; i++)
	{
		COORDstack.push(COORDmas[i]);
		cout << "����� � ������������ (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") �������� � ����" << endl;
	}

	cout << "� ���������� ��������� " << COORDstack.size() << " ��������" << endl;

	while(COORDstack.size() != 0)
	{
		cout << "����� � ������������ (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") ��������� �� �����" << endl;
		COORDstack.pop();
	}

	cout << "� ���������� ��������� " << COORDstack.size() << " ��������" << endl;
}
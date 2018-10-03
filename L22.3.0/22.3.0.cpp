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
		cout << "Точка с координатами (" << COORDstack.top().X << ", " << COORDstack.top().Y <<  ") помещена в стек" << endl;
	}

	cout << "В контейнене находится " << COORDstack.size() << " элемента" << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Точка с координатами (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") извлечена из стека" << endl;
		COORDstack.pop();
	}

	cout << "В контейнене находится " << COORDstack.size() << " элемента" << endl;

	for (int i = 0; i < 4; i++)
	{
		COORDstack.push(COORDmas[i]);
		cout << "Точка с координатами (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") помещена в стек" << endl;
	}

	cout << "В контейнене находится " << COORDstack.size() << " элемента" << endl;

	while(COORDstack.size() != 0)
	{
		cout << "Точка с координатами (" << COORDstack.top().X << ", " << COORDstack.top().Y << ") извлечена из стека" << endl;
		COORDstack.pop();
	}

	cout << "В контейнене находится " << COORDstack.size() << " элемента" << endl;
}
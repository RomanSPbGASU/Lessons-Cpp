// Шаблон связных списков
#include <Windows.h>
#include <fstream>
#include "Distance.h"
#include "linklist.h"
#include "employee.h"

int main()
{
	SetConsoleOutputCP(1251);

	linklist<employee> list_empl;				// объект linklist<employee>
	employee empl;								// объявили объект employee

	fstream myfile("list.txt", ios::in);		// считали в поток содержимое файла list.txt

	while (myfile)
	{
		myfile >> empl;
		if (!myfile) break;
		list_empl.additem(empl);
	}

	cout << "Список сотрудников из файла list.txt" << endl << endl;
	list_empl.display();

	system("pause");
}
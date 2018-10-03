// ������ ������� �������
#include <Windows.h>
#include <fstream>
#include "Distance.h"
#include "linklist.h"
#include "employee.h"

int main()
{
	SetConsoleOutputCP(1251);

	linklist<employee> list_empl;				// ������ linklist<employee>
	employee empl;								// �������� ������ employee

	fstream myfile("list.txt", ios::in);		// ������� � ����� ���������� ����� list.txt

	while (myfile)
	{
		myfile >> empl;
		if (!myfile) break;
		list_empl.additem(empl);
	}

	cout << "������ ����������� �� ����� list.txt" << endl << endl;
	list_empl.display();

	system("pause");
}
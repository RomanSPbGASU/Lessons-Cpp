// ничему не научился из этого задания(
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class person
{
protected:
	string name;
	float salary;
public:
	void setData()
	{
		cout << "Введите имя: "; cin >> name;
		cout << "Введите оклад (руб.): "; cin >> salary;
	}
	void printData()
	{
		cout << endl << name << " - " << salary << " руб.";
	}
	float getSalary()
	{
		return salary;
	}
};

int main()
{
	system("chcp 1251 > nul");
	void bsort(person**, int);

	int n;
	cout << "Введите количество работников: ";
	cin >> n;
	person** persPtr = new person*[n];
	for (int i = 0; i < n; i++)
	{
		persPtr[i] = new person;
		persPtr[i]->setData();
	}

	cout << "\nНеотсортирвоанный список:";
	for (int j = 0; j < n; j++)
		persPtr[j]->printData();

	bsort(persPtr, n);

	cout << "\n\nОтсортированный список:";
	for (int j = 0; j < n; j++)
		persPtr[j]->printData();
	cout << endl;
	_getche();
}

void bsort(person** pp, int n)
{
	void order(person**, person**);
	for (int j = 0; j < n - 1; j++)
		for (int k = j + 1; k < n; k++)
			order(pp + j, pp + k);
}

void order(person** pp1, person** pp2)
{
	if ((*pp1)->getSalary() > (*pp2)->getSalary())
	{
		person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
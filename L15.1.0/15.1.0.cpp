#include "fraction.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	char decision = 13;
	do
	{
		int a = 0, b = 0, c = 0, d = 0;
		char operation, garbage;
		cout << "\nВведите операцию в виде a/b + c/d: ";
		cin >> a >> garbage >> b >> operation >> c >> garbage >> d;
		if (cin.fail())
		{
			cin.clear();					//НЕ ДО КОНЦА ПОНИМАЮ ЭТО
			cin.ignore(INT_MAX, '\n');      //оператор ввода игнорирует следующие (максимальное число int) символов после 
			cout << "Некорректный ввод";	//символа перевода строки
		}
		else
		{
			fraction fract1(a, b);
			fraction fract2(c, d);
			fraction result;
			if (operation == '+') { result = fract1 + fract2; }
			if (operation == '-') { result = fract1 - fract2; }
			if (operation == '*') { result = fract1 * fract2; }
			if (operation == '/') { result = fract1 / fract2; }
			result.reduction2();
			result.print();
		}
	} while (decision != 27);

	system("pause");
}
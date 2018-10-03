#include "fraction_full.h"
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
		char operation, slash;
		bool failed = true;
		cout << "\nВведите операцию в виде a/b + c/d или a/b ^ n: ";
		cin >> a;
		cin >> slash; if (slash == '/') failed = 0;
		cin >> b;
		cin >> operation; if (operation == ('+' || '-' || '*' || '/' || '>' || '<' || '!=' || '==' || '^')) failed = 0;
		if (operation == '^')
		{
			cin >> c;
		}
		else
		{
			cin >> c;
			cin >> slash; if (slash == '/') failed = 0;
			cin >> d;
		}
			if (cin.fail() || failed == 1)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Некорректный ввод";
		}
		else
		{
			fraction_full fract1(a, b);
			fraction_full fract2(c, d);
			if (operation == '+') { auto result = fract1 + fract2; result.reduction2(); result.print(); }
			if (operation == '-') { auto result = fract1 - fract2; result.reduction2(); result.print(); }
			if (operation == '*') { auto result = fract1 * fract2; result.reduction2(); result.print(); }
			if (operation == '/') { auto result = fract1 / fract2; result.reduction2(); result.print(); }
			if (operation == '>') { bool result = fract1 > fract2; cout << (result ? "true" : "false"); } // когда писал cout << result ? "true" : "false" (без скобок), выводил 0 или 1
			if (operation == '<') { bool result = fract1 < fract2; cout << (result ? "true" : "false"); }
			if (operation == '==') { bool result = fract1 == fract2; cout << (result ? "true" : "false"); }
			if (operation == '!=') { bool result = fract1 != fract2; cout << (result ? "true" : "false"); }
			if (operation == '^') {	auto result = fract1 ^ c; result.reduction2(); result.print(); }
		}
	} while (decision != 27);

	system("pause");
}
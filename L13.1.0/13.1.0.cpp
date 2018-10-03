#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class fraction
{
private:
	int P;
	unsigned int Q;
public:
	fraction() : P(0), Q(0)
	{}
	fraction(int p, unsigned int q) : P(p), Q(q)
	{}
	void print()
	{
		cout << " = " << P << "/" << Q;
	}
	void addition(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q + fraction2.P * fraction1.Q;
		Q = fraction1.Q * fraction2.Q;
	}
	void substraction(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q - fraction2.P * fraction1.Q;
		Q = fraction1.Q * fraction2.Q;
	}
	void multiplication(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.P;
		Q = fraction1.Q * fraction2.Q;
	}
	void division(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q;
		Q = fraction1.Q * fraction2.P;
	}
	void reduction()
	{
		if (P >= 0)
		{
			if (Q % P == 0) { Q = Q / P;  P = 1; }
			else
			{
				int n = (Q > P ? Q : P);
				for (int i = n; i > 0; i--)
				{
					if ((P % i == 0) & (Q % i == 0)) { Q = Q / i; P = P / i; }
				}
			}
		}
		else
		{
			if (Q % -P == 0) { Q = Q / -P;  P = -1; }
			else
			{
				int n = (Q > -P ? Q : -P);
				for (int i = n; i > 0; i--)
				{
					if ((-P % i == 0) & (Q % i == 0)) { Q = Q / i; P = P / i; }
				}
			}
		}
	}
};

void main()
{
	SetConsoleOutputCP(1251);
	char decision = 13;
	do
	{
		int a = 0, b = 0, c = 0, d = 0;
		char operation, garbage;
		bool flag;
		cout << "\nВведите операцию в виде a/b + c/d: ";
		decision = _getche();
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
			if (operation == '+') { result.addition(fract1, fract2); }
			if (operation == '-') { result.substraction(fract1, fract2); }
			if (operation == '*') { result.multiplication(fract1, fract2); }
			if (operation == '/') { result.division(fract1, fract2); }
			result.reduction();
			result.print();
		}
	} while (decision != 27);

	_getche();
}
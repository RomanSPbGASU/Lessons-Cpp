#include "fraction.h"
#include <iostream>

using namespace std;

fraction::fraction() : P(0), Q(0)
{}
fraction::fraction(int p, unsigned int q) : P(p), Q(q)
{}
void fraction::print()
{
	cout << " = " << P << "/" << Q;
}

fraction fraction::operator + (const fraction fraction2) const
{
	return (fraction(P * fraction2.Q + fraction2.P * Q, Q * fraction2.Q));
}

fraction fraction:: operator - (const fraction fraction2) const
{
	return (fraction(P * fraction2.Q - fraction2.P * Q, Q * fraction2.Q));
}

fraction fraction:: operator * (const fraction fraction2) const
{
	return (fraction(P * fraction2.P, Q * fraction2.Q));
}

fraction fraction:: operator / (const fraction fraction2) const
{
	return (fraction(P * fraction2.Q, Q * fraction2.P));
}

void fraction::reduction()  //это мой способ
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
int fraction::gcd(const int P, const int Q) { return P ? gcd(Q % P, P) : Q; }  //это алгоритм Евклида (Штейна) в виде рекурсии
void fraction::reduction2()
{
	int p = P, q = Q;
	Q /= abs(gcd(p, q));
	P >= 0 ? P /= gcd(p, q) : P /= -gcd(p, q);
}

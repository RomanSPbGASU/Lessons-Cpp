#include "fraction_full.h"

fraction_full::fraction_full() : fraction()
{}
fraction_full::fraction_full(int p, unsigned int q) : fraction(p, q)
{}
fraction_full fraction_full::operator ^ (unsigned int exp)
{
	P = pow(P, exp);
	Q = pow(Q, exp);
	return fraction_full(P, Q);
}
bool fraction_full::operator == (const fraction_full fraction2) const
{
	int f1 = P * fraction2.Q; int f2 = fraction2.P * Q;
	return f1 == f2 ? true : false;
}
bool fraction_full::operator != (const fraction_full fraction2) const
{
	int f1 = P * fraction2.Q; int f2 = fraction2.P * Q;
	return f1 == f2 ? false : true;
}
bool fraction_full::operator > (const fraction_full fraction2) const
{
	int f1 = P * fraction2.Q; int f2 = fraction2.P * Q;
	return f1 > f2 ? true : false;
}
bool fraction_full::operator < (const fraction_full fraction2) const
{
	int f1 = P * fraction2.Q; int f2 = fraction2.P * Q;
	return f1 < f2 ? true : false;
}
#include "Distance.h"

Distance::Distance() : meters(0), centimeters(0.0)
{}

Distance::Distance(int met, float cent): meters(met), centimeters(cent)
{}

Distance::Distance(float fmet)
{
	meters = (int)fmet;
	centimeters = (fmet - (float)meters) * 100;
}

Distance operator + (Distance d1, Distance d2)
{
	int met = d1.meters + d2.meters;
	float cent = d1.centimeters + d2.centimeters;						// сложение сантиметров
	if (cent >= 100.)
	{
		cent -= 100.;
		met++;
	}
	return Distance(met, cent);
}

ostream& operator << (ostream& os, const Distance& d)
{
	os << d.meters << " м " << fixed << setprecision(2) << d.centimeters << " см ";
	return os;
}

istream& operator >> (istream& is, Distance& d)
{
	cout << endl << "Введите число метров: "; is >> d.meters;
	cout << endl << "Введите число сантиметров: "; is >> d.centimeters;
	return is;
}
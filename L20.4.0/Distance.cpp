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
	float cent = d1.centimeters + d2.centimeters;						// �������� �����������
	if (cent >= 100.)
	{
		cent -= 100.;
		met++;
	}
	return Distance(met, cent);
}

ostream& operator << (ostream& os, const Distance& d)
{
	os << d.meters << " � " << fixed << setprecision(2) << d.centimeters << " �� ";
	return os;
}

istream& operator >> (istream& is, Distance& d)
{
	cout << endl << "������� ����� ������: "; is >> d.meters;
	cout << endl << "������� ����� �����������: "; is >> d.centimeters;
	return is;
}
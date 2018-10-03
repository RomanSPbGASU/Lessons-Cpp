#include "Distance.h"

Distance::Distance() : meters(0), centimeters(0.0) // ����������� ��� ����������
{}
Distance::Distance(int met, float cent) : meters(met), centimeters(cent) // ����������� � ����� �����������
{}
void Distance::get_dist() // ���� ����� � ����������
{
	cout << "\n������� ����� ������: "; cin >> meters;
	cout << "\n������� ����� �����������: "; cin >> centimeters;
}
void Distance::show_dist() // ����� ����� �� �����
{
	cout << meters << " � " << centimeters << " �� ";
}
Distance Distance::operator + (const Distance d2) const
{
	int met = meters + d2.meters;
	float cent = centimeters + d2.centimeters; // �������� �����������
	if (cent >= 100.)
	{
		cent -= 100.;
		met++;
	}
	return Distance(met, cent);
}
Distance Distance::operator - (const Distance d2) const
{
	int met = meters - d2.meters;
	float cent = centimeters - d2.centimeters; // ��������� �����������
	if (met + cent / 100 < 0) cout << " dist1 ������ ��� dist2";
	else
	{
		if (cent < 0.)
		{
			cent += 100.;
			met--;
		}
		return Distance(met, cent);
	}
}
Distance Distance::operator * (const Distance d2) const
{
	float bd1 = meters + centimeters / 100;
	float bd2 = d2.meters + d2.centimeters / 100;
	int met = bd1 * bd2;
	float cent = bd1 * bd2 - met;
	return Distance(met, cent);
}
Distance Distance::operator += (const Distance d2)
{
	meters += d2.meters; // �������� ������
	centimeters += d2.centimeters; // �������� �����������
	if (centimeters >= 100.)
	{
		centimeters -= 100.;
		meters++;
	}
	return Distance(meters, centimeters);
}
bool Distance::operator < (const Distance d2) const
{
	float bd1 = meters + centimeters / 100;
	float bd2 = d2.meters + d2.centimeters / 100;
	return (bd1 < bd2) ? true : false;
}
bool Distance::operator > (const Distance d2) const
{
	float bd1 = meters + centimeters / 100;
	float bd2 = d2.meters + d2.centimeters / 100;
	return (bd1 > bd2) ? true : false;
}
bool Distance::operator == (const Distance d2) const
{
	float bd1 = meters + centimeters / 100;
	float bd2 = meters + centimeters / 100;
	return (bd1 == bd2) ? true : false;
}
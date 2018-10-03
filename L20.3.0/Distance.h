#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Distance
{
private:
	int meters;
	float centimeters;
public:
	Distance();													// ����������� ��� ����������
	Distance(int, float);										// ����������� � ����� �����������
	Distance(float fmet);										// ����������� �������� float � Distance
	friend Distance operator + (Distance, Distance);			// �������� ���� ����
	friend ostream& operator << (ostream&, const Distance&);
	friend istream& operator >> (istream&, Distance&);
};
#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Distance // ����������� ������
{
private:
	int meters;
	float centimeters;
public:
	Distance();
	Distance(int, float);
	void set_dist();
	void show_dist();
	Distance operator + (const Distance) const;
	Distance operator - (const Distance) const;
	Distance operator * (const Distance) const;
	bool operator < (const Distance) const; // ��������� ���� ����
	bool operator > (const Distance) const; // ��������� ���� ����
	bool operator == (const Distance) const; // ��������� ���� ����
};

#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Distance // определение класса
{
private:
	int meters;
	float centimeters;
public:
	Distance();
	Distance(int, float);
	void get_dist();
	void show_dist();
	Distance operator + (const Distance) const;
	Distance operator - (const Distance) const;
	Distance operator * (const Distance) const;
	Distance operator += (const Distance);
	bool operator < (const Distance) const; // сравнение двух длин
	bool operator > (const Distance) const; // сравнение двух длин
	bool operator == (const Distance) const; // сравнение двух длин
};

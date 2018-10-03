#pragma once
#include <iostream>

using namespace std;

class Distance
{
private:
	int meters;
	float centimeters;
public:
	Distance();													// конструктор без аргументов
	Distance(int, float);										// конструктор с двумя аргументами
	Distance(float fmet);										// конструктор переводт float в Distance
	friend Distance operator + (Distance, Distance);			// сложение двух длин
	friend ostream& operator << (ostream&, const Distance&);
	friend istream& operator >> (istream&, Distance&);
};
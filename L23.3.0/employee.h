#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class employee
{
private:
	int number;
	string surname;
	string name;
	float salary;
public:
	employee(int, string, string, float);
	friend ostream& operator << (ostream&, const employee&);
	friend istream& operator >> (istream&, employee&);
};

employee::employee(int number = 0, string surname = "", string name = "", float salary = 0.0)
	: number(number), surname(surname), name(name), salary(salary)
{
}

ostream& operator << (ostream& os, const employee& e)
{
	cout << setw(3) << left << e.number
		<< setw(15) << left << e.surname
		<< setw(15) << left << e.name
		<< setw(8) << right << fixed << setprecision(2) << e.salary;
	return os;
}

istream& operator >> (istream& is, employee& e)
{
	is >> e.number >> e.surname >> e.name >> e.salary;
	return is;
}
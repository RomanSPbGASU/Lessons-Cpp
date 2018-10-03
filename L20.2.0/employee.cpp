#include "employee.h"

employee::employee() : number(0), surname(""), name(""), salary(0.0)
{}

employee::employee(int number = 0, string surname = "", string name = "", float salary = 0.0)
	: number(number), surname(surname), name(name), salary(salary)
{}


ostream& operator << (ostream& os, const employee& e)
{
	cout << setw(2) << left << e.number
		<< setw(15) << left << e.surname
		<< setw(15) << left << e.name
		<< setw(8) << right << fixed << setprecision(2) << e.salary;
	return os;
}

istream& operator >> (istream& is, employee& e)
{
	is >> e.number;
	is >> e.surname;
	is >> e.name;
	is >> e.salary;
	return is;
}
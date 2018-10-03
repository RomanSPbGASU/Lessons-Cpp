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
	employee();
	employee(int, string, string, float);
	friend ostream& operator << (ostream&, const employee&);
	friend istream& operator >> (istream&, employee&);
};
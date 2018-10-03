#pragma once
//#include <iomanip>
#include <iostream>
using namespace std;

class time
{
private:
	int hrs;
	int mts;
	int sds;
public:
	time();
	time(int, int, int);
	void print() const;
	time operator + (const time) const;
	time operator - (const time) const;
	time operator * (const time) const;
};
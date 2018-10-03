#pragma once
#include <fstream>
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
	time operator + (const time) const;
	time operator - (const time) const;
	time operator * (const time) const;
	friend ostream& operator << (ostream&, const time&);	// смотрел здесь: https://msdn.microsoft.com/ru-ru/library/1z2f6c2k.aspx
};
#pragma once
#include <iostream>
using namespace std;

class publication
{
private:
	static const int MAX = 338;
protected:
	char title[MAX];
	float price;
public:
	void getdata();
	void putdata();
};
#pragma once
#include <iostream>
using namespace std;

class publication
{
protected:
	char title[338];
	float price;
public:
	void getdata();
	void putdata();
};
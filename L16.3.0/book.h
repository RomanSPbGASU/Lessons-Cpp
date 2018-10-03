#pragma once
#include "publication.h"

class book : public publication
{
private:
	int pages;
public:
	void getdata();
	void putdata();
};
#pragma once
#include "publication.h"
#include "sales.h"

class book : public publication, public sales
{
private:
	int pages;
public:
	void getdata();
	void putdata();
};
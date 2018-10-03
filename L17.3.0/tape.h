#pragma once
#include "publication.h"
#include "sales.h"

class tape : publication, sales
{
private:
	float time;
public:
	void getdata();
	void putdata();
};
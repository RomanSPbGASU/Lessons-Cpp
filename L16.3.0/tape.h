#pragma once
#include "publication.h"

class tape : public publication
{
private:
	float time;
public:
	void getdata();
	void putdata();
};
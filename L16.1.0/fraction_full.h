#pragma once
#include "fraction.h"
#include <cmath>

class fraction_full : public fraction
{
public:
	fraction_full();
	fraction_full(int p, unsigned int q);
	fraction_full operator ^ (unsigned int);
	bool operator == (const fraction_full) const;
	bool operator != (const fraction_full) const;
	bool operator > (const fraction_full) const;
	bool operator < (const fraction_full) const;
};
#pragma once
class fraction
{
private:
	int P;
	unsigned int Q;
public:
	fraction();
	fraction(int p, unsigned int q);
	void print();
	fraction operator + (const fraction) const;
	fraction operator - (const fraction) const;
	fraction operator * (const fraction) const;
	fraction operator / (const fraction) const;
	void reduction(); //это мой способ
	int gcd(const int P, const int Q); // алгоритм Евклида (Штейна) в виде рекурсии
	void reduction2();
};

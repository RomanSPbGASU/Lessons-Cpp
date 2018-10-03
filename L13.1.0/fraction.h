class fraction
{
private:
	int P;
	unsigned int Q;
public:
	fraction() : P(0), Q(0)
	{}
	fraction(int p, unsigned int q) : P(p), Q(q)
	{}
	void fraction::print()
	{
		cout << " = " << P << "/" << Q;
	}
	void fraction::addition(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q + fraction2.P * fraction1.Q;
		Q = fraction1.Q * fraction2.Q;
	}
	void fraction::substraction(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q - fraction2.P * fraction1.Q;
		Q = fraction1.Q * fraction2.Q;
	}
	void fraction::multiplication(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.P;
		Q = fraction1.Q * fraction2.Q;
	}
	void fraction::division(fraction fraction1, fraction fraction2)
	{
		P = fraction1.P * fraction2.Q;
		Q = fraction1.Q * fraction2.P;
	}
	void fraction::reduction()  //это мой способ
	{
		if (P >= 0)
		{
			if (Q % P == 0) { Q = Q / P;  P = 1; }
			else
			{
				int n = (Q > P ? Q : P);
				for (int i = n; i > 0; i--)
				{
					if ((P % i == 0) & (Q % i == 0)) { Q = Q / i; P = P / i; }
				}
			}
		}
		else
		{
			if (Q % -P == 0) { Q = Q / -P;  P = -1; }
			else
			{
				int n = (Q > -P ? Q : -P);
				for (int i = n; i > 0; i--)
				{
					if ((-P % i == 0) & (Q % i == 0)) { Q = Q / i; P = P / i; }
				}
			}
		}
	}
	int gcd( const int P, const int Q ) { return P ? gcd( Q % P, P ) : Q; }  //это алгоритм Евклида (Штейна) в виде рекурсии
	void reduction2()
	{
		int p = P, q = Q;
		Q /= abs(gcd(p, q));
		P >= 0 ? P /= gcd(p, q): P /= -gcd( p, q);
	}
};

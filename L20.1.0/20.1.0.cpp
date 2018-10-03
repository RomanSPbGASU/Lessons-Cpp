#include <iostream>

using namespace std;

template <class numeric>
numeric max(numeric[], int);

int main()
{
	int intmas[] = { 1,2,3,4,5 };
	long longmas[] = { 5,1,2,3,4 };
	float floatmas[] = { 5,4,3,2,1 };
	double doublemas[] = { 1,4,5,3,2 };
	char charmas[] = { '1', '3', '4', '5', '2' };

	cout << "max(intmas) = " << max(intmas, 5) << endl;
	cout << "max(longmas) = " << max(longmas, 5) << endl;
	cout << "max(floatmas) = " << max(floatmas, 5) << endl;
	cout << "max(doublemas) = " << max(doublemas, 5) << endl;
	cout << "max(charmas) = " << max(charmas, 5) << endl;		// работает только на числах из одной цифры

	system("pause");
}

template <class numeric>										// шаблон функции
numeric max(numeric mas[], int size)							// определение шаблонной функции
{
	numeric max = mas[0];
	for (int i = 0; i < size; i++)
		if (mas[i] > max) max = mas[i];
	return max;
}


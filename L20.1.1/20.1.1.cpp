#include <iostream>

using namespace std;

template <class num>
num max(num*, int);

int main()
{
	int ia[] = { 10, 11, 12, 13, 14, 15, 16 };
	long la[] = { 10, 11, 12, 13, 14, 15, 16 };
	float fa[] = { 10, 11, 12, 13, 14, 15, 16 };
	double da[] = { 10, 11, 12, 13, 14, 15, 16 };
	char ca[] = { 10, 11, 12, 13, 14, 15, 16 };

	cout << "max(ia) = " << max(ia, 7) << endl;
	cout << "max(la) = " << max(la, 7) << endl;
	cout << "max(fa) = " << max(fa, 7) << endl;
	cout << "max(da) = " << max(da, 7) << endl;
	cout << "max(ca) = " << (int)max(ca, 7) << endl;

	system("pause");
}

template <class num>
num max(num* arr, int size) 
{
	num max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max) max = arr[i];
	return max;
}
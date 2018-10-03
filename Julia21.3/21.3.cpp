#include "21.3h.h"

Time perev(int p)
{
	int hours = p / 3600;
	int mins = (p - 3600 * hours) / 60;
	int secs = p - (60 * mins) - (3600 * hours);
	Time timee(hours, mins, secs);
	return timee;
}
int main()
{
	SetConsoleOutputCP(1251);
	const int max = 4;
	int vr[max] = { -68,-120,-1500,-3602 };

	Time timee[max];

	cout << "Массив данных в секундах:" << endl;
	for (int i = 0;i < max;i++)
		cout << vr[i] << setw(7);
	cout << endl;

	cout << "Массив данных в time:" << endl;
	transform(vr, vr + max, timee,perev);
	for (int i = 0;i < max;i++)
		cout << timee[i] << setw(7);
	cout << endl;
	_getche();
}
#include <algorithm>
#include <windows.h>
#include "time.h"
using namespace std;

Time sec_to_time(int sec)
{
	return Time(sec / 3600, sec % 3600 / 60, sec % 60);
}
int main()
{
	SetConsoleOutputCP(1251);

	Time t1(10, 20, 30), t2(-20,30,-40);	// t2 - это сколько вообще?
	cout << t1 << " " << t2 << endl << endl;




	cout << "Массив данных в сек: " << endl;
	const int max = 5;
	int sec_mas[max];
	//for (int i = 0; i < max; i++)
	//	sec_mas[i] = rand();
	int sec_mas[max] = { -3600, -60, -1, rand() - rand(), rand() - rand() };
	for (int i = 0; i < max; i++)
		cout << sec_mas[i] << "	";
	cout << endl << "Массив данных в time:" << endl;
	Time t[max];
	transform(sec_mas, sec_mas + max, t, sec_to_time);
	//time t[3] = { time(1, 25,46), time(2,15,00), time(0, 56, 59) };
	for (int i = 0; i < max; i++)
		cout << t[i] << "	";
	cout << endl << endl;
	system("pause");
}
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <functional>
#include "Distance.h"
using namespace std;

bool dist_comp_greater(Distance dist1, Distance dist2)
{
	return(dist1 > dist2);
}
bool dist_comp_less(Distance dist1, Distance dist2)
{
	return(dist1 < dist2);
}

int main()
{
	SetConsoleOutputCP(1251);
	Distance d1[3] = { Distance(8, 25), Distance(13, 6.5), Distance(4, 48.5) };
	cout << "ƒо сортировки: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "dist[" << i << "] = "; d1[i].show_dist(); cout << endl;
	}
	cout << "—ортировка по возрастанию: " << endl;
	sort(d1, d1 + 3, dist_comp_less);
	// ¬ данном случае пользовательскую функцию dist_comp_less() можно не создавать, так как у класса имеетс€ перегруженный оператор сравнени€ '<' и sort() будет работать с двум€ аргументами
	//sort(d1, d1 + 3);
	for (int i = 0; i < 3; i++)
	{
		cout << "dist[" << i << "] = "; d1[i].show_dist(); cout << endl;
	}
	cout << "—ортировка по убыванию: " << endl;
	sort(d1, d1 + 3,greater<Distance>());
	for (int i = 0; i < 3; i++)
	{
		cout << "dist[" << i << "] = "; d1[i].show_dist(); cout << endl;
	}
	system("pause");
}


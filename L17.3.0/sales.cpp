#include "sales.h"

int sales::getdata()
{
	cout << "Âגוהטעו מבת¸ל ןנמהאז חא 3 לוסÿצא: \n Ìוסÿצ 1: "; cin >> cost[0];
	cout << " Ìוסÿצ 2: "; cin >> cost[1];
	cout << " Ìוסÿצ 3: "; cin >> cost[2]; cout << endl;
	return 0;
}

void sales::putdata()
{
	for (int i = 0; i != 3; i++) 
		cout << "Ïנמהאזט חא לוסÿצ " << i + 1 << ": " << cost[i] << endl;
}
#include "sales.h"

int sales::getdata()
{
	cout << "������� ����� ������ �� 3 ������: \n ����� 1: "; cin >> cost[0];
	cout << " ����� 2: "; cin >> cost[1];
	cout << " ����� 3: "; cin >> cost[2]; cout << endl;
	return 0;
}

void sales::putdata()
{
	for (int i = 0; i != 3; i++) 
		cout << "������� �� ����� " << i + 1 << ": " << cost[i] << endl;
}
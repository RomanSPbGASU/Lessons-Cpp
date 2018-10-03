#include <iostream>
#include <windows.h>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	float n;	// �������� �����
	int max = 1;
	char ans = 'y';

	float *mas, *mas2 = new float;

	do
	{
		cout << "������� ����� � ������� � ��������� ������: "; cin >> n;
		mas = new float[max];
		for (int i = 0; i < max - 1; i++)
		{
			mas[i] = mas2[i];
		}
		mas[max++ - 1] = n;
		delete[] mas2;
		mas2 = mas;

		cout << "���������� (y/n): "; cin >> ans;
	} while (ans == 'y');

	max--;
	cout << endl << endl << "�� ����������: " << endl;
	for (int k = 0; k < max; k++)
		cout << mas2[k] << " ";

	cout << endl << endl << "���������� �� �����������: " << endl;
	sort(mas2, mas2 + max, less<float>());
	for (int k = 0; k < max; k++)
		cout << mas2[k] << " ";

	cout << endl << endl << "���������� �� ��������: " << endl;
	sort(mas2, mas2 + max, greater<float>());
	for (int k = 0; k < max; k++)
		cout << mas2[k] << " ";

	cout << endl << endl;
	system("pause");
}
#include <iostream>
#include <iomanip>
#include "stock.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	stock sec[3] =	{ {"�������", "�����", 50, 141.56f},
					{"��������", "�����", 135, 101.87f},
					{"�������", "���������", 214, 1001.26f} };
	stock buy[3] =	{ { "�������", "�����", 50, 137.89f }, //� ������� �������, ��� ������� buy � sell ������ ����� �� 3 ��������
					{ "��������", "�����", 115, 98.09f },
					{"�������", "���������", 0, 0} };
	stock sell[3] = { { "�������", "�����", 0, 0 },
					{ "��������", "�����", 150, 101.62f },
					{ "�������", "���������", 114, 1002.68f } };
//������ �������
	cout << " " << setw(20) << left << "������������ ��" << setw(12) << left << "��� ��"
		<< setw(15) << left << "����������" << setw(12) << left << "���� ��" << setw(20)
		<< right << "��������� �������" << endl 
		<< "\n" << setw(50) << right << "��������� ��������� ��������" << endl << endl;
	const int posnumber = 3; //������, ��� ���������� ��������� ������� ��������
	for (int i = 0; i < posnumber; i++)
		sec[i].show_investment();
	stock fict(NULL, NULL, 0, 0); //��������� ������ (�� ����, ��� ������� ��� ����)
	int count = sizeof(sec) / sizeof(stock);
	cout << "\n " << setw(32) << left << "����� ��������� ��������" 
		<< setw(15) << setw(47) << right << setprecision(2) << fixed << fict.portfolio_cost(sec, count) << endl;
	cout << "\n" << setw(40) << right << "�������" << endl << endl;
	for (int i = 0; i < posnumber; i++)
		buy[i].show_investment();
	cout << "\n" << setw(40) << right << "�������" << endl << endl;
	for (int i = 0; i < posnumber; i++)
		sell[i].show_investment();
	cout << "\n" << setw(50) << right << "�������� ��������� ��������" << endl << endl;
	for (int i = 0; i < posnumber; i++)
	{
		sec[i].recalc_investment(buy[i], sell[i]); //����� �������� �������� �� ���������� �������� � ���� �� ��� ������ �������
		sec[i].show_investment();
	}
	cout << "\n " << setw(32) << left << "����� ��������� ��������"
		<< setw(15) << setw(47) << right << setprecision(2) << fixed << fict.portfolio_cost(sec, count) << endl;
	cin.get();
}

#include "publication.h"

void publication::getdata()
{
	cout << "������� ���������: ";
	title[0] = NULL;					// ��� ������� ���� �� ���������� ���� ��-�����������?
	cin.getline(title, MAX); 
	if (strlen(title) == 0) 
	{
		cin.ignore(0, 1);
		cin.getline(title, MAX);
	}
	cout << "������� ����: "; cin >> price; 
}
void publication::putdata()
{
	cout << "���������: " << title << endl;
	cout << "����: " << price << endl;
}
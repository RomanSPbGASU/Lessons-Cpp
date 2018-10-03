#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

struct person
{
	int number;
	char surname[15];
	char name[15];
	float salary;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream myfile("list_2.txt", ios::in | ios::binary);										// ������� ����� ��� ��������� ������
	person pers;
	myfile.seekg(0, ios::end);																	// ��������� ��������� � ����� ����� (������ ������)
	cout << "� ����� " << myfile.tellg() / (float)sizeof(pers) << " �������" << endl << endl;	// ������� ������� ������� � ������
	int n;																						// ����� ������
	char answer;																				// ����� � ����������� �����
	do
	{
		cout << "������� ����� ������: "; cin >> n; cout << endl;
		myfile.seekg(sizeof(person) * (n - 1), ios::beg);										// ��������� ��������� ����� n-��� ���������
		myfile.read((char*)(&pers), sizeof(person));											// ������� ������� ���� person
		cout << pers.number << " "
			<< pers.surname << " "
			<< setw(15 - strlen(pers.surname)) << left << pers.name << " "
			<< fixed << setprecision(2) << pers.salary << endl << endl;
		cout << "����� ���������� ����? (�/�): "; cin >> answer; cout << endl;
	} while (answer == '�');
		myfile.close();																			// ������� ����
	system("pause");
}
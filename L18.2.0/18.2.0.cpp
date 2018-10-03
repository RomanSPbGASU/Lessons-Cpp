#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

void masmax(int (&)[5],int(&)[5], int (&)[3][5]);	// ���������� �������� ��������, ��������� � ��������� �������� (��������)
void print1(int (&)[5]);							// ����� �� ����� ��������� ������� (������������ 1 � 5)
void print3(int (&)[3][5]);							// ����� �� ����� ��������� ������� (������������ 3 � 5)
int read1(int (&)[5], char * filename);				// ���������� ��������� ������� (������������ 1 � 5)
int write(int (&)[3][5], char * filename);			// ������ ��������������� ������� � ����
int read3(int (&)[3][5], char * filename);			// ���������� ��������������� ������� (������������ 3 � 5) �� �����

void main()
{
	SetConsoleOutputCP(1251);
	int mas1[5];
	if (!read1(mas1, "task_18_2_1.txt"))
	cout << "\n������ ������ ������ �� ����� task_18_2_1.txt" << endl;
	else cout << "������ ���������� �� ����� task_18_2_1.txt" << endl;
	print1(mas1);
	int mas2[5];
	if (!read1(mas2, "task_18_2_2.txt"))
	cout << "\n������ ������ ������ �� ����� task_18_2_2.txt" << endl;
	else cout << "������ ���������� �� ����� task_18_2_2.txt" << endl;
	print1(mas2);
	int mas3[3][5];
	masmax(mas1, mas2, mas3);
	cout << "\n�������������� ������" << endl;
	print3(mas3);
	if(!write(mas3, "task_18_2_3.txt"))
	cout << "\n�������������� ������ ������� � ���� task_18_2_3.txt" << endl;
	else cout << "������ ������ � ���� task_18_2_3.txt" << endl;
	int mas4[3][5];
	read3(mas4, "task_18_2_3.txt");
	cout << "\n�������������� ������ ������ �� ����� task_18_2_3.txt" << endl;
	print3(mas4);
	system("pause");
}

void masmax(int (&mas1)[5], int (&mas2)[5], int (&mas3)[3][5])
{
	for (int i = 0; i < 5; i++)
	{
		mas3[0][i] = mas1[i] + mas2[i];
		mas3[1][i] = mas1[i] - mas2[i];
		mas3[2][i] = mas1[i] * mas2[i];
	}
}

void print1(int(&mas)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << setw(3) << left << mas[i];
	}
	cout << endl;
}

void print3(int(&mas)[3][5])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++) { cout << setw(3) << left << mas[i][j]; }
		cout << endl;
	}
}

int read1(int (&mas)[5], char *filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);
	int i;
	for (i = 0; (i != 5) && myfile.good(); i++)
	{
	myfile >> mas[i];
	}
	if (i == 5) return 0; // ��� �������� �������?
	else return 1;
}

int write(int (&mas)[3][5], char *filename)
{
	fstream myfile(filename, ios::out);
	int i, j;
	for (i = 0; i < 3 && myfile.good(); i++)
	{
		for (j = 0; j != 5 && myfile.good(); j++)
		{
			myfile << mas[i][j] << ' ';
		}
		myfile << endl;
	}
	if ((i = 3) && (j = 5)) return 0;
	else return 1;
}

int read3(int (&mas)[3][5], char *filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);
	int i, j;
	for (i = 0; i < 3 && myfile.good(); i++)
		for (j = 0; j < 5 && myfile.good(); j++)
		{
			myfile >> mas[i][j];
		}
	if (j = 5) return 0;
	else return 1;
}

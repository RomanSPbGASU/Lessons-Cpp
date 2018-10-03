#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

void read_f(char*);
void write_f(char*, char*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* file = "list.txt", *file_1 = "list_1.txt";				// ����� ������� ������

	cout << "��������� ������..." << endl << endl;
	read_f(file);													// ����� �� ����� ���������� ������ �� ����� list.txt
	cout << "�������������� ������..." << endl << endl;
	read_f(file_1);													// ����� �� ����� ������� ������ �� ����� list_1.txt
	write_f(file, file_1);											// ���������� ������� ������ � ������� ������
	cout << "����������� ������..." << endl << endl;
	read_f(file);													// ����� �� ����� ������������ ������ �� ����� list.txt
	system("pause");
}

void read_f(char*filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);				// �������� ������� ������ fstream � ������������� ��� ������, ����������� filename
	if (myfile.is_open() == 0) cout << "������ �������� �����";		// �������� ������������ �������� �����
	else
	{
		cout << myfile.rdbuf() << endl;								// ����� ������ ������ myfile �� �����
	}
	myfile.close();
}

void write_f(char*filename1, char*filename2)
{
	fstream myfile1(filename1, ios::app);							// �������� ������� ����� ��� ������ � �����
	fstream myfile2(filename2, ios::in | ios::_Nocreate);			// �������� ������� ����� ��� ������
	myfile1 << endl << myfile2.rdbuf();								// ������ ������ ������, ������������������� ������ ������ � ������ (� �����)
	myfile1.close();												// �������� ������
	myfile2.close();
}

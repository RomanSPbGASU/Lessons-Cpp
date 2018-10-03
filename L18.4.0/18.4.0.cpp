#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <limits.h>
using namespace std;

void read_f(char*);															// ������ ������ �� �����
void write_f(char*, char*);													// ���� ������ � ����� ����� �� �����
void write_f(char*);														// ���� ������ � ����������
void getfilename(char*);													// ���������� ��� ����� �������� �������������
int selectmet();															// ����� ������ �����
int continueinput();														// ������ ���������� �� ����

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* file = "list.txt", *file_1 = "list_1.txt";						// ����� ������� ������

	cout << "��������� ������..." << endl << endl;
	read_f(file);															// ����� �� ����� ���������� ������ �� ����� list.txt
	do
	{
		if (selectmet() == 1)
			write_f(file);													// ���� ����� 1, �� ���� � ����������
		else
		{
			char filename[80];
			getfilename(filename);
			cout << "�������������� ������ �� ����� " << filename << "..." << endl << endl;
			read_f(filename);
			write_f(file, filename);										// ���� ����� 2, �� ���� �� �����
		}
		cout << "���������� ������..." << endl << endl;
		read_f(file);
	} while (continueinput());
	system("pause");
}

void read_f(char*filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);						// �������� ������� ������ fstream � ������������� ��� ������, ����������� filename
	if (myfile.is_open() == 0) cout << "������ �������� �����" << endl;		// �������� ������������ �������� �����
	else
	{
		cout << myfile.rdbuf() << endl;										// ����� ������ ������ myfile �� �����
	}
	myfile.close();
}

void write_f(char*filename1, char*filename2)
{
	fstream myfile1(filename1, ios::app);									// �������� ������� ����� ��� ������
	fstream myfile2(filename2, ios::in | ios::_Nocreate);					// �������� ������� ����� ��� ������
	char endchar;															// ��������� ������ � �����
	myfile1 << endl << myfile2.rdbuf();										// ������ ������ ������, ������������������� ������ ������ � ������ (� �����)
	myfile1.close();														// �������� ������
	myfile2.close();
}

void write_f(char*filename)
{
	int number; char surname[80], name[80]; float salary;
	cout << "������� ����� ����������: "; cin >> number;
	cout << "������� ������� ����������: "; cin >> surname;
	cout << "������� ��� ����������: "; cin >> name;
	cout << "������� ����� ����������: "; cin >> salary;
	fstream myfile(filename, ios::app);										// ������� ���� ��� ������
	myfile << endl << number << " " << surname << " "
		<< setw(15 - strlen(surname)) << left << name << " " 
		<< fixed << setprecision(2) << salary;
	myfile.close();
}
void getfilename(char* filename)
{
	cout << "������� ������ ��� �����: ";
	cin >> filename;
}

int selectmet()
{
	cout << "�������� ������� ����� ������: 1 - c ����������"
		<< endl << setw(45) << right << "2 - �� �����:	";
	int answer;
	cin >> answer;														// ������� �������� ������� (�� �������)
	return answer;
}

int continueinput()
{
	cout << "���������� ����? (�/�): ";
	char answer;
	cin >> answer;
	if (answer == '�') return 1;
	else return 0;
}

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
int intin();																// ������� ������� ������ ����� �����
float floatin();															// ������� ������� ������ �����

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
	fstream myfile1(filename1, ios::in);									// �������� ������� ����� ��� ������
	fstream myfile2(filename2, ios::in | ios::_Nocreate);					// �������� ������� ����� ��� ������
	char endchar;															// ��������� ������ � �����
	myfile1.seekg(-1, ios::end);											// �������� ��������� �� 1 ������ �� ����� �����
	myfile1.get(endchar);													// ������� ��������� ������
	myfile1.close();														// �������� �����
	myfile1.open(filename1, ios::app);										// �������� ������� ����� ��� ������ � �����
	if (endchar != '\n') myfile1 << endl;									// ���� � ����� ����� ��� �������� ������, �� ������� �� ����� ������
	myfile1 << myfile2.rdbuf();												// ������ ������ ������, ������������������� ������ ������ � ������ (� �����)
	myfile1.close();														// �������� ������
	myfile2.close();
}

void write_f(char*filename)
{
	int number; char surname[80], name[80]; float salary;
	cout << "������� ����� ����������: "; number = intin();
	cout << "������� ������� ����������: "; cin >> surname;
	cout << "������� ��� ����������: "; cin >> name;
	cout << "������� ����� ����������: "; salary = floatin();
	fstream myfile(filename, ios::in);										// ������� ���� ��� ������
	char endchar;															// ��������� ������ � �����
	myfile.seekg(-1, ios::end);												// �������� ��������� �� 1 ������ �� ����� �����
	myfile.get(endchar);													// ������� ��������� ������
	myfile.close();															// �������� �����
	myfile.open(filename, ios::app);										// �������� ����� ��� ������ � �����
	if (endchar != '\n') myfile << endl;									// ���� � ����� ����� ��� �������� ������, �� ������� �� ����� ������
	myfile << number << " " << surname << " "
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
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// �������� Handle ������ �������
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// �������� ���������� � ������ �������
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// �������� ������� ������� ������� � �������
	COORD CursorPosition;
	int answer;
	int inputsize;															// ���������� �������� ��������
	char ch;
	while (1)
	{
		while (cin.peek() == '\n')											// ���� ������ Enter �� ����� ������
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// ���������� ������ � ���������� ���������
			cin.ignore(1);													// .peek() ��������� ����������� ��������� ������ ��� ���������� (����� ������������ ��� ���������� ������������ ������ ����)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// �������� ������ ������ �����
		cin >> answer;														// ������� �������� ������� (�� �������)
		if (answer == 1 || answer == 2) break;
		cin.clear();														// �� ������, ���� ���������� ���� ���������� � �������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ������� ����� �������� ��������
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// ����������� �������� ������� ���������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ���������� ���������
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() ���������� ���������� ���������, ������� ������ � ������ �� ������
	}
	return answer;
}

int continueinput()
{
	cout << "���������� ����? (�/�): ";
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// �������� Handle ������ �������
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// �������� ���������� � ������ �������
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// �������� ������� ������� ������� � �������
	COORD CursorPosition;
	char answer;
	int inputsize;															// ���������� �������� ��������
	char ch;
	while (1)
	{
		while (cin.peek() == '\n')											// ���� ������ Enter �� ����� ������
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// ���������� ������ � ���������� ���������
			cin.ignore(1);													// .peek() ��������� ����������� ��������� ������ ��� ���������� (����� ������������ ��� ���������� ������������ ������ ����)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// �������� ������ ������ �����
		cin >> answer;														// ������� �������� ������� (�� �������)
		if (answer == '�' || answer == '�') break;
		cin.clear();														// �� ������, ���� ���������� ���� ���������� � �������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ������� ����� �������� ��������
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// ����������� �������� ������� ���������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ���������� ���������
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() ���������� ���������� ���������, ������� ������ � ������ �� ������
	}
	if (answer == '�') return 1;
	else return 0;
}

int intin()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// �������� Handle ������ �������
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// �������� ���������� � ������ �������
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// �������� ������� ������� ������� � �������
	COORD CursorPosition;
	int answer;
	short inputsize;
	while (1)
	{
		while (cin.peek() == '\n')											// ���� ������ Enter �� ����� ������
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// ���������� ������ � ���������� ���������
			cin.ignore(1);													// .peek() ��������� ����������� ��������� ������ ��� ���������� (����� ������������ ��� ���������� ������������ ������ ����)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// �������� ������ ������ �����
		cin >> answer;														// ������� �������� ������� (�� �������)
		if (!cin.fail()) break;
		cin.clear();														// �� ������, ���� ���������� ���� ���������� � �������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ������� ����� �������� ��������
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// ����������� �������� ������� ���������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ���������� ���������
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() ���������� ���������� ���������, ������� ������ � ������ �� ������
	}
	short buffersize = cin.rdbuf()->in_avail();								// ������ ������ �����
	SetConsoleCursorPosition(ConsoleHandle, 								// ���������� ������ � ������� ����� ���������� ������
	{ CorrectCursorPosition.X + inputsize - buffersize, CorrectCursorPosition.Y });
	for (int i = 0; i < buffersize - 1; i++) cout << " ";					// �������� "�����"
	cin.ignore(cin.rdbuf()->in_avail());									// �������� �����
	cout << endl;
	return answer;
}

float floatin()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					// �������� Handle ������ �������
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(ConsoleHandle, &Info);						// �������� ���������� � ������ �������
	COORD CorrectCursorPosition = Info.dwCursorPosition;					// �������� ������� ������� ������� � �������
	COORD CursorPosition;
	float answer;
	short inputsize;
	while (1)
	{
		while (cin.peek() == '\n')											// ���� ������ Enter �� ����� ������
		{
			SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);	// ���������� ������ � ���������� ���������
			cin.ignore(1);													// .peek() ��������� ����������� ��������� ������ ��� ���������� (����� ������������ ��� ���������� ������������ ������ ����)
		}
		cin.peek();
		inputsize = cin.rdbuf()->in_avail();								// �������� ������ ������ �����
		cin >> answer;														// ������� �������� ������� (�� �������)
		if (!cin.fail()) break;
		cin.clear();														// �� ������, ���� ���������� ���� ���������� � �������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ������� ����� �������� ��������
		for (int i = 0; i < inputsize - 1; i++) cout << " ";				// ����������� �������� ������� ���������
		SetConsoleCursorPosition(ConsoleHandle, CorrectCursorPosition);		// ���������� ������ � ���������� ���������
		cin.ignore(cin.rdbuf()->in_avail());								// in_avail() ���������� ���������� ���������, ������� ������ � ������ �� ������
	}
	short buffersize = cin.rdbuf()->in_avail();								// ������ ������ �����
	SetConsoleCursorPosition(ConsoleHandle,									// ���������� ������ � ������� ����� ���������� ������
	{ CorrectCursorPosition.X + inputsize - buffersize, CorrectCursorPosition.Y });
	for (int i = 0; i < buffersize - 1; i++) cout << " ";					// �������� "�����"
	cin.ignore(cin.rdbuf()->in_avail());									// �������� �����
	cout << endl;
	return answer;
}
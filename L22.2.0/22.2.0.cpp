#include <Windows.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#pragma region
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::getline;
using std::ios;
using std::for_each;
using std::sort;
#pragma endregion

struct names
{
	int number;
	string name_b;
	//bool operator != (names n2)
	//{
	//	if (this->name_b == n2.name_b && this->number == n2.number) return false;
	//	else return true;
	//}
} n;

vector<names> vname;	// ������ ��� �������� ������� ������� NAMES
						// ������ ������ �� ����� NAMES.txt � ������
void read_names(const char* filename, vector<names>& vname)
{
	fstream myfile(filename, ios::in);
	myfile.exceptions(fstream::eofbit);
	string substring;
	try
	{
		while (1)
		{
			getline(myfile, substring, ';');
			n.number = stoi(substring);
			getline(myfile, n.name_b);
			vname.push_back(n);
		}
	}
	catch (fstream::failure eb)	// ��� ����� ��� �������� ����� �����
	{
		if (vname[vname.size() - 1].name_b != n.name_b) vname.push_back(n);
		return;
	}
}
// ������ ����������� � ���� RESULT.txt
void write_names(char* filename, const vector<names> &vname)
{
	fstream myfile(filename, ios::out);
	for_each(vname.begin(), vname.end(), [&](const names &n) { myfile << n.number << ";" << n.name_b << endl; });
}

int main()
{
	SetConsoleOutputCP(1251);

	char file_1[] = "NAMES.txt", file_2[] = "NAMES_sort.txt";

	read_names(file_1, vname);	// ������� ���������� ������� � ����� NAMES.txt � ���������� ������� vname
	cout << "��������� " << vname.size() << " ������� �� ����� " << file_1 << endl;
	cout << "����������..." << endl;
	sort(vname.begin(), vname.end(), [](const names &n1, const names &n2) { return n1.number < n2.number; });
	write_names(file_2, vname);
	cout << "�������� " << vname.size() << " ������� � ���� " << file_2 << endl;
}

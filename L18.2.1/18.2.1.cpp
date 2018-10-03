#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <sstream>

using namespace std;

void masASM(vector <vector<int>> &vecIntMas1,
	vector <vector<int>> &vecIntMas2, vector <vector<int>> &vecIntRes);	// ���������� �������� ��������, ��������� � ��������� �������� (��������)
void print(vector <vector<int>> &vecIntMas);							// ����� ������� �� �����
int read(vector <vector<int>> &vecIntMas, char * filename);				// ���������� �������
int write(vector <vector<int>> &vecIntMas, char * filename);			// ������ �������
int vec2Size(vector <vector<int>> &vecIntMas);							// ���������� ������ ���������� �������

void main()
{
	SetConsoleOutputCP(1251);
	vector<vector<int>>mas1;
	if(!read(mas1, "task_18_2_1.txt"))
		 cout << "������ ������ ������ �� ����� task_18_2_1.txt" << endl;
	else cout << "������ ���������� �� ����� task_18_2_1.txt" << endl;
	print(mas1);
	vector<vector<int>>mas2;
	if(!read(mas2, "task_18_2_2.txt"))
		 cout << "\n������ ������ ������ �� ����� task_18_2_2.txt" << endl;
	else cout << "\n������ ���������� �� ����� task_18_2_2.txt" << endl;
	print(mas2);
	vector<vector<int>>mas3;
	masASM(mas1, mas2, mas3);
	cout << "\n�������������� ������:" << endl;
	print(mas3);
	if (!write(mas3, "task_18_2_3.txt"))
		 cout << "\n�������������� ������ ������� � ���� task_18_2_3.txt" << endl;
	else cout << "\n������ ������ � ���� task_18_2_3.txt" << endl;
	vector<vector<int>> mas4;
	if (!read(mas4, "task_18_2_3.txt"))
		 cout << "\n�������������� ������ ������ �� ����� task_18_2_3.txt" << endl;
	else cout << "\n������ ���������� �� ����� task_18_2_3.txt" << endl;
	print(mas4);
	cout << endl;
	system("pause");
}

void masASM(vector <vector<int>> &vecIntMas1, vector <vector<int>> &vecIntMas2, vector <vector<int>> &vecIntRes)
{
	int vecminsize = vec2Size(vecIntMas1) > vec2Size(vecIntMas2) ? vec2Size(vecIntMas2) : vec2Size(vecIntMas1);
	int vecminsizeDiv5 = vecminsize / 5, vecminsizeDiv5Mul2 = vecminsizeDiv5 * 2, vecminsizeDiv5Mul3 = vecminsizeDiv5 * 3;
	vecIntRes.resize(5);
	// ������������� ������ ��� ������
	for (int i = 0; i < 5; i++)
	{
		//vecIntRes[i].reserve(vecminsizeDiv5); // ��� �� ��� � reserve()?
		vecIntRes[i].resize(vecminsizeDiv5Mul3);
	}
	// �������������� ��� (��������� ����� ������� �����)
	for (int i = 0; i < vecminsizeDiv5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			vecIntRes[j][i] = vecIntMas1[j][i] + vecIntMas2[j][i];
			vecIntRes[j][i + vecminsizeDiv5] = vecIntMas1[j][i] - vecIntMas2[j][i];
			vecIntRes[j][i + vecminsizeDiv5Mul2] = vecIntMas1[j][i] * vecIntMas2[j][i];
		}
	}
}
void print(vector <vector<int>> &vecIntMas)
{
	int count = 0;							// ������� �����
	int size = vec2Size(vecIntMas);			// ���������� ��������� � �������
	stringstream intermstream;				// ������������� �����
	int elemsize = 1;						// ����� ����� � �������
	int maxelemsize = 1;					// ������������ ����� ����� � �������
	int n;
	for (int i = 0; count != size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			elemsize = 1;
			n = vecIntMas[j][i];
			intermstream << n << ' ';		// ��������� ������� ������� � ������������� �����
			if (n < 0) elemsize++;
			while ((n /= 10) > 0) elemsize++;
			if (elemsize > maxelemsize) maxelemsize = elemsize;
			if (++count == size) break;
		}
	}
	int elem;
	while (intermstream.good())
	{
		for (int i = 0; i < 5; i++)
		{
			intermstream >> elem;
			if (!intermstream.good()) break;
			cout << setw(maxelemsize + 1) << right << elem;
		}
		cout << endl;
	}
}

int read(vector <vector<int>> &vecIntMas, char * filename)
{
	fstream myfile(filename, ios::in, ios::_Nocreate);
	// ������� ����� https://ru.stackoverflow.com/questions/57957/���������-vector � ����� http://cppstudio.com/post/8670/
	int intCount;
	vecIntMas.resize(5);
	while (myfile.good())
	{
		for (int i = 0; (i < 5) && (myfile >> intCount); i++)
		{
			vecIntMas[i].push_back(intCount);			// ��������� ��������� ������ �� ������
		}
	}
	if (myfile.eof()) return 0;
	else return 1;
}

int write(vector <vector<int>> &vecIntMas, char * filename)
{
	fstream myfile(filename, ios::out);
	int count = 0;
	int size = vec2Size(vecIntMas);
	for (int i = 0; count != size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			myfile << vecIntMas[j][i] << ' ';
			if (count++ == size) break;
		}
		myfile << endl;
	}
	if (myfile.good()) return 0;
	else return 1;
}

int vec2Size(vector <vector<int>> &vecIntMas)
{
	int size = 0;
	for (int i = 0; i < (int)vecIntMas.size(); i++)
	{
		size += vecIntMas[i].size();
	}
	return size;
}
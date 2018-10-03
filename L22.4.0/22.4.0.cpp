#include <windows.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
using namespace std;
//using std::deque;
//using std::fstream;
//using std::ios;
//using std::cout;
//using std::endl;

struct person
{
	int id;
	char fname[15];
	char iname[15];
	float salary;
};
deque<person>deq, deq_1;	// ���������� ���� �������� � ������������ �������� deq � deq_1 ��� ������ ���� person

// ���������� ������ �� ����� � ������ �� � ��������� deque
void read_f(const char*filename, deque<person>&d)
{
	fstream myfile(filename, ios::in);
	person p;
	while (myfile >> p.id >> p.fname >> p.iname >> p.salary)
		d.push_back(p);
}
// ���������� ����������� ������ ���������� � ����������� ������� ����������
void add_deq(deque<person>&from, deque<person>&to)
{
	// ������� 1
	int i = to.size();
	to.resize(from.size() + to.size());
	copy(from.begin(), from.end(), to.begin() + i);
	sort(to.begin(), to.end(), [](const person &p, const person &p2) { return p.id < p2.id; });

	//// ������� 2
	//sort(from.begin(), from.end(), [](const person &p, const person &p2){return p.id < p2.id;});
	//sort(to.begin(), to.end(), [](const person &p, const person &p2){return p.id < p2.id;});
	//deque<person>over(from.size() + to.size());
	//merge(from.begin(), from.end(), to.begin(), to.end(), over.begin(), [](const person &p, const person &p2){return p.id < p2.id;});
	//to.resize(from.size() + to.size());
	//copy(over.begin(), over.end(), to.begin());
}
 //����� ������������ ���������� �� �����
void show_deq(deque<person>&d)
{
	for_each(d.begin(), d.end(), [](const person p) { cout << p.id << " " << p.fname << " " << p.iname << " " << p.salary << endl; });
}
// ����� ����������� ���������� � ����
void write_f(const char*filename, deque<person>&d)
{
	fstream myfile(filename, ios::out);
	for_each(d.begin(), d.end(), [&](const person p) { myfile << p.id << " " << p.fname << " " << p.iname << " " << p.salary << endl; });
}

int main()
{
	SetConsoleOutputCP(1251);

	const char* file = "list.txt", *file_1 = "list_1.txt", *file_2 = "list_res.txt";	// ����� ������� ������

	read_f(file, deq);	// ���������� ���������� ������� �� ����� list.txt � ������ ��� � ��������� deq
	read_f(file_1, deq_1);
	cout << "��������� ������..." << endl << endl;
	show_deq(deq);
	cout << endl << "�������������� ������..." << endl << endl;
	show_deq(deq_1);
	cout << endl << "���������� ������..." << endl << endl;
	add_deq(deq, deq_1);
	show_deq(deq_1);
	write_f(file_2, deq_1);
	cout << endl;
	system("pause");
}
//#include "moneylist.h"
//#include "planlist.h"
//#include "nameslist.h"
#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

struct names
{
	int number;
	string name_b;
} n;
struct plans
{
	char plan;
	int num_sc;
	string name;
} p;
struct money
{
	int regn;
	char plan;
	int num_sc;
	char a_p;
	float vr, vv, vitg, ora, ova, oitga, orp, ovr, oitgp, ir, iv, iitg;
	string dt;
	//int time;
	float priz;
} m;
struct res
{
	int regn, num_sc;
	string dt;
	float iitg;
} r;

vector<names> vname;	// ������ ��� �������� ������� ������� NAMES
vector<plans> vplan;	// ������ ��� �������� ������� ������� PLAN
vector<money> vmoney;	// ������ ��� �������� ������� ������� 101F
vector<res> vres;		// ������ ��� �������� �����������

// ������ ������ �� ����� NAMES.txt � ������
void read_names(const char* filename, vector<names>& vname)
{
	fstream myfile(filename, ios::in);
	string sline;
	string substring;
	while (getline(myfile, sline))
	{
		stringstream ssline;
		ssline << sline;
		try
		{
			getline(ssline, substring, ';');
			n.number = stoi(substring);
			getline(ssline, n.name_b);
		}
		catch(...)
		{
			if (!myfile.eof()) 
				cout << "�������� ���������� � ������: " << vname.size() + 1 << endl;
			continue;
		}
		vname.push_back(n);
	}
}
// ������ ������ �� ����� PLAN.txt � ������
void read_plans(const char* filename, vector<plans>&vplan)	
{
	fstream myfile(filename, ios::in);
	string sline;
	string substring;
	while (getline(myfile, sline))
	{
		stringstream ssline;
		ssline << sline;
		try
		{
			getline(ssline, substring, ';');
			p.plan = substring[0];
			getline(ssline, substring, ';');
			p.num_sc = stoi(substring);
			getline(ssline, p.name);
		}
		catch(...)
		{
			if (!myfile.eof())
				cout << "�������� ���������� � ������: " << vplan.size() + 1 << endl;
			continue;
		}
		vplan.push_back(p);
	}
}
// ������ ������ �� ����� 101F.txt � ������
void read_money(const char* filename, vector<money>& vmoney)
{
	fstream myfile(filename, ios::in);
	string sline;
	string substring;
	while (getline(myfile, sline))
	{
		stringstream ssline;
		ssline << sline;
		try 
		{
			ssline >> m.regn;
			ssline.get();
			getline(ssline, substring, ';');
			m.plan = substring[0];
			ssline >> m.num_sc;
			ssline.get();
			getline(ssline, substring, ';');
			m.plan = substring[0];
			ssline >> m.vr;
			ssline.get();
			ssline >> m.vv;
			ssline.get();
			ssline >> m.vitg;
			ssline.get();
			ssline >> m.ora;
			ssline.get();
			ssline >> m.ova;
			ssline.get();
			ssline >> m.oitga;
			ssline.get();
			ssline >> m.orp;
			ssline.get();
			ssline >> m.ovr;
			ssline.get();
			ssline >> m.oitgp;
			ssline.get();
			ssline >> m.ir;
			ssline.get();
			ssline >> m.iv;
			ssline.get();
			ssline >> m.iitg;
			ssline.get();
			getline(ssline, m.dt, ';');
			m.dt.resize(10);
			ssline >> m.priz;
		}
		catch (...)
		{
			if (!myfile.eof())
				cout << "�������� ���������� � ������: " << vplan.size() + 1 << endl;
			continue;
		}
		vmoney.push_back(m);
	}
}
//// ��������� ������������ ����� �� ��� ������
//string get_name(int /*position*/, vector<names>vname)
//{
//	return vname[position].name_b;
//}
//// ��������� ������������ ����� �� ��� ������
//string get_plan(int /*position*/, vector<plans>vplan)
//{
//	return vplan[position].name;
//}
//void search_money(int, int, vector<money>, vector<res>&);	// ����� ������� ��������������� �������� ��������
//void show_res(vector<res>);	// ����� ����������� �� �����
//void write_res(char*, vector<res>);	// ������ ����������� � ���� RESULT.txt

int main()
{

	{
		SetConsoleOutputCP(1251);

		char file_1[] = "NAMES.txt", file_2[] = "PLAN.txt", file_3[] = "101F.txt", file_4[] = "RESULT.txt";

		//int regn, num_sc;
		time_t dt = time(NULL);
		read_names(file_1, vname);	// ������� ���������� ������� � ����� NAMES.txt � ���������� ������� vname
		cout << "��������� " << vname.size() << " ������� �� ����� " << file_1 << endl;

		read_plans(file_2, vplan);	// ������� ���������� ������� � ����� PLAN.txt � ���������� ������� vname
		cout << "��������� " << vplan.size() << " ������� �� ����� " << file_2 << endl;

		read_money(file_3, vmoney);	// ������� ���������� ������� � ����� 101F.txt � ���������� ������� vname
		cout << "��������� " << vmoney.size() << " ������� �� ����� " << file_3 << endl;

		cout << "����� ����������: " << -(dt -= time(NULL)) << endl;
		//int regn;
		//string num_sc;
		//cout << "\n������� ���. ����� �����: "; cin >> regn;
		//if (n1.get_single(regn) == "\0")
		//{
		//	system("pause");
		//	return(0);
		//}

		//cout << "\n������� ����� �����: "; cin >> num_sc;
		//if (p1.get_single(num_sc) == "\0")
		//{
		//	system("pause");
		//	return(0);
		//}

		//cout << "\n�������� ������� �� ����� �" << num_sc << " \"" << p1.get_single(num_sc) << " \"" << endl;

		//cout << "\n��� ����� �" << regn << " " << n1.get_single(regn) << endl;

		//cout << setw(7) << right << "����" << setw(22) << "�����, ���. ���." << endl;
		//m1.display_single(regn, num_sc, (char*)"RES.txt");
		//cout << endl;
	}
	system("pause");
}

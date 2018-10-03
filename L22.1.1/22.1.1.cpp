#include <Windows.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
using std::cin;
using std::cout;
using std::setw;
using std::right;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::getline;
using std::ios;
using std::out_of_range;
using std::fixed;
using std::setprecision;

template <class t>
bool Equal(const t &first, const t &second);

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
// ������ ������ �� ����� PLAN.txt � ������
void read_plans(const char* filename, vector<plans>&vplan)
{
	fstream myfile(filename, ios::in);
	myfile.exceptions(fstream::eofbit);
	string substring;
	try
	{
		while (1)
		{
			getline(myfile, substring, ';');
			p.plan = substring[0];
			getline(myfile, substring, ';');
			p.num_sc = stoi(substring);
			getline(myfile, p.name);
			vplan.push_back(p);
		}
	}
	catch (fstream::failure eb)	// ��� ����� ��� �������� ����� �����
	{
		if (vplan[vplan.size() - 1].name != p.name) vplan.push_back(p);
		return;
	}
}
// ������ ������ �� ����� 101F.txt � ������
void read_money(const char* filename, vector<money>& vmoney)
{
	fstream myfile(filename, ios::in);
	myfile.exceptions(fstream::eofbit);
	string substring;
	try
	{
		while (1)
		{
			getline(myfile, substring, ';');
			m.regn = stoi(substring);
			getline(myfile, substring, ';');
			m.plan = substring[0];
			getline(myfile, substring, ';');
			m.num_sc = stoi(substring);
			getline(myfile, substring, ';');
			m.a_p = substring[0];
			getline(myfile, substring, ';');
			m.vr = stof(substring);
			getline(myfile, substring, ';');
			m.vv = stof(substring);
			getline(myfile, substring, ';');
			m.vitg = stof(substring);
			getline(myfile, substring, ';');
			m.ora = stof(substring);
			getline(myfile, substring, ';');
			m.ova = stof(substring);
			getline(myfile, substring, ';');
			m.oitga = stof(substring);
			getline(myfile, substring, ';');
			m.orp = stof(substring);
			getline(myfile, substring, ';');
			m.ovr = stof(substring);
			getline(myfile, substring, ';');
			m.oitgp = stof(substring);
			getline(myfile, substring, ';');
			m.ir = stof(substring);
			getline(myfile, substring, ';');
			m.iv = stof(substring);
			getline(myfile, substring, ';');
			m.iitg = stof(substring);
			getline(myfile, m.dt, ';');
			m.dt.resize(10);
			getline(myfile, substring);
			m.priz = stof(substring);
			vmoney.push_back(m);
		}
	}
	catch (fstream::failure eb)	// ��� ����� ��� �������� ����� �����
	{
		if (!Equal(vmoney[vmoney.size() - 1], m)) vmoney.push_back(m);
		return;
	}
}
// ��������� ������������ ����� �� ��� ������
string get_name(int number, const vector<names>&vname)
{
	int i = 0;
	try
	{
		while (vname.at(i++).number != number);
	}
	catch(out_of_range)
	{
		return "";
	}
	return vname[i-1].name_b; 
}
// ��������� ������������ ����� �� ��� ������
string get_plan(int num_sc, const vector<plans>&vplan)
{
	int i = 0;
	try
	{
		while (vplan.at(i++).num_sc != num_sc);
	}
	catch(out_of_range)
	{
		return "";
	}
	return vplan[i - 1].name;
}
// ����� �������, ��������������� �������� ��������
void search_money(int regn, int num_sc, vector<money> vmoney, vector<res>& vres)
{
	int i = -1;
	try
	{
		while (1) 
			if (vmoney.at(++i).regn == regn && vmoney.at(i).num_sc == num_sc)
				vres.push_back({ vmoney[i].regn, vmoney[i].num_sc, vmoney[i].dt, vmoney[i].iitg });
	}
	catch(out_of_range)
	{
		return;
	}
}
// ����� ����������� �� �����
void show_res(const vector<res>&vres)
{
	int i = 0;
	try
	{
		do
			cout << vres.at(i).dt << setw(6) << " " << setw(7) << fixed << setprecision(0) << vres.at(i).iitg << endl;
		while (++i);
	}
	catch (out_of_range)
	{
		return;
	}

}
// ������ ����������� � ���� RESULT.txt
void write_res(char* filename, const vector<res> &vres)
{
	fstream myfile(filename, ios::out);
	int i = 0;
	try
	{
		do
			myfile << vres.at(i).regn << " " << vres.at(i).num_sc << " " << vres.at(i).dt << " " << setw(7) << fixed << setprecision(0) << vres.at(i).iitg << endl;
		while (++i);
	}
	catch (out_of_range)
	{
		return;
	}
}

int main()
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
	int regn, num_sc;
	string name, plan;
	while(1)
	{
		cout << endl << "������� ���. ����� �����: "; cin >> regn;
		if ((name = get_name(regn, vname)) != "")
			break;
		cout << "���� �� ������" << endl;
	}

	while (1)
	{
		cout << endl << "������� ����� �����: "; cin >> num_sc;
		if ((plan = get_plan(num_sc, vplan)) != "")
			break;
		cout << "���� �� ������" << endl;
	}

	cout << endl << "�������� ������� �� ����� �" << num_sc << " \"" << plan << " \"" << endl;

	cout << endl << "��� ����� �" << regn << " " << name << endl;

	cout << endl << setw(7) << right << "����" << setw(22) << "�����, ���. ���." << endl;
	search_money(regn, num_sc, vmoney, vres);
	show_res(vres);
	write_res(file_4, vres);
	cout << endl;
	system("pause");
}

template <class t>
bool Equal(const t &first, const t &second)
{
	bool ans = 0;
	for (char i = 0; i < sizeof(first) && (ans = !(((char*)&first)[i] ^ ((char*)&second)[i])); ++i);
	return ans;
}

#include <Windows.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <iterator>
//using std::cin;
//using std::cout;
//using std::setw;
//using std::right;
//using std::endl;
//using std::string;
//using std::vector;
//using std::fstream;
//using std::getline;
//using std::ios;
//using std::out_of_range;
//using std::fixed;
//using std::setprecision;
//using std::find_if;
//using std::for_each;
//using std::transform;
using namespace std;

template <class t>
bool Equal(const t &first, const t &second);

struct names
{
	int number;
	string name_b;
	friend istream& operator >> (istream& is, names& names)
	{
		is >> names.name_b >> names.number;
		return is;
	}
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
	float priz;
} m;
struct res
{
	int regn, num_sc;
	string dt;
	float iitg;
} r;

vector<names> vname;	// вектор для хранения записей таблицы NAMES
vector<plans> vplan;	// вектор для хранения записей таблицы PLAN
vector<money> vmoney;	// вектор для хранения записей таблицы 101F
vector<res> vres;		// вектор для хранения результатов

// запись данных из файла NAMES.txt в вектор
void read_names(const char* filename, vector<names>& vname)
{
	fstream names_file(filename, ios::in);
	istream_iterator<names>names_iter(names_file);
	istream_iterator<names>end_of_stream;
	copy(names_iter, end_of_stream, back_inserter(vname));
}
// запись данных из файла PLAN.txt в вектор
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
	catch (fstream::failure eb)	// Вот такая вот проверка конца файла
	{
		if (vplan[vplan.size() - 1].name != p.name) vplan.push_back(p);
		return;
	}
}
// запись данных из файла 101F.txt в вектор
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
	catch (fstream::failure eb)	// Вот такая вот проверка конца файла
	{
		if (!Equal(vmoney[vmoney.size() - 1], m)) vmoney.push_back(m);
		return;
	}
}
// получение наименования банка по его номеру
string get_name(int number, vector<names>&vname)
{
	return find_if(vname.begin(), vname.end(), [&](const names &n) { return (number == n.number); })->name_b;
}
// получение наименования счёта по его номеру
string get_plan(int num_sc, const vector<plans>&vplan)
{
	return find_if(vplan.begin(), vplan.end(), [&](const plans &p) { return (num_sc == p.num_sc); })->name;
}
// поиск записей, удовлетворяющих заданным условиям
void search_money(int regn, int num_sc, vector<money> vmoney, vector<res>& vres)
{
	for_each(vmoney.begin(), vmoney.end(), [&](const money &m) { if (m.regn == regn && m.num_sc == num_sc) vres.push_back({ m.regn, m.num_sc, m.dt, m.iitg }); });
	//transform(vmoney.begin(), vmoney.end(), vres, [&](const money &m)->res { if (m.regn == regn && m.num_sc == num_sc) return { m.regn, m.num_sc, m.dt, m.iitg }; });
}
// вывод результатов на экран
void show_res(const vector<res>&vres)
{
	for_each(vres.begin(), vres.end(), [](const res r) { cout << r.dt << setw(6) << " " << setw(7) << fixed << setprecision(0) << r.iitg << endl; });
}
// запись рузультатов в файл RESULT.txt
void write_res(char* filename, const vector<res> &vres)
{
	fstream myfile(filename, ios::out);
	for_each(vres.begin(), vres.end(), [&](const res r) { myfile << r.regn << " " << r.num_sc << " " << r.dt << " " << setw(7) << fixed << setprecision(0) << r.iitg << endl; });
}

int main()
{

	SetConsoleOutputCP(1251);

	char file_1[] = "NAMES.txt", file_2[] = "PLAN.txt", file_3[] = "101F.txt", file_4[] = "RESULT.txt";

	time_t dt = time(NULL);

	read_names(file_1, vname);	// подсчёт количества записей в файле NAMES.txt и заполнение вектора vname
	cout << "Загружено " << vname.size() << " записей из файла " << file_1 << endl;

	read_plans(file_2, vplan);	// подсчёт количества записей в файле PLAN.txt и заполнение вектора vname
	cout << "Загружено " << vplan.size() << " записей из файла " << file_2 << endl;

	read_money(file_3, vmoney);	// подсчёт количества записей в файле 101F.txt и заполнение вектора vname
	cout << "Загружено " << vmoney.size() << " записей из файла " << file_3 << endl;

	cout << "Время выполнения: " << -(dt -= time(NULL)) << endl;
	int regn, num_sc;
	string name, plan;
	while (1)
	{
		cout << endl << "Введите рег. номер банка: "; cin >> regn;
		if ((name = get_name(regn, vname)) != "")
			break;
		cout << "Банк не найден" << endl;
	}

	while (1)
	{
		cout << endl << "Введите номер счёта: "; cin >> num_sc;
		if ((plan = get_plan(num_sc, vplan)) != "")
			break;
		cout << "План не найден" << endl;
	}

	cout << endl << "Денежные остатки на счёте №" << num_sc << " \"" << plan << " \"" << endl;

	cout << endl << "Для банка №" << regn << " " << name << endl;

	cout << endl << setw(7) << right << "Дата" << setw(22) << "Сумма, тыс. руб." << endl;
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

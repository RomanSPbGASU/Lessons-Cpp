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
deque<person>deq, deq_1;	// объявление двух очередей с двусторонним доступом deq и deq_1 для данных типа person

// считывание данных из файла и запись их в контейнер deque
void read_f(const char*filename, deque<person>&d)
{
	fstream myfile(filename, ios::in);
	person p;
	while (myfile >> p.id >> p.fname >> p.iname >> p.salary)
		d.push_back(p);
}
// добавление содержимого одного контейнера к содержимому другого контейнера
void add_deq(deque<person>&from, deque<person>&to)
{
	// вариант 1
	int i = to.size();
	to.resize(from.size() + to.size());
	copy(from.begin(), from.end(), to.begin() + i);
	sort(to.begin(), to.end(), [](const person &p, const person &p2) { return p.id < p2.id; });

	//// вариант 2
	//sort(from.begin(), from.end(), [](const person &p, const person &p2){return p.id < p2.id;});
	//sort(to.begin(), to.end(), [](const person &p, const person &p2){return p.id < p2.id;});
	//deque<person>over(from.size() + to.size());
	//merge(from.begin(), from.end(), to.begin(), to.end(), over.begin(), [](const person &p, const person &p2){return p.id < p2.id;});
	//to.resize(from.size() + to.size());
	//copy(over.begin(), over.end(), to.begin());
}
 //вывод соддержимого контейнера на экран
void show_deq(deque<person>&d)
{
	for_each(d.begin(), d.end(), [](const person p) { cout << p.id << " " << p.fname << " " << p.iname << " " << p.salary << endl; });
}
// вывод содержимого контейнера в файл
void write_f(const char*filename, deque<person>&d)
{
	fstream myfile(filename, ios::out);
	for_each(d.begin(), d.end(), [&](const person p) { myfile << p.id << " " << p.fname << " " << p.iname << " " << p.salary << endl; });
}

int main()
{
	SetConsoleOutputCP(1251);

	const char* file = "list.txt", *file_1 = "list_1.txt", *file_2 = "list_res.txt";	// имена внешних файлов

	read_f(file, deq);	// считывание начального осписка из файла list.txt и запись его в контейнер deq
	read_f(file_1, deq_1);
	cout << "Начальный список..." << endl << endl;
	show_deq(deq);
	cout << endl << "Дополнительный список..." << endl << endl;
	show_deq(deq_1);
	cout << endl << "Обновлённый список..." << endl << endl;
	add_deq(deq, deq_1);
	show_deq(deq_1);
	write_f(file_2, deq_1);
	cout << endl;
	system("pause");
}
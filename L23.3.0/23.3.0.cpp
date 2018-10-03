#include <iostream>
#include <Windows.h>
#include <deque>
#include <fstream>
#include <iterator>
#include "employee.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	deque<employee> list;
	deque<employee> list_1;

	ifstream mylist("list.txt");
	ifstream mylist_1("list_1.txt");
	istream_iterator<employee> mylist_iter(mylist);
	istream_iterator<employee> mylist_1_iter(mylist_1);
	istream_iterator<employee> end_of_file;

	copy(mylist_iter, end_of_file, back_inserter(list));
	copy(mylist_1_iter, end_of_file, back_inserter(list_1));

	cout << "Содержимое списка из файла List.txt" << endl << endl;

	ostream_iterator<employee> os_iter(cout, "\n");
	copy(list.begin(), list.end(), os_iter);

	cout << endl << "Содержимое списка из файла List_1.txt" << endl << endl;

	copy(list_1.begin(), list_1.end(), os_iter);

	cout << endl << "Обновленный список (добавление в конец списка)" << endl << endl;

	deque<employee>::iterator list_iter = list.end();
	copy(list_1.begin(), list_1.end(), back_inserter(list));
	copy(list.begin(), list.end(), os_iter);

	cout << endl << "Восстановленный список" << endl << endl;

	list.erase(list_iter, list.end());
	copy(list.begin(), list.end(), os_iter);

	cout << endl << "Обновленный список (добавление в середину списка)" << endl << endl;

	copy(list_1.begin(), list_1.end(), inserter(list, list.begin() + 3));
	copy(list.begin(), list.end(), os_iter);

	cout << endl;
}
#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

struct person
{
	int number;
	char surname[15];
	char name[15];
	float salary;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream myfile("list_2.txt", ios::in | ios::binary);										// открыть поток для двоичного чтения
	person pers;
	myfile.seekg(0, ios::end);																	// поставить указатель в конец файла (буфера потока)
	cout << "В файле " << myfile.tellg() / (float)sizeof(pers) << " записей" << endl << endl;	// считать текущую позицию в потоке
	int n;																						// номер записи
	char answer;																				// ответ о продолжении ввода
	do
	{
		cout << "Введите номер записи: "; cin >> n; cout << endl;
		myfile.seekg(sizeof(person) * (n - 1), ios::beg);										// поставить указатель перед n-ным элементом
		myfile.read((char*)(&pers), sizeof(person));											// считать элемент типа person
		cout << pers.number << " "
			<< pers.surname << " "
			<< setw(15 - strlen(pers.surname)) << left << pers.name << " "
			<< fixed << setprecision(2) << pers.salary << endl << endl;
		cout << "Будем продолжать ввод? (д/н): "; cin >> answer; cout << endl;
	} while (answer == 'д');
		myfile.close();																			// закрыть файл
	system("pause");
}
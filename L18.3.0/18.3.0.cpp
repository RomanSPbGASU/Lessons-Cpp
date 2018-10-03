#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

void read_f(char*);
void write_f(char*, char*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* file = "list.txt", *file_1 = "list_1.txt";				// Имена внешних файлов

	cout << "Начальный список..." << endl << endl;
	read_f(file);													// вывод на экран начального списка из файла list.txt
	cout << "Дополнительный список..." << endl << endl;
	read_f(file_1);													// вывод на экран второго списка из файла list_1.txt
	write_f(file, file_1);											// добавление второго списка к первому списку
	cout << "Обновленный список..." << endl << endl;
	read_f(file);													// вывод на экран обновленного списка из файла list.txt
	system("pause");
}

void read_f(char*filename)
{
	fstream myfile(filename, ios::in | ios::_Nocreate);				// создание объекта класса fstream и инициализация его файлом, указываемым filename
	if (myfile.is_open() == 0) cout << "Ошибка открытия файла";		// проверка правильности открытия файла
	else
	{
		cout << myfile.rdbuf() << endl;								// вывод буфера потока myfile на экран
	}
	myfile.close();
}

void write_f(char*filename1, char*filename2)
{
	fstream myfile1(filename1, ios::app);							// открытие первого файла для записи в конец
	fstream myfile2(filename2, ios::in | ios::_Nocreate);			// открытие второго файла для чтения
	myfile1 << endl << myfile2.rdbuf();								// запись буфера потока, инициализированного вторым файлом в первый (в конец)
	myfile1.close();												// закрытие файлов
	myfile2.close();
}

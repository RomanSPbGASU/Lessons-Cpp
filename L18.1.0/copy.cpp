#include "copy.h"

void copyapp(char * from, char * to)
{
	SetConsoleOutputCP(1251);
	fstream myfile(from, ios::in);
	fstream myfile1(to, ios::out | ios::app);
	myfile1 << myfile.rdbuf();
	cout << "Файл " << (char*)from << " записан в файл " << (char*)to << endl;
}
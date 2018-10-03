#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class nameslist
{
private:
	struct names
	{
		double REGN;
		string NAME_B;
		names * next;
	} *first;
public:
	nameslist();
	int all_names(char*filename);	// создание списка
	void display();					// вывод списка всех банков на экран
	string get_single(int REGN);	// возвращает и выводит на экран наименование конкретного банка (NAME_B)
	~nameslist();
};
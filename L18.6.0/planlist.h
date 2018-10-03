#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class planlist
{
private:
	struct plan
	{
		string PLAN, NUM_SC, NAME;
		plan * next;
	} *first;
public:
	planlist();
	int all_names(char* filename);			// создает список
	void display();							// вывод списка на экран
	string get_single(string NUM_SC);	// вовзвращает и выводит на экран наименование денежного счёта (NAME)
	~planlist();
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class moneylist
{
private:
	struct money
	{
		double REGN, VR, VV, VITG, ORA, OVA, OITGA, ORP, OVP, OITGP, IR, IV, IITG, PRIZ;
		string PLAN, NUM_SC, A_P, DT;
		money * next;
	} *first;
public:
	moneylist();
	int all_names(char* filename);										// создание списка
	void display();														// вывод списка на экран
	void display_single(double REGN, string NUM_SC, char *filename);	// возвращает и выводит на экран и в файл сумму денежного остатка (IITG) на все отчетные даты
	~moneylist();
};
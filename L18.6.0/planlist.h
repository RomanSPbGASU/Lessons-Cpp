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
	int all_names(char* filename);			// ������� ������
	void display();							// ����� ������ �� �����
	string get_single(string NUM_SC);	// ����������� � ������� �� ����� ������������ ��������� ����� (NAME)
	~planlist();
};
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
	int all_names(char*filename);	// �������� ������
	void display();					// ����� ������ ���� ������ �� �����
	string get_single(int REGN);	// ���������� � ������� �� ����� ������������ ����������� ����� (NAME_B)
	~nameslist();
};
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

planlist::planlist()
{
	first = NULL;
}

int planlist::all_names(char* filename)
{
	fstream myfile(filename, ios::in);
	int count = 0;
	//plan *next;
	while (1)
	{
		next = first;
		first = new plan;							// ��������� ������ ��� ����� �������
		getline(myfile, first->PLAN, ';');			// ���������� ���������� ����������� �����
		getline(myfile, first->NUM_SC, ';');		// ���������� ������ �����
		getline(myfile, first->NAME);				// ���������� �������� �����
		first->next = next;
		if (!myfile)
		{
			first = first->next;
			break;
		}
		count++;
	}
	return count;

}

void planlist::display()
{
	plan *current = first;
	while (current)
	{
		cout << current->PLAN << " " << setw(5) << left << current->NUM_SC << " " << current->NAME << endl;
		current = current->next;
	}
}
string planlist::get_single(string number)
{
	plan * current = first;
	while (current->NUM_SC != number)
	{
		current = current->next;
		if (current->next == NULL)
		{
			cout << "������. ���� �� ������" << endl;
			return "\0";
		}
	}
	return current->NAME;
}

planlist::~planlist()
{
	plan* current = first;							// ���������� ��������� �� ������ �������
	while (current != NULL)						// ����� �� ���������� ���������� ��������
	{
		plan* temp = current;						// ��������� ��������� �� ������ �������
		current = current->next;					// �������� ������ �� ��������� �������
		delete temp;								// ������� ������� �������
	}
	cout << "�������� ������� ������� PLAN" << endl;
}
#include "nameslist.h"

nameslist::nameslist()
{
	first = NULL;
}

int nameslist::all_names(char* filename)
{
	fstream myfile(filename, ios::in);
	int count = 0;
	names *next;
	while (1)
	{
		next = first;
		first = new names;							// ��������� ������ ��� ����� �������
		myfile >> first->REGN;						// ���������� ���������������� ������
		myfile.get();								// ���������� ����������� (����� ������ ��� �� ������)
		getline(myfile, first->NAME_B);				// ���������� �������� �����
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

void nameslist::display()
{
	names *current = first;
	while (current)
	{
		cout << current->REGN << " " << current->NAME_B << endl;
		current = current->next;
	}
}

string nameslist::get_single(int number)
{
	names * current = first;
	while (current->REGN != number)
	{
		current = current->next;
		if (current->next == NULL)
		{
			cout << "������. ���� �� ������" << endl;
			return "\0";
		}
	}
	return current->NAME_B;
}

nameslist::~nameslist()
{
	names* current = first;							// ���������� ��������� �� ������ �������
	while (current != 0)							// ����� �� ���������� ���������� ��������
	{
		names* temp = current;						// ��������� ��������� �� ������ �������
		current = current->next;					// �������� ������ �� ��������� �������
		delete temp;								// ������� ������� �������
	}
	cout << "�������� ������� ������� NAMES" << endl;
}
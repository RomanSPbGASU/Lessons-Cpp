#pragma once
#include <Windows.h>

template<class Type>											// ����� linklist<Type>
class linklist													// ��������� ������ (������ ����� ������ Linklist �������� linklist<Type>)
{
private:
	template<class Type>										// ��������� link<Type>
	struct link													// ������� ������ (������ ���� ��������� ����������� link �������� link<Type>)
	{
		Type data;												// ������� ������
		link* next;												// ��������� �� ��������� �������
	}; 
	link<Type> *first;											// ��������� �� ������ ������
public:
	linklist();													// ����������� ��� ����������
	void additem(Type d);										// �������� ���� ������� ������
	void display();												// ������� ���� ������
};


template<class Type>
linklist<Type>::linklist()
{
	first = NULL;												// ������ ����
}

template<class Type>
void linklist<Type>::additem(Type d)							// ���������� ������
{
	if (first == NULL)											// ���� ������ ������� �����������
	{
		first = new link<Type>;									// �������� ������ ��� ������ �������
		first->data = d;										// ��������� ������ � ������ ��������
		first->next = NULL;										// ������ �� ��������� ������� ����� NULL
	}
	else														// ���� ������ ������� ������
	{
		link<Type> *current = first;							// ������� ������� - ������
		while (current->next != NULL) current = current->next;	// ������� �� ���������� ��������
		current->next = new link<Type>;							// �������� ������ ��� ����� ������� (��������� �� ���������)
		current->next->data = d;								// ��������� ������ � ����� �������
		current->next->next = NULL;								// ������ �� ��������� ������� ����� NULL
	}
}

template<class Type>
void linklist<Type>::display()									// ����� ����� ������
{
	link<Type>* current = first;								// ��������� - �� ������ ������
	while (current != NULL)										// ������ ���� ������
	{
		cout << current->data << endl;							// ������� �� ����� ������
		current = current->next;								// ������� � ���������� ��������
	}
}
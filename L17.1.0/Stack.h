#pragma once
// ���������� ������� �������� � ������������ �������
#include <iostream>
#include <Windows.h>
using namespace std;
#include <process.h>		 // ��� exit()

class Stack
{
protected:					// ���������: ������������ private ������
	enum { MAX = 4 };		// ������ �����
	int st[MAX];			// ������, ���������� � �����
	int top;				// ������ ���������� �������� � �����
public:
	Stack();				// �����������
	void put(int);			// ��������� ����� � ����
	int pop();				// ���������� ����� �� �����

};
#include "stock.h"

struct link
{
	stock Stock;
	link *next;
};

class Stack
{
protected:
	link *head;
public:
	Stack();
	~Stack();
	void add(char * name, char * type, int amount, float price); //���������� ��������
	void remove(); //�������� �������� (���������� ������������)
	void display() const; //����� ��������� �� �����
	stock get() const; //��������� ���������� ��������
};
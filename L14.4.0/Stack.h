#include <circle.h> // ��� circle

struct link
{
	circle Circle;
	link *next;
};

class Stack
{
protected:
	link *head;
public:
	Stack();
	~Stack();
	void add(COORD centre, int radius, COLORREF color); //���������� ��������
	void remove(); //�������� �������� (���������� ������������)
	void display(); //����� ��������� �� �����
};
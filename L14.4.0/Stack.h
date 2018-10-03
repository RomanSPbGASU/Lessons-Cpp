#include <circle.h> // для circle

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
	void add(COORD centre, int radius, COLORREF color); //добавление элемента
	void remove(); //удаление элемента (последнего добавленного)
	void display(); //вывод элементов на экран
};
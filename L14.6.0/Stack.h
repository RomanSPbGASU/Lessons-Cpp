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
	void add(char * name, char * type, int amount, float price); //добавление элемента
	void remove(); //удаление элемента (последнего добавленного)
	void display() const; //вывод элементов на экран
	stock get() const; //получение последнего элемента
};
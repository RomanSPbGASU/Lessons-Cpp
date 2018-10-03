
#include "ring.h"

struct link
{
	ring Ring;
	link *next;
};

class ringlist
{
protected:
	link *head;
public:
	ringlist();
	~ringlist();
	void add(COORD center, short radius, int linestyle, int linewidth, COLORREF color); //добавление элемента
	void remove(); //удаление элемента (последнего добавленного)
	void display(); //вывод элементов на экран
};
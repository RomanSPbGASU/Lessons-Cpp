#include <iostream>
using namespace std;

class linklist
{
protected:
	struct link
	{
		int data;
		link* next;
	};
	link* first;
public:
	linklist();
	~linklist();
	void additem(int d);
	void display();
};
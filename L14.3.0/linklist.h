struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;
public:
	linklist();
	~linklist();
	void additem(int d);
	void display();
};
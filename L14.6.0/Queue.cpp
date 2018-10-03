#include "Queue.h"
using namespace std;

	Queue::Queue()
	{
		head = MAX - 1;
		tail = 0;
		count;
	}
	Queue::~Queue()
	{
		//if (qu) delete qu; // не понимаю, как написать деструктор
	}
	void Queue::put(char * name, char * type, int amount, float price)
	{
		head = ++head % MAX;
		if (count == 10)
		{
			head--;
		}
		else
		{
			qu[head] = { name, type, amount, price };

			count = 0;
			int c = head;
			do
			{
				c--;
				if (c == -1) c = MAX - 1;
				count++;
			} while (c != (tail == 0 ? MAX - 1 : tail - 1));
		}
	}
	stock Queue::get()
	{
		if (count != 0)
		{
			stock last(qu[tail].get_name(), qu[tail].get_type(), qu[tail].get_amount(), qu[tail].get_price());
			tail = ++tail % MAX;
			return last;
		}
	}
	void Queue::remove()
	{
		if (count != 0)
		{
			head--;
		}
	}
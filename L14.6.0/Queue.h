#include "stock.h"

class Queue
{
	private:
		static const int MAX = 10;
		stock qu[MAX];
		int head;
		int tail;
		int count;
	public:
		Queue();
		~Queue();
		void put(char * name, char * type, int amount, float price);
		stock get();
		void remove();
};
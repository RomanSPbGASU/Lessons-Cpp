
template <class ntype>
class Queue
{
private:
	static const int MAX = 10;	
	ntype qu[MAX];					// очередь не более чем из MAX элементов
	int head;						// номер головного элемента очереди
	int tail;						// номер хвостового элемента очереди
	int count;						// количество элементов в очереди
public:
	Queue();
	void put(ntype var);
	void get();
};

template <class ntype>
Queue<ntype>::Queue()
{
	head = MAX - 1;
	tail = 0;
	count = 0;
}

template <class ntype>
void Queue<ntype>::put(ntype var)
{
	head = ++head % MAX;
	if (count == 10)
	{
		cout << "Массив полон" << endl;
		head--;
	}
	else
	{
		qu[head] = var;

		count = 0;
		int c = head;
		do
		{
			c--;
			if (c == -1) c = MAX - 1;
			count++;
		} while (c != (tail == 0 ? MAX - 1 : tail - 1));

		cout << "Элемент " << var << " помещен в очередь. Всего в очереди " << count
			<< (count == 1 ? " элемент" : (count >= 5 ? " элементов" : " элемента")) << endl;
	}
}

template <class ntype>
void Queue<ntype>::get()
{
	if (count == 0) cout << "Массив пуст" << endl;
	else
	{
		cout << "Элемент " << qu[tail] << " извлечён из очереди. Всего в очереди " << --count;	// почему, если писать одной строкой, условная операция выполняется до декримента?
		cout << (count == 1 ? " элемент" : (count >= 5 || count == 0 ? " элементов" : " элемента")) << endl;
		tail = ++tail % MAX;
	}
}
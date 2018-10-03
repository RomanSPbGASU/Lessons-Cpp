#include <Windows.h>
#include "Distance.h"
//#include "Queue.h"



template <class ntype>
class Queue
{
private:
	static const int MAX = 10;
	ntype qu[MAX];							// очередь не более чем из MAX элементов
	int head;								// номер головного элемента очереди
	int tail;								// номер хвостового элемента очереди
	int count;								// количество элементов в очереди
public:
	class Error								// класс исключений
	{
	public:
		char* mis;							// тип ошибки
		char* type;							// тип данных
		Error(char* misname) : mis(misname)
		{
			type = typeid(ntype).name();	// получили имя типа данных
		}
	};
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
		throw Queue::Error("заполнена");
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
	if (count == 0) throw Queue::Error("пуста");
	else
	{
		cout << "Элемент " << qu[tail] << " извлечён из очереди. Всего в очереди " << --count;	// почему, если писать одной строкой, условная операция выполняется до декримента?
		cout << (count == 1 ? " элемент" : (count >= 5 || count == 0 ? " элементов" : " элемента")) << endl;
		tail = ++tail % MAX;
	}
}










int main()
{
	SetConsoleOutputCP(1251);
	Queue<char*> arr1;							// очередь из строк char
	Queue<float> arr2;							// очередь типа float
	Queue<Distance> arr3;						// очередь типа Distance

	try
	{
		arr1.put("Понедельник");
		arr1.put("Вторник");
		arr1.get();
		arr1.put("Среда");
		arr1.get();
		arr1.get();

		arr2.put(77.77);
		arr2.put(88.88);
		arr2.put(99.99);
		arr2.get();
		arr2.put(111.11);
		arr2.get();
		arr2.get();
		arr2.get();

		arr3.put(25.1648);
		arr3.put(144.2518);
		arr3.get();
		arr3.put(4.9914);
		arr3.get();
		arr3.get();
	}
	catch (Queue</*...*/>::Error err)
	{


		cout << "Ошибка: очередь Queue<" << err.type << "> " << err.mis << endl;
	}

	system("pause");
}
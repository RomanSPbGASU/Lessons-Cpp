#include <Windows.h>
#include "Distance.h"
//#include "Queue.h"



template <class ntype>
class Queue
{
private:
	static const int MAX = 10;
	ntype qu[MAX];							// ������� �� ����� ��� �� MAX ���������
	int head;								// ����� ��������� �������� �������
	int tail;								// ����� ���������� �������� �������
	int count;								// ���������� ��������� � �������
public:
	class Error								// ����� ����������
	{
	public:
		char* mis;							// ��� ������
		char* type;							// ��� ������
		Error(char* misname) : mis(misname)
		{
			type = typeid(ntype).name();	// �������� ��� ���� ������
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
		throw Queue::Error("���������");
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

		cout << "������� " << var << " ������� � �������. ����� � ������� " << count
			<< (count == 1 ? " �������" : (count >= 5 ? " ���������" : " ��������")) << endl;
	}
}

template <class ntype>
void Queue<ntype>::get()
{
	if (count == 0) throw Queue::Error("�����");
	else
	{
		cout << "������� " << qu[tail] << " �������� �� �������. ����� � ������� " << --count;	// ������, ���� ������ ����� �������, �������� �������� ����������� �� ����������?
		cout << (count == 1 ? " �������" : (count >= 5 || count == 0 ? " ���������" : " ��������")) << endl;
		tail = ++tail % MAX;
	}
}










int main()
{
	SetConsoleOutputCP(1251);
	Queue<char*> arr1;							// ������� �� ����� char
	Queue<float> arr2;							// ������� ���� float
	Queue<Distance> arr3;						// ������� ���� Distance

	try
	{
		arr1.put("�����������");
		arr1.put("�������");
		arr1.get();
		arr1.put("�����");
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


		cout << "������: ������� Queue<" << err.type << "> " << err.mis << endl;
	}

	system("pause");
}
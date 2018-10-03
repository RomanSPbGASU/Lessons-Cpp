#include <conio.h>
#include <iostream>

using namespace std;

class Queue
{
private:
	static const int MAX = 10;
	int qu[MAX];
	int head;
	int tail;
	int count;
public:
	Queue() 
	{
		head = MAX - 1;
		tail = 0;
		count;
	}
	void put(int var)
	{
		head = ++head % MAX;
		if (count == 10)
		{
			cout << "������ �����" << endl;
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
				<< (count == 1 ? " �������" : (count > 4 || count < 2 ? " ���������" : " ��������"))  << endl; // ��� ������ �����?
		}
	}
	void get()
	{
		if (count == 0) cout << "������ ����" << endl;
		else
		{
			cout << "������� " << qu[tail] << " �������� �� �������. ����� � ������� " << --count
				<< (count == 1 ? " �������" : (count > 4 || count < 2 ? " ���������" : " ��������")) << endl;
			tail = ++tail % MAX;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Queue q1;
	q1.put(22);
	q1.put(11);
	q1.get();
	q1.get();
	q1.put(33);
	q1.put(44);
	q1.put(55);
	q1.put(66);
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	//
	q1.get();
	//
	q1.put(111);
	q1.put(112);
	q1.put(113);
	q1.put(114);
	q1.put(125);
	q1.put(116);
	q1.put(117);
	q1.put(118);
	q1.put(119);
	q1.put(120);
	q1.put(121);
	//
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	q1.get();
	_getche();
}

template <class ntype>
class Queue
{
private:
	static const int MAX = 10;	
	ntype qu[MAX];					// ������� �� ����� ��� �� MAX ���������
	int head;						// ����� ��������� �������� �������
	int tail;						// ����� ���������� �������� �������
	int count;						// ���������� ��������� � �������
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
			<< (count == 1 ? " �������" : (count >= 5 ? " ���������" : " ��������")) << endl;
	}
}

template <class ntype>
void Queue<ntype>::get()
{
	if (count == 0) cout << "������ ����" << endl;
	else
	{
		cout << "������� " << qu[tail] << " �������� �� �������. ����� � ������� " << --count;	// ������, ���� ������ ����� �������, �������� �������� ����������� �� ����������?
		cout << (count == 1 ? " �������" : (count >= 5 || count == 0 ? " ���������" : " ��������")) << endl;
		tail = ++tail % MAX;
	}
}
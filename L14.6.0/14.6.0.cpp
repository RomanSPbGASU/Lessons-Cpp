// ��� ��������� (��� �������) ������ � ������ FIFO?
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include "Stack.h"
#include "Queue.h"
#include "Average.h"
using namespace std;

struct trans
{
	int SecOperation;
	stock Securities; // ������ ������
};

float LIFO(trans);
float FIFO(trans);
float APRICE(trans); // average price - ������� ����

//���� ��������� ������ � main, �� ������� ��� �� ������
Stack stack_of_transactions; //�������� ���� ��� ������ LIFO
Queue queue_of_transactions; //�������� ������� ��� ������ FIFO
Average aprice_of_transactions; // �������� ������ ��� ������ ������� ����

float sumLIFO = 0;
float sumFIFO = 0;
float sumAPRICE = 0;

void main()
{
	trans t[8] = { { 1,{ "��������", "�����", 500, 331.50f } },
				  { 1,{ "��������", "�����", 500, 344.09f } },
				  { 1,{ "��������", "�����", 500, 362.62f } },
				  { 1,{ "��������", "�����", 500, 372.68f } },
				  { 1,{ "��������", "�����", 500, 351.45f } },
				  { 0,{ "��������", "�����", 500, 333.74f } },
				  { 0,{ "��������", "�����", 500, 315.96f } },
				  { 0,{ "��������", "�����", 500, 301.28f } }
				};
	SetConsoleOutputCP(1251);
	cout << setw(60) << "������ ����������� ���������� �� ������� � ��" << endl << endl;
	cout << setw(17) << "������������ ��: " << t[0].Securities.get_name() << endl;
	cout << setw(17) << left << "��� ��: " << t[0].Securities.get_type() << endl << endl;
	cout << setw(12) << left << "��� ������" << setw(12) << "���-��, ��." << setw(12) << "����, ���."
		<< setw(12) << "����� LIFO" << setw(12) << "����� FIFO" << setw(16) << "����� ��. ����"
		<< endl << endl;

	for (int i = 0; i < sizeof(t)/sizeof(trans); i++)
	{
		cout << setw(12) << left << (t[i].SecOperation ? " �������" : " �������") << right << setw(7)
			<< t[i].Securities.get_amount() << setw(13) << fixed << setprecision(2) 
			<< t[i].Securities.get_price() << setw(14)
			 << LIFO(t[i]) << setw(12)
			<< FIFO(t[i]) << setw(14)
			<< APRICE(t[i]) << endl;
	}

	cout << "\n�����: " << setw(39) << right << fixed << setprecision(2)
		<< sumLIFO << setw(12)
		<< sumFIFO << setw(14)
		<< sumAPRICE << endl;

	system("pause");
}

float LIFO(trans transaction)
{
	// ���� �������� �����, �� ������ ��������� ������� � "��������"
	if (transaction.SecOperation == 1)
	{
		stack_of_transactions.add(transaction.Securities.get_name(), transaction.Securities.get_type(),
			 transaction.Securities.get_amount(), transaction.Securities.get_price());
		return 0;
	}
	// ���� ������� �����, �� �������� �� ������� "��������" � ������� ������� "��������"
	else
	{
		stock last_stock;
		last_stock = stack_of_transactions.get(); 
		stack_of_transactions.remove();
		sumLIFO += (transaction.Securities.get_price() - last_stock.get_price()) * transaction.Securities.get_amount();
		return(transaction.Securities.get_price() - last_stock.get_price()) * transaction.Securities.get_amount();
	}
}

float FIFO(trans transaction)
{
	if (transaction.SecOperation == 1)
	{
		queue_of_transactions.put(transaction.Securities.get_name(), transaction.Securities.get_type(),
			transaction.Securities.get_amount(), transaction.Securities.get_price());
		return 0;
	}
	else
	{
		stock last_stock;
		last_stock = queue_of_transactions.get();
		queue_of_transactions.remove();
		sumFIFO += (transaction.Securities.get_price() - last_stock.get_price()) * transaction.Securities.get_amount();
		return(transaction.Securities.get_price() - last_stock.get_price()) * transaction.Securities.get_amount();
	}
}

float APRICE(trans transaction)
{
	if (transaction.SecOperation == 1)
	{
		aprice_of_transactions.buy(transaction.Securities.get_amount(), transaction.Securities.get_price());
		return 0;
	}
	else
	{
		sumAPRICE += aprice_of_transactions.sale(transaction.Securities.get_amount(), transaction.Securities.get_price());
		return aprice_of_transactions.sale(transaction.Securities.get_amount(), transaction.Securities.get_price());
	}
}
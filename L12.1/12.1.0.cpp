#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int tarif = 80;

class gate
{
private:
	unsigned int payCars;
	unsigned int nopayCars;
	unsigned int totalCash;
public:
	gate() : payCars(0), nopayCars(0), totalCash(0)
	{}
	void payingCars() //����� ������, ��������������� ���������� ���������� �������� �����
	{                 //� ������������� ��������� �������
		payCars++;
		totalCash ++;
	}
	void nopayingCars() //����� ������, ��������������� ���������� �� ���������� �������� �����
	{
		nopayCars++;
	}
	void showCash() //����� ������, ��������� ���������� �� �����
	{
		cout << "\n���������� ���������� �����: " << payCars+nopayCars << endl;
		cout << "�� ���: /n�������� ��������: " << payCars << endl;
		cout << "�� �������� ��������: " << nopayCars << endl;
		cout << "����� ����� �������: " << totalCash*tarif << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	gate d1;
	cout << "\n������� �������: \n+ ��� ������ ���������� ������" << "\n- ��� ������ ������ ��� ������" << "\nEsc ��� ������" << endl;
	char character;
	do
	{
		character = _getche();
		if (character == '+') d1.payingCars();
		if (character == '-') d1.nopayingCars();
		if (character == 27) d1.showCash();
	} while (character == '+' || character == '-' || character != 27);
	_getche();
}
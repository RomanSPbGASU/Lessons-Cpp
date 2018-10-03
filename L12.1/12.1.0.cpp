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
	void payingCars() //метод класса, инкременирующий количество оплативших парковку машин
	{                 //и увеличивающий суммарную выручку
		payCars++;
		totalCash ++;
	}
	void nopayingCars() //метод класса, инкреминирующий количество не оплативших парковку машин
	{
		nopayCars++;
	}
	void showCash() //метод класса, выводящий результаты на экран
	{
		cout << "\nКоличество проехавших машин: " << payCars+nopayCars << endl;
		cout << "Из них: /nоплатили парковку: " << payCars << endl;
		cout << "не оплатили парковку: " << nopayCars << endl;
		cout << "Общая сумма выручки: " << totalCash*tarif << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	gate d1;
	cout << "\nНажмите клавиши: \n+ для каждой оплатившей машины" << "\n- для каждой машины без оплаты" << "\nEsc для выхода" << endl;
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
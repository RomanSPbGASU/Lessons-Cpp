#include <iostream>
#include <windows.h>
#include <list>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	char cArg[] = "Аргентина манит негра";
	list<char> lArg(cArg, cArg + sizeof(cArg) - 1);
	list<char>::iterator iter;
	cout << "Прямой проход..." << endl << endl;
	for (iter = lArg.begin(); iter != lArg.end(); iter++)
		cout << *iter;
	cout << endl << endl;
	cout << "Обратный проход..." << endl << endl;
	list<char>::reverse_iterator reviter;
	for (reviter = lArg.rbegin(); reviter != lArg.rend(); reviter++)
		cout << *reviter;
	cout << endl << endl;
}
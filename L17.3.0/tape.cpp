#include "tape.h"

void tape::getdata()
{
	publication::getdata();
	cout << "Введите время звучания: "; cin >> time;
	sales::getdata();
}
void tape::putdata()
{
	publication::putdata();
	cout << "Время звучания: " << time << endl;
	sales::putdata();
}
#include "tape.h"

void tape::getdata()
{
	publication::getdata();
	cout << "������� ����� ��������: "; cin >> time;
	sales::getdata();
}
void tape::putdata()
{
	publication::putdata();
	cout << "����� ��������: " << time << endl;
	sales::putdata();
}
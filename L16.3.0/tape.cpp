#include "tape.h"

void tape::getdata()
{
	publication::getdata();
	cout << "������� ����� ��������: "; cin >> time; cout << "\n";
}
void tape::putdata()
{
	publication::putdata();
	cout << "����� ��������: " << time << endl;
}
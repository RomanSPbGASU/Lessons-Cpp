#include "time.h"

void main()
{
	const time t1(2,00,00), t2(0,45,00);
	time t3, t4, t5;
	t3 = t1 + t2;
	t4 = t1 - t2;
	t5 = t1 * t2; // КАК вообще перемножать время?
	cout << "time1 = "; t1.print();
	cout << "\ntime2 = "; t2.print();
	cout << "\ntime3 = "; t3.print();
	cout << "\ntime4 = "; t4.print();
	cout << "\ntime5 = "; t5.print();
	cout << "\n";
	system("pause");
}
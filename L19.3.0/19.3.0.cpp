// не совсем разобрался с перегрузкой <<
#include "time.h"

void main()
{
	const time t1(2, 00, 00), t2(0, 45, 00);
	time t3, t4, t5;

	cout << "time1 = " << t1 << endl;
	cout << "time2 = " << t2 << endl;
	cout << "time3 = time1 + time2 = " << t1 + t2 << endl;
	cout << "time4 = time1 - time2 = " << t1 - t2 << endl;
	cout << "time5 = time1 * time2 = " << t1 * t2 << endl;  // КАК вообще перемножать время?

	system("pause");
}
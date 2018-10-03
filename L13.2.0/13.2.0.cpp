#include <iostream>
#include <conio.h>
using namespace std;

class time
{
private:
	int hrs;
	int mts;
	int sds;
public:
	time() : hrs (0), mts (0), sds (0) {}
	time(int hours, int minutes, int seconds) : hrs(hours), mts(minutes), sds(seconds) {}
	void print() const
	{
		cout << hrs << ":" << mts << ":" << sds;
	}
	void add_time(time t1, time t2)				// как я понимаю, в задании сказано, что в случае,
	{											// если время больше 11:59:59, начинать отсчет заново, 
		sds = t1.sds + t2.sds;					// но тогда этим классом нельзя  будет пользоваться(
		if (sds > 60) { mts++; sds -= 60; }
		mts = t1.mts + t2.mts;
		if (mts > 60) { hrs++; mts -= 60; }
		hrs = t1.hrs + t2.hrs;
	}
	void ded_time(time t1, time t2)
	{
		sds = t1.sds - t2.sds;
		if (sds < 0) { mts--; sds += 60; }
		mts = t1.mts - t2.mts;
		if (mts < 0) { hrs--; mts += 60; }
		hrs = t1.hrs - t2.hrs;
	}
};

void main()
{
	const time t1(1, 23, 45);
	const time t2(2, 34, 56);
	time t3, t4;
	t3.add_time(t1, t2);
	t4.ded_time(t1, t2);
	cout << "time1 = "; t1.print();
	cout << "\ntime2 = "; t2.print();
	cout << "\ntime3 = "; t3.print();
	cout << "\ntime4 = "; t4.print();
	_getche();
}
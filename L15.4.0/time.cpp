#include "time.h"

time::time() : hrs(0), mts(0), sds(0)
{ }
time::time(int hours, int minutes, int seconds) : hrs(hours), mts(minutes), sds(seconds)
{ }
void time::print() const
{
	//if (hrs < 0) cout << hrs << ":" << setfill('0') << setw(2) << -mts << ":" << -sds; // когда подключаю <iomanip> ругается на time
	//else cout << hrs << ":" << setfill('0') << setw(2) << mts << ":" << sds;
	if (hrs < 0) cout << hrs << ":" << -mts << ":" << -sds;
	else cout << hrs << ":" << mts << ":" << sds;
}
time time::operator + (const time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) + (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // сумма времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return time(hours, minuts, seconds);
}
time time::operator - (const time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) - (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // разность времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return time(hours, minuts, seconds);
}
time time::operator * (const time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) * (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // разность времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return time(hours, minuts, seconds);
}
#include "time.h"

time::time() : hrs(0), mts(0), sds(0)
{ }

time::time(int hours, int minutes, int seconds) : hrs(hours), mts(minutes), sds(seconds)
{ }

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

ostream &(operator <<) (ostream &os, const time &t)
{
	os << t.hrs << ":" << t.mts << ":" << t.sds;
	return os;
}
#include <iomanip>
#include <fstream>
#include <iostream>
using std::ostream;
using std::setfill;
using std::setw;

class Time
{
private:
	int hrs;
	int mts;
	int sds;
public:
	Time();
	Time(unsigned int, unsigned int, unsigned int);
	Time operator + (const Time) const;
	Time operator - (const Time) const;
	Time operator * (const Time) const;
	friend ostream& operator << (ostream&, const Time&);	// смотрел здесь: https://msdn.microsoft.com/ru-ru/library/1z2f6c2k.aspx
};

Time::Time() : hrs(0), mts(0), sds(0)
{}

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds)/* : hrs(hours), mts(minutes), sds(seconds)*/
{	
	hrs = hours;
	mts = minutes;
	sds = seconds;
}

Time Time::operator + (const Time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) + (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // сумма времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return Time(hours, minuts, seconds);
}

Time Time::operator - (const Time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) - (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // разность времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return Time(hours, minuts, seconds);
}

Time Time::operator * (const Time t2) const
{
	int seconds = (hrs * 3600 + mts * 60 + sds) * (t2.hrs * 3600 + t2.mts * 60 + t2.sds); // разность времени в секундах
	int minuts = seconds / 60;
	int hours = minuts / 60;
	seconds %= 60;
	minuts %= 60;
	return Time(hours, minuts, seconds);
}

ostream &(operator <<) (ostream &os, const Time &t)
{
	os << setfill('0') << setw(2) << t.hrs << ":" << setw(2) << t.mts << ":" << setw(2) << t.sds;
	return os;
}
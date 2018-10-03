#pragma once
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<conio.h>

using namespace std;

class Time
{
private:
		int hours, mins, secs;
 public:
		Time() :hours(0), mins(0), secs(0)//нулевые значения
		{};
		Time(int h, int m, int sec) : hours(h), mins(m), secs(sec)//заданный набор значений
		{};
		Time operator+(const Time t1)
		{
			int secs1 = secs + t1.secs;
			int mins1 = mins + t1.mins;
			int hours1 = hours + t1.hours;

			//int mins1 = 0;
			if (secs1 > 59)
			{
				secs1 -= 60;
				mins1++;
			}
			
			//int hours1 = 0;
			if (mins1 > 59)
			{
				mins1 -= 60;
				hours1++;
			}
			
			return(Time(hours1, mins1, secs1));
		}
		Time operator-(const Time t1) 
		{
			int secs1 = secs - t1.secs;
			int mins1 = mins - t1.mins;
			int hours1 = hours - t1.hours;

			//int mins1 = 0;
			if (secs1 < 0)
			{
				secs1 += 60;
				mins1--;
			}
			//int hours1 = 0;
			if (mins1 < 0)
			{
				mins1 += 60;
				hours1--;
			}
			return(Time(hours1, mins1, secs1));
		}
		Time operator*(const Time t1) 
		{
			int hours1 = hours * 60 * 60;
			int h1 = t1.hours * 60 * 60;
			int mins1 = mins * 60;
			int m1 = t1.mins * 60;

			int	sum1 = hours1 + mins1 + secs;
			int sum2 = h1 + m1 + t1.secs;
			float secs1 = sum1 * sum2;
			hours1 = 0; h1 = 0;
			secs1 /= 3600;
			while (secs1 >= 60)
			{
				secs1 -= 60;
				mins1++;
			}
			while (mins1 >= 60)
			{
				mins1 -= 60;
				hours1++;
			}
	    return(Time(hours1, mins1, secs1));
	}
		friend ostream& operator << (ostream&, const Time t);
};
ostream& operator << (ostream& os, const Time t)
{
	if (t.hours < 10)
		os << "0" << t.hours << ":";
	else
		os << t.hours << ":";
	if (t.mins < 10)
		os << "0" << t.mins << ":";
	else
		os << t.mins << ":";
	if (t.secs < 10)
		os << "0" << t.secs;
	else
		os << t.secs;
	return os;
}
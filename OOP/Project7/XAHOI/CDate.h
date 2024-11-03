#pragma once
#ifndef _CDate
#define _CDate
#include <iostream>
using namespace std;

class CDate {
private:
	int Day, Month, Year;
public:
	CDate(int newday = 1, int newmonth = 1, int newyear = 1);
	friend istream& operator>>(istream& is, CDate& date);
	friend ostream& operator<<(ostream& os, CDate date);
	int MaxDay_of_Month();
	bool CheckDate();
	CDate operator+(int newday);
	CDate operator-(int newday);
	CDate operator++();
	CDate operator++(int);
	CDate operator--();
	CDate operator--(int);
	int operator-(CDate b);
};

#endif // !

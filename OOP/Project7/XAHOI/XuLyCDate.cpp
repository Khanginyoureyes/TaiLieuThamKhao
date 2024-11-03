#include "CDate.h"

CDate::CDate(int newday, int newmonth, int newyear) {
	Day = newday;
	Month = newmonth;
	Year = newyear;

}
int CDate::MaxDay_of_Month()
{
	switch (Month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if ((Year % 4 == 0 && Year % 100 != 0)) return 29;
		else return 28;
	}
}
bool CDate::CheckDate()
{
	if (Month > 12 || Month <= 0) return false;
	if (Day > MaxDay_of_Month()) return false;
	return true;
}
istream& operator>>(istream& is, CDate& date) {
	do
	{
		cout << "Nhap ngay: ";
		is >> date.Day;
		cout << "Nhap thang: ";
		is >> date.Month;
		cout << "Nhap nam: ";
		is >> date.Year;
	} while (date.CheckDate() == false);
	return is;
}

ostream& operator<<(ostream& os, CDate date) {
	os << date.Day << "/" << date.Month << "/" << date.Year;
	return os;
}
CDate CDate::operator+(int newday) {
	CDate tong(Day, Month, Year);
	tong.Day += newday;
	if (tong.Day > tong.MaxDay_of_Month())
	{
		tong.Day -= tong.MaxDay_of_Month();
		tong.Month++;
		if (tong.Month > 12)
		{
			tong.Month = 1;
			tong.Year++;
		}
	}
	return tong;
}

CDate CDate::operator-(int newday) {
	CDate hieu(Day, Month, Year);
	hieu.Day = hieu.Day - newday;
	if (hieu.Day < 1)
	{
		if (hieu.Month == 1)
		{
			hieu.Month = 12;
			hieu.Year--;
		}
		else hieu.Month--;
		hieu.Day += hieu.MaxDay_of_Month();
	}
	return hieu;
}

CDate CDate::operator++()
{
	*this = *this + 1;
	return *this;
}

CDate CDate::operator++(int) {
	CDate temp = *this;
	*this = *this + 1;
	return temp;
}

CDate CDate::operator--() {
	*this = *this - 1;
	return *this;
}

CDate CDate::operator--(int) {
	CDate temp = *this;
	*this = *this - 1;
	return temp;
}

int CDate::operator-(CDate b) {
	//tinh so ngay

	int time = 0;
	int year = 0;
	CDate temp;

	//tinh dau nam toi a
	temp.Year = Year;
	while (temp.Month != Month) {
		time += temp.MaxDay_of_Month();
		temp.Month++;
	}
	time += Day - temp.Day + 1;

	//tinh b toi cuoi nam
	temp = b;
	time = time + b.MaxDay_of_Month() - temp.Day + 1;
	while (temp.Month != 12) {
		time += b.MaxDay_of_Month();
		temp.Month++;
	}

	if (Year == b.Year) {
		if (Month < b.Month) time = time - 2;
		if (MaxDay_of_Month() == 29) time = 366 - time;
		else time = 365 - time;
		if (time < 0) time = 0 - time;
		return time;
	}

	int MaxYear;
	if (Year > b.Year) {
		year = Year - (b.Year + 1);
		MaxYear = Year;
	}
	else {
		year = b.Year - Year + 1;
		MaxYear = b.Year + 1;
		time -= 2;
	}

	int* arryear = new int[year];

	for (int i = year - 1; i >= 0; i--)
		arryear[i] = MaxYear - year + i;

	int timeyear = 0;
	for (int j = 0; j < year; j++) {
		if (arryear[j] % 400 == 0 || (arryear[j] % 4 == 0 && arryear[j] % 100 != 0))
			timeyear += 366;
		else timeyear += 365;
	}
	if (Year > b.Year)
		time += timeyear;
	else time = timeyear - time;
	return time;
}
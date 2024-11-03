#pragma once
#ifndef _HINHTRON
#define _HINHTRON
#include "Diem3c.h"
#define PI 3.14
class HINHTRON : public DIEM3C
{
protected:
	double R;
public:
	HINHTRON(double = 0, double = 0, double = 0, double = 1);
	HINHTRON(const HINHTRON&);
	~HINHTRON();
	double GetR() const;
	void SetR(double);
	void SetXYZR(double, double, double, double);
	void Nhap();
	void Xuat() const;
	void diChuyen(double, double, double, double);
	friend istream& operator>>(istream&, HINHTRON&);
	friend ostream& operator<<(ostream&, const HINHTRON&);
	double tinhCVTron() const;
	double tinhDTTron() const;
};
#endif // !HINHTRON

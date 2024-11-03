#pragma once
#ifndef _MAU
#define _MAU
#include <iostream>
using namespace std;

class MAU
{
private:
	int r, g, b;
	static int dem;
public:
	MAU(double = 0, double = 0, double = 0);
	MAU(const MAU&);
	~MAU();
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int, int, int);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const MAU&) const;
	friend istream& operator>>(istream&, MAU&);
	friend ostream& operator<<(ostream&, const MAU&);
};
#endif
#pragma once
#ifndef _DiemMau3c
#define _DiemMau3c
#include"Diem3c.h"

class DiemMau3c : public Diem3c
{
protected:
	int r, g, b;
	static int dem;
public:
	DiemMau3c(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	~DiemMau3c();
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
	bool KiemTraTrung(const DiemMau3c&) const;
	friend istream& operator>>(istream&, DiemMau3c&);
	friend ostream& operator<<(ostream&, const DiemMau3c&);
};
#endif // !_DiemMau3c

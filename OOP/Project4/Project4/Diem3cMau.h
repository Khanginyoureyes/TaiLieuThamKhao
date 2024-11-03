#pragma once
#ifndef _DIEM3CMAU
#define _DIEM3CMAU
#include "DIEM3C.h"
#include "MAU.h"
class DIEM3CMAU : public DIEM3C, public MAU
{
public:
	DIEM3CMAU(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	~DIEM3CMAU();
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEM3CMAU&) const;
	friend istream& operator>>(istream&, DIEM3CMAU&);
	friend ostream& operator<<(ostream&, const DIEM3CMAU&);
private:
	static int dem;
};

#endif // !_DIEM3CMAU

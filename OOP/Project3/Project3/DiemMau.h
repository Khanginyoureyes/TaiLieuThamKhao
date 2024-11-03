#pragma once
#ifndef _DIEMMAU
#define _DIEMMAU
#include"DIEM2c.h"
#include"Mau.h"
class DIEMMAU : public DIEM, public MAU
{
public:
	DIEMMAU(double = 0, double = 0, double = 0, double = 0, double = 0);
	~DIEMMAU();
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU&) const;
	friend istream& operator>>(istream&, DIEMMAU&);
	friend ostream& operator<<(ostream&, const DIEMMAU&);
private:
	static int dem;
};

#endif // !_DIEMMAU

#pragma once
#ifndef _SVCQ
#define _SVCQ
#include "SV.h"

class SVCQ : public SV
{
private:
	double drl;
public:
	~SVCQ();
	SVCQ(string = "", string = "", string = "", double = 0, double = 0);
	double getDRL();
	void setDRL(double);
	void Nhap();
	void Xuat();
	string getLoai();
	long tinhTienHocBong();
};
#endif // !_SVCQ

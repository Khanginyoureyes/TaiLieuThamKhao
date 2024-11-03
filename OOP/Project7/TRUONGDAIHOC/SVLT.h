#pragma once
#ifndef _SVLT
#define _SVLT
#include "SV.h"

class SVLT : public SV
{
private:
	int soBuoiVang;
public:
	~SVLT();
	SVLT(string = "", string = "", string = "", double = 0, int = 0);
	int getSoBuoiVang();
	void setSoBuoiVang(int);
	void Nhap();
	void Xuat();
	string getLoai();
	long tinhTienHocBong();
};
#endif // !_SVLT

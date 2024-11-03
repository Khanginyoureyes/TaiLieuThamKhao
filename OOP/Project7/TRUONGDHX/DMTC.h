#pragma once
#ifndef _DMTC
#define _DMTC
#include "BAIBAO.h"

class DMTC : public BAIBAO
{
private:
	string tenDMTC;
public:
	DMTC(string = "");
	~DMTC();
	void setTenDMTC(string);
	string getTenDMTC();
	void Nhap();
	void Xuat();

	int getTongSoTiet();
};
#endif // !_DMTC

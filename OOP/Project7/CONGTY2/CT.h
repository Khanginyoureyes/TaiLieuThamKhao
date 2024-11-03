#pragma once
#ifndef _CT
#define _CT
#include "NV.h"

class CT {
private:
	NV** dsnv;
	int sl;
public:
	CT();
	~CT();
	int GetSL();
	void Nhap();
	void Xuat();
	NV* Nhap1();
};

#endif // !_CT

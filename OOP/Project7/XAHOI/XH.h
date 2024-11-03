#pragma once
#ifndef _XH
#define _XH
#include "NGUOI.h"
#include "SV.h"
#include "HS.h"
#include "CN.h"
#include "CS.h"
#include "NS.h"

class XH {
private:
	NGUOI** dsnguoi;
	int sl;
public:
	XH();
	~XH();
	void Nhap();
	NGUOI* Nhap1();
	void Xuat();
};

#endif // !_XH

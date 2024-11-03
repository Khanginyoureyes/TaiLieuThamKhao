#pragma once
#ifndef _DSTG
#define _DSTG
#include "BAIBAO.h"

class DSTG 
{
protected:
	string maGV, tenGV, ChuyenNganh;
	long long std;
public:
	DSTG(string = "", string = "", string = "", long long = 0);
	~DSTG();
	virtual void Nhap();
	virtual void Xuat();

};

#endif // !_DSTG

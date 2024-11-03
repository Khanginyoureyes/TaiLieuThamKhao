#pragma once
#ifndef _NVCT
#define _NVCT
#include "NVXS.h"

using namespace std;

class NVCT : public NVXS {
protected:
	long long KPI;
public:
	NVCT(string = "", string = "", string = "", long long = 0);
	~NVCT();
	long long GetKPI();
	void SetKPI(long long);
	string GetLoai();
	double TinhTienThuong();
	void Nhap();
	void Xuat();
};
#endif // !_NVCT

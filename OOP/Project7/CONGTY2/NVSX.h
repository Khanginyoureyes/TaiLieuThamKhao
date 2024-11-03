#pragma once
#ifndef _NVSX
#define _NVSX
#include "NV.h"

class NVSX : public NV {
protected:
	long long lcb;
	int	sosanpham;
public:
	NVSX(string = "", CDate = CDate(1, 1, 1), long long = 0, long long = 0, int = 0);
	~NVSX();
	long long GetLCB();
	int GetSSP();
	void SetLCB(long long);
	void SetSSP(int);
	string GetLoai();
	long long TinhLuong();
	void Nhap();
	void Xuat();
};
#endif // !_NVSX

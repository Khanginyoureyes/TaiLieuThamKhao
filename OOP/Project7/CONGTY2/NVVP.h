#pragma once
#ifndef _NVVP
#define _NVVP
#include "NV.h"

class NVVP : public NV {
protected:
	int songaylamviec;
public:
	NVVP(string = "", CDate = CDate(1, 1, 1), long long = 0, int = 0);
	~NVVP();
	int GetSNLV();
	void SetSNLV(int);
	string GetLoai();
	long long TinhLuong();
	void Nhap();
	void Xuat();
};
#endif // !_NVVP

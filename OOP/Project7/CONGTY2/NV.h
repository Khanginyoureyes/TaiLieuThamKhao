#pragma once
#ifndef _NV
#define _NV
#include <iostream>
#include "CDate.h"

using namespace std;

class NV {
protected:
	string ten;
	CDate ngaysinh;
	long long luong;
public:
	NV(string = "", CDate = CDate(1, 1, 1), long long = 0);
	NV(const NV&);
	~NV();
	string GetTen();
	CDate GetNgaySinh();
	long long GetLuong();
	void SetTen(string);
	void SetNgaySinh(CDate);
	virtual string GetLoai() = 0;
	virtual void Xuat();
	virtual void Nhap();
	virtual long long TinhLuong() = 0;

};
#endif // !_NV

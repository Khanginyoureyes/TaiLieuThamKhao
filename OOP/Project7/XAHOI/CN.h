#pragma once
#ifndef _CN
#define _CN
#include "NGUOI.h"

class CN : public NGUOI {
protected:
	string noilamviec;
	long long luong;
public:
	CN(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0, string = "", long long = 0);
	~CN();
	string GetNoiLamViec();
	long long GetLuong();
	void SetNoiLamViec(string);
	void SetLuong(long long);
	string GetLoai();
	void Nhap();
	void Xuat();

};

#endif

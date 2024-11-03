#pragma once
#ifndef _CS
#define _CS
#include "NGUOI.h"

class CS : public NGUOI {
protected:
	string nghedanh;
	string chuyenmon;
public:
	CS(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0, string = "", string = "");
	~CS();
	string GetNgheDanh();
	string GetChuyenMon();
	void SetNgheDanh(string);
	void SetChuyenMon(string);
	string GetLoai();
	void Nhap();
	void Xuat();

};

#endif 

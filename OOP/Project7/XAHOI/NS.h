#pragma once
#ifndef _NS
#define _NS
#include "NGUOI.h"

class NS : public NGUOI {
protected:
	string nghedanh;
	string chuyenmon;
public:
	NS(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0, string = "", string = "");
	~NS();
	string GetNgheDanh();
	string GetChuyenMon();
	void SetNgheDanh(string);
	void SetChuyenMon(string);
	string GetLoai();
	void Nhap();
	void Xuat();

};

#endif 

#pragma once
#pragma once
#ifndef _NGUOI
#define _NGUOI
#include <iostream>
#include <string>
#include "CDate.h"

using namespace std;

class NGUOI {
protected:
	string ten;
	CDate ngaysinh;
	string noio;
	int gioitinh;
public:
	NGUOI(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0);
	~NGUOI();
	string GetTen();
	CDate GetNgaySinh();
	string GetNoiO();
	int GetGT();
	void SetTen(string);
	void SetNgaySinh(CDate);
	void SetNoiO(string);
	void SetGT(int);
	virtual string GetLoai() = 0;
	virtual void Nhap();
	virtual void Xuat();
};

#endif // !_NGUOI

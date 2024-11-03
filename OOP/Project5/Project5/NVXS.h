#pragma once
#ifndef _NVXS
#define _NVXS
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NVXS {
protected:
	string maso;
	string hoten;
	string diachi;
public:
	NVXS(string = "", string = "", string = "");
	~NVXS();
	string GetMaSo();
	string GetHoTen();
	string GetDiaChi();
	void SetHoTen(string);
	void SetDiaChi(string);
	virtual string GetLoai() = 0;
	virtual double TinhTienThuong() = 0;
	virtual void Nhap();
	virtual void Xuat();

};


#endif // !_NhanVien

#pragma once
#ifndef _SV
#define _SV
#include <iostream>
#include <string>
using namespace std;

class SV
{
protected:
	string mssv, hoten, khoa;
	double dtb;
public:
	~SV();
	SV(string = "", string = "", string = "", double = 0);
	string getMSSV() const;
	string getHoTen() const;
	string getKhoa() const;
	double getDTB() const;
	void setHoTen(string);
	void setKhoa(string);
	void setDTB(double);
	virtual double getDRL();
	virtual int getSoBuoiVang();
	virtual void setDRL(double);
	virtual void setSoBuoiVang(int);
	virtual void Nhap();
	virtual void Xuat();

	virtual string getLoai() = 0;
	virtual long tinhTienHocBong() = 0;
};
#endif // !_SV

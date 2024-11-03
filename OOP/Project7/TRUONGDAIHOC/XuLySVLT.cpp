#include "SVLT.h"

SVLT::~SVLT() {}

SVLT::SVLT(string mssv, string hoten, string khoa, double dtb, int soBuoiVang) : SV(mssv, hoten, khoa, dtb), soBuoiVang(soBuoiVang){}

int SVLT::getSoBuoiVang()
{
	return soBuoiVang;
}

void SVLT::setSoBuoiVang(int soBuoiVang)
{
	this->soBuoiVang = soBuoiVang;
}

void SVLT::Nhap()
{
	SV::Nhap();
	do
	{
		cout << "Nhap so buoi vang: ";
		cin >> soBuoiVang;
	} while (soBuoiVang < 0);
}

void SVLT::Xuat()
{
	SV::Xuat();
	cout << "\tSo buoi vang: " << soBuoiVang << endl;
}

string SVLT::getLoai()
{
	return "SVLT";
}

long SVLT::tinhTienHocBong()
{
	long hocBong;
	if (soBuoiVang <= 3)
	{
		hocBong = dtb >= 9 ? 1500000 : (dtb >= 8 ? 1200000 : (dtb >= 7 ? 1000000 : 0));
	}
	return hocBong;
}
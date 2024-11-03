#include "SV.h"

SV::SV(string mssv, string hoten, string khoa, double dtb) : mssv(mssv), hoten(hoten), khoa(khoa), dtb(dtb){}

SV::~SV(){}

string SV::getMSSV() const
{
	return mssv;
}

string SV::getHoTen() const
{
	return hoten;
}

string SV::getKhoa() const
{
	return khoa;
}

double SV::getDTB() const
{
	return dtb;
}

void SV::setHoTen(string hoten)
{
	this->hoten = hoten;
}

void SV::setKhoa(string khoa)
{
	this->khoa = khoa;
}

void SV::setDTB(double dtb)
{
	this->dtb = dtb;
}

double SV::getDRL()
{
	return -1;
}

int SV::getSoBuoiVang()
{
	return -1;
}

void SV::setDRL(double drl)
{
	return;
}

void SV::setSoBuoiVang(int soBuoiVang)
{
	return;
}

void SV::Nhap()
{
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, mssv);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap khoa: ";
	getline(cin, khoa);
	do
	{
		cout << "Nhap diem trung binh: ";
		cin >> dtb;
	} while (dtb < 0 || dtb > 10);
}

void SV::Xuat()
{
	cout << "Ma so: " << mssv << "\tHo ten: " << hoten << "\tKhoa: " << khoa << "\tDTB: " << dtb << "\tLoai: " << getLoai() << "\tHoc bong: " << tinhTienHocBong();
}
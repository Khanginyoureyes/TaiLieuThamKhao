#include "NVXS.h"

NVXS::NVXS(string maso, string hoten, string diachi) : maso(maso), hoten(hoten), diachi(diachi) {}

NVXS::~NVXS()
{

}

string NVXS::GetMaSo()
{
	return maso;
}

string NVXS::GetHoTen()
{
	return hoten;
}

string NVXS::GetDiaChi()
{
	return diachi;
}

void NVXS::SetHoTen(string hoten)
{
	this->hoten = hoten;
}

void NVXS::SetDiaChi(string diachi)
{
	this->diachi = diachi;
}

void NVXS::Nhap()
{
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maso);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap dia chi: ";
	getline(cin, diachi);
}

void NVXS::Xuat()
{
	cout << "Ma so: " << maso << "\t Ho ten: " << hoten << "\t Dia chi: " << diachi << "\tLoai nhan vien: " << GetLoai() << "\t Tien thuong: "
		<< fixed << setprecision(2) << TinhTienThuong();
}
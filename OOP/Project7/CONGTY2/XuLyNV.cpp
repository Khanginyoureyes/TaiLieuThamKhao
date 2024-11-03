#include "NV.h"

NV::NV(string ten, CDate ngaysinh, long long luong) : ten(ten), ngaysinh(ngaysinh), luong(luong) {}

NV::NV(const NV& nv)
{
	ten = nv.ten;
	ngaysinh = nv.ngaysinh;
	luong = nv.luong;
}

NV::~NV() {}

string NV::GetTen()
{
	return ten;
}

CDate NV::GetNgaySinh()
{
	return ngaysinh;
}

long long NV::GetLuong()
{
	return luong;
}

void NV::SetTen(string ten)
{
	this->ten = ten;
}

void NV::SetNgaySinh(CDate ngaysinh)
{
	this->ngaysinh = ngaysinh;
}

void NV::Xuat()
{
	cout << "Ten: " << ten << "\tNgay sinh: " << ngaysinh << "\t Loai: " << GetLoai() << "\t Luong: " << TinhLuong();
}
void NV::Nhap()
{
	cin.ignore();
	cout << "Nhap ten: ";
	cin >> ten;
	cout << "Nhap ngay sinh: \n";
	cin >> ngaysinh;
}

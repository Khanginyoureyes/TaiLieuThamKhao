#include "NVSX.h"

NVSX::NVSX(string ten, CDate ngaysinh, long long luong, long long lcb, int sosanpham) : NV(ten, ngaysinh, luong), lcb(lcb), sosanpham(sosanpham) {}

NVSX::~NVSX()
{
}

long long NVSX::GetLCB()
{
	return lcb;
}

int NVSX::GetSSP()
{
	return sosanpham;
}

void NVSX::SetLCB(long long lcb)
{
	this->lcb = lcb;
}

void NVSX::SetSSP(int ssp)
{
	sosanpham = ssp;
}

string NVSX::GetLoai()
{
	return "NVSX";
}

long long NVSX::TinhLuong()
{
	return (lcb + sosanpham * 5000);
}

void NVSX::Nhap()
{
	NV::Nhap();
	cout << "Nhap luong co ban: ";
	cin >> lcb;
	cout << "Nhap so san pham: ";
	cin >> sosanpham;
}

void NVSX::Xuat()
{
	NV::Xuat();
	cout << "\t Luong co ban: " << lcb << "\t So san pham: " << sosanpham << endl;
}
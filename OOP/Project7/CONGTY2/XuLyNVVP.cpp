#include "NVVP.h"

NVVP::NVVP(string ten, CDate ngaysinh, long long luong, int songaylamviec) : NV(ten, ngaysinh, luong), songaylamviec(songaylamviec) {}

NVVP::~NVVP()
{
}

int NVVP::GetSNLV()
{
	return songaylamviec;
}

void NVVP::SetSNLV(int songaylamviec)
{
	this->songaylamviec = songaylamviec;
}

string NVVP::GetLoai()
{
	return "NVVP";
}

long long NVVP::TinhLuong()
{
	return (songaylamviec * 100000);
}

void NVVP::Nhap()
{
	NV::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> songaylamviec;
}

void NVVP::Xuat()
{
	NV::Xuat();
	cout << "\t So ngay lam viec: " << songaylamviec << endl;
}
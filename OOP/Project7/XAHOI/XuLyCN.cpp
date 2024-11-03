#include "CN.h"

CN::CN(string ten, CDate ngaysinh, string noio, int gioitinh, string noilamviec, long long luong) :
	NGUOI(ten, ngaysinh, noio, gioitinh), noilamviec(noilamviec), luong(luong) {}

CN::~CN()
{

}

string CN::GetNoiLamViec()
{
	return noilamviec;
}

long long CN::GetLuong()
{
	return luong;
}

void CN::SetNoiLamViec(string noilamviec)
{
	this->noilamviec = noilamviec;
}

void CN::SetLuong(long long luong)
{
	do
	{
		cout << "Nhap Luong: ";
		cin >> luong;
	} while (luong < 0);
	this->luong = luong;
}

string CN::GetLoai()
{
	return "Cong Nhan";
}

void CN::Nhap()
{
	NGUOI::Nhap();
	cout << "Nhap noi lam viec: ";
	cin.ignore();
	getline(cin, noilamviec);
	do
	{
		cout << "Nhap Luong: ";
		cin >> luong;
	} while (luong < 0);
}

void CN::Xuat()
{
	NGUOI::Xuat();
	cout << "\t Noi lam viec: " << noilamviec << "\t Luong: " << luong << endl;
}
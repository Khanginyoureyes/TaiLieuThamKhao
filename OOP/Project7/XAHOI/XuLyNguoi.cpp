#include "NGUOI.h"

NGUOI::NGUOI(string ten, CDate ngaysinh, string noio, int gioitinh) : ten(ten), ngaysinh(ngaysinh), noio(noio), gioitinh(gioitinh) {}

NGUOI::~NGUOI()
{

}

string NGUOI::GetTen()
{
	return ten;
}

CDate NGUOI::GetNgaySinh()
{
	return ngaysinh;
}

string NGUOI::GetNoiO()
{
	return noio;
}

int NGUOI::GetGT()
{
	return gioitinh;
}

void NGUOI::SetTen(string ten)
{
	this->ten = ten;
}

void NGUOI::SetNgaySinh(CDate ngaysinh)
{
	this->ngaysinh = ngaysinh;
}

void NGUOI::SetNoiO(string noio)
{
	this->noio = noio;
}

void NGUOI::SetGT(int gioitinh)
{
	do
	{
		cout << "Nhap gioi tinh ( 1 - Nam, 2 - Nu): ";
		cin >> gioitinh;
	} while (gioitinh < 1 || gioitinh > 2);
	this->gioitinh = gioitinh;
}

void NGUOI::Nhap()
{
	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, ten);
	cout << "Nhap ngay sinh: \n";
	cin >> ngaysinh;
	cout << "Nhap noi o: ";
	cin.ignore();
	getline(cin, noio);
	do
	{
		cout << "Nhap gioi tinh ( 1 - Nam, 2 - Nu): ";
		cin >> gioitinh;
	} while (gioitinh < 1 || gioitinh > 2);
}


void NGUOI::Xuat()
{
	cout << "Ten: " << ten << "\t Ngay Sinh: " << ngaysinh << "\t Noi o: " << noio << "\t Gioi tinh: " << gioitinh << "\t Loai: " << GetLoai();
}
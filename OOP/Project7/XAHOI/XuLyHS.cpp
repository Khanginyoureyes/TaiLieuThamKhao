#include "HS.h"

HS::HS(string ten, CDate ngaysinh, string noio, int gioitinh, string truonghoc, string lophoc) :
	NGUOI(ten, ngaysinh, noio, gioitinh), truonghoc(truonghoc), lophoc(lophoc) {}

HS::~HS()
{

}

string HS::GetTruongHoc()
{
	return truonghoc;
}

string HS::GetLopHoc()
{
	return lophoc;
}

void HS::SetTruongHoc(string truonghoc)
{
	this->truonghoc = truonghoc;
}

void HS::SetLopHoc(string lophoc)
{
	this->lophoc = lophoc;
}

string HS::GetLoai()
{
	return "Hoc Sinh";
}

void HS::Nhap()
{
	NGUOI::Nhap();
	cout << "Nhap truong hoc: ";
	cin.ignore();
	getline(cin, truonghoc);
	cout << "Nhap lop hoc: ";
	getline(cin, lophoc);
}

void HS::Xuat()
{
	NGUOI::Xuat();
	cout << "\t Truong Hoc: " << truonghoc << "\t Lop: " << lophoc << endl;
}
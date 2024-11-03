#include "SV.h"

SV::SV(string ten, CDate ngaysinh, string noio, int gioitinh, int namhoc, pair<int, int> nienkhoa, string truonghoc, string nganhhoc) :
	NGUOI(ten, ngaysinh, noio, gioitinh), namhoc(namhoc), nienkhoa(nienkhoa), truonghoc(truonghoc), nganhhoc(nganhhoc) {}

SV::~SV()
{

}

int SV::GetNamHoc()
{
	return namhoc;
}

pair<int, int> SV::GetNienKhoa()
{
	return nienkhoa;
}

string SV::GetTruongHoc()
{
	return truonghoc;
}

string SV::GetNganhHoc()
{
	return nganhhoc;
}

void SV::SetNamHoc(int namhoc)
{
	do
	{
		cout << "Nhap nam hoc ( > 0): ";
		cin >> namhoc;
	} while (namhoc < 1);
	this->namhoc = namhoc;
}

void SV::SetNienKhoa(pair<int, int> nienkhoa)
{
	this->nienkhoa = nienkhoa;
}

void SV::SetTruongHoc(string truonghoc)
{
	this->truonghoc = truonghoc;
}

void SV::SetNganhHoc(string nganhhoc)
{
	this->nganhhoc = nganhhoc;
}

string SV::GetLoai()
{
	return "Sinh Vien";
}

void SV::Nhap()
{
	NGUOI::Nhap();
	do
	{
		cout << "Nhap nam hoc ( > 0): ";
		cin >> namhoc;
	} while (namhoc < 1);
	do
	{
		cout << "Nhap nien khoa ( ... - ....): ";
		cin >> nienkhoa.first >> nienkhoa.second;
	} while (nienkhoa.first > nienkhoa.second);
	cout << "Nhap truong hoc: ";
	cin.ignore();
	getline(cin, truonghoc);
	cout << "Nhap nganh hoc: ";
	getline(cin, nganhhoc);
}

void SV::Xuat()
{
	NGUOI::Xuat();
	cout << "\t Truong: " << truonghoc << "\t Nganh Hoc: " << nganhhoc << "\t Nien Khoa: " << nienkhoa.first << " - " << nienkhoa.second
		<< "\t Sinh vien nam: " << namhoc << endl;
}

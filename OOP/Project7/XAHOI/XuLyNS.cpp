#include "NS.h"

NS::NS(string ten, CDate ngaysinh, string noio, int gioitinh, string nghedanh, string chuyenmon) :
	NGUOI(ten, ngaysinh, noio, gioitinh), nghedanh(nghedanh), chuyenmon(chuyenmon) {}

NS::~NS()
{

}

string NS::GetNgheDanh()
{
	return nghedanh;
}

string NS::GetChuyenMon()
{
	return chuyenmon;
}

void NS::SetNgheDanh(string nghedanh)
{
	this->nghedanh = nghedanh;
}

void NS::SetChuyenMon(string chuyenmon)
{
	this->chuyenmon = chuyenmon;
}

string NS::GetLoai()
{
	return "Nghe Si";
}

void NS::Nhap()
{
	NGUOI::Nhap();
	cout << "Nhap nghe danh: ";
	cin.ignore();
	getline(cin, nghedanh);
	cout << "Nhap chuyen mon: ";
	getline(cin, chuyenmon);
}

void NS::Xuat()
{
	NGUOI::Xuat();
	cout << "\t Truong Hoc: " << nghedanh << "\t Lop: " << chuyenmon << endl;
}
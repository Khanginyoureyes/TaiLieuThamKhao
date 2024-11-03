#include "CS.h"

CS::CS(string ten, CDate ngaysinh, string noio, int gioitinh, string nghedanh, string chuyenmon) :
	NGUOI(ten, ngaysinh, noio, gioitinh), nghedanh(nghedanh), chuyenmon(chuyenmon) {}

CS::~CS()
{

}

string CS::GetNgheDanh()
{
	return nghedanh;
}

string CS::GetChuyenMon()
{
	return chuyenmon;
}

void CS::SetNgheDanh(string nghedanh)
{
	this->nghedanh = nghedanh;
}

void CS::SetChuyenMon(string chuyenmon)
{
	this->chuyenmon = chuyenmon;
}

string CS::GetLoai()
{
	return "Ca Si";
}

void CS::Nhap()
{
	NGUOI::Nhap();
	cout << "Nhap nghe danh: ";
	cin.ignore();
	getline(cin, nghedanh);
	cout << "Nhap chuyen mon: ";
	getline(cin, chuyenmon);
}

void CS::Xuat()
{
	NGUOI::Xuat();
	cout << "\t Truong Hoc: " << nghedanh << "\t Lop: " << chuyenmon << endl;
}
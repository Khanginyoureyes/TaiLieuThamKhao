#include "NVCT.h"

NVCT::NVCT(string maso, string hoten, string diachi, long long KPI) : NVXS(maso, hoten, diachi), KPI(KPI) {}

NVCT::~NVCT()
{

}

long long NVCT::GetKPI()
{
	return KPI;
}

void NVCT::SetKPI(long long KPI)
{
	this->KPI = KPI;
}

string NVCT::GetLoai()
{
	return "NVCT";
}

double NVCT::TinhTienThuong()
{
	double thuong = 0;
	if (KPI >= 100000000 && KPI < 200000000)
		thuong = KPI * 0.1 + 5000000;
	else if (KPI >= 200000000)
		thuong = KPI * 0.1 + 10000000;
	return thuong;
}

void NVCT::Nhap()
{
	NVXS::Nhap();
	cout << "Nhap KPI: ";
	cin >> KPI;
}

void NVCT::Xuat()
{
	NVXS::Xuat();
	cout << "\tKPI: " << KPI << endl;
}
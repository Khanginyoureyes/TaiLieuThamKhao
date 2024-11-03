#include "DMHN.h"

DMHN::DMHN(int XepHang) : XepHang(XepHang){}

DMHN::~DMHN(){}

void DMHN::Nhap()
{
	BAIBAO::Nhap();
	cout << "Nhap (1 - Thuoc bang xep hang, 2 - Khong thuoc bang xep hang: ";
	cin >> XepHang;
}

void DMHN::Xuat()
{
	BAIBAO::Xuat();
	if (XepHang == 1)
	{
		cout << "\t Thuoc bang xep hang Core Ranking";
	}
	else if (XepHang == 2)
	{
		cout << "\t Khong thuoc bang xep hang Core Ranking";
	}
}


int DMHN::getTongSoTiet()
{
	if (XepHang == 1)
	{
		return 1000;
	}
	else
	{
		return 500;
	}
}
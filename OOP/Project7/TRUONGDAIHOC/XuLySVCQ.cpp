#include "SVCQ.h"

SVCQ::~SVCQ(){}

SVCQ::SVCQ(string mssv, string hoten, string khoa, double dtb, double drl) : SV(mssv, hoten, khoa, dtb), drl(drl){}

double SVCQ::getDRL()
{
	return drl;
}

void SVCQ::setDRL(double drl)
{
	this->drl = drl;
}

void SVCQ::Nhap()
{
	SV::Nhap();
	do
	{
		cout << "Nhap diem ren luyen: ";
		cin >> drl;
	} while (drl < 0 || drl > 101);
}

void SVCQ::Xuat()
{
	SV::Xuat();
	cout << "\tDRL: " << drl << endl;
}

string SVCQ::getLoai()
{
	return "SVCQ";
}

long SVCQ::tinhTienHocBong()
{
	long hocBong;
	if (drl >= 85)
	{
		hocBong = (dtb >= 9.5 ? 1500000 : (dtb >= 8 ? 1200000 : (dtb >= 7 ? 1000000 : 0)));
	}
	return hocBong;
}
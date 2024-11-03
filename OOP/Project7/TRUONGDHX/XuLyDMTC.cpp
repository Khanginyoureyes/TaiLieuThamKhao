#include "DMTC.h"

DMTC::DMTC(string tenDMTC) : tenDMTC(tenDMTC){}

DMTC::~DMTC(){}

void DMTC::setTenDMTC(string tenDMTC)
{
	this->tenDMTC = tenDMTC;
}

string DMTC::getTenDMTC()
{
	return tenDMTC;
}

void DMTC::Nhap()
{
	cin.ignore();
	BAIBAO::Nhap();
	cout << "Nhap ten danh muc tap chi(ISI, Scopus, Non-Index): ";
	getline(cin, tenDMTC);
}

void DMTC::Xuat()
{
	BAIBAO::Xuat();
	cout << "\t Ten danh muc tap chi: " << tenDMTC;
}

int DMTC::getTongSoTiet()
{
	if (tenDMTC == "ISI")
	{
		return 5000;
	}
	else if (tenDMTC == "Scopus")
	{
		return 2500;
	}
	else if (tenDMTC == "Non-Index")
	{
		return 1000;
	}
}
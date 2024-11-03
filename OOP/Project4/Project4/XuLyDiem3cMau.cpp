#include "DIEM3CMAU.h"

int DIEM3CMAU::dem = 0;
DIEM3CMAU::~DIEM3CMAU()
{
	cout << "Da huy 1 DIEM 3c MAU => Con " << --dem << " DIEM 3c MAU\n";
}
DIEM3CMAU::DIEM3CMAU(double x, double y, double z, double r, double g, double b) : DIEM3C(x, y, z), MAU(r, g, b)
{
	cout << "Da tao 1 DIEM 3c MAU => Co " << ++dem << " DIEM 3c MAU\n";
}
int DIEM3CMAU::GetDem()
{
	return dem;
}
void DIEM3CMAU::Nhap()
{
	DIEM3C::Nhap();
	MAU::Nhap();
}
void DIEM3CMAU::Xuat() const
{
	DIEM3C::Xuat();
	MAU::Xuat();
}
bool DIEM3CMAU::KiemTraTrung(const DIEM3CMAU& d3cm) const
{
	return DIEM3C::KiemTraTrung(d3cm) && MAU::KiemTraTrung(d3cm);
}
istream& operator>>(istream& is, DIEM3CMAU& d3cm)
{
	d3cm.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const DIEM3CMAU& d3cm)
{
	d3cm.Xuat();
	return os;
}

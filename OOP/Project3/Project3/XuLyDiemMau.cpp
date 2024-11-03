#include "DIEMMAU.h"

int DIEMMAU::dem = 0;
DIEMMAU::~DIEMMAU()
{
	cout << "Da huy 1 DIEM MAU => Con " << --dem << " DIEM MAU\n";
}
DIEMMAU::DIEMMAU(double x, double y, double r, double g, double b) : DIEM(x, y), MAU(r, g, b)
{
	cout << "Da tao 1 DIEM MAU => Co " << ++dem << " DIEM MAU\n";
}
int DIEMMAU::GetDem()
{
	return dem;
}
void DIEMMAU::Nhap()
{
	DIEM::NhapDIEM();
	MAU::Nhap();
}
void DIEMMAU::Xuat() const
{
	DIEM::XuatDIEM();
	MAU::Xuat();
}
bool DIEMMAU::KiemTraTrung(const DIEMMAU& dm) const
{
	return DIEM::TrungNhau(dm) && MAU::KiemTraTrung(dm);
}
istream& operator>>(istream& is, DIEMMAU& dm)
{
	dm.Nhap();
	return is;
}
ostream& operator<<(ostream& os, const DIEMMAU& dm)
{
	dm.Xuat();
	return os;
}
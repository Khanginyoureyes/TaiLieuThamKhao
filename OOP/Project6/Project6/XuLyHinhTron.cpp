#include "HinhTron.h"
HINHTRON::~HINHTRON(){}

HINHTRON::HINHTRON(double x, double y, double z, double R) : DIEM3C(x, y, z), R(R){}

HINHTRON::HINHTRON(const HINHTRON& O) : DIEM3C(O.x, O.y, O.z), R(O.R){}

double HINHTRON::GetR() const
{
	return R;
}

void HINHTRON::SetR(double R)
{
	this->R = R;
}

void HINHTRON::SetXYZR(double x, double y, double z, double R)
{
	DIEM3C(x, y, z);
	SetR(R);
}

void HINHTRON::Nhap()
{
	DIEM3C::Nhap();
	do
	{
		cout << "Nhap ban kinh: ";
		cin >> R;
	} while (R <= 0);
}

void HINHTRON::Xuat() const
{
	DIEM3C::Xuat();
	cout << ", ban kinh: " << R << endl;
}

istream& operator>>(istream& is, HINHTRON& ht)
{
	ht.DIEM3C::Nhap();
	do
	{
		cout << "Nhap ban kinh: ";
		is >> ht.R;
	} while (ht.R <= 0);
	return is;
}

ostream& operator<<(ostream& os, const HINHTRON& ht)
{
	ht.DIEM3C::Xuat();
	os << ", ban kinh: " << ht.R << endl;
	return os;
}

void HINHTRON::diChuyen(double dx, double dy, double dz, double dR)
{
	DIEM3C::DiChuyen(dx, dy, dz);
	R += dR;
}

double HINHTRON::tinhCVTron() const
{
	return 2 * PI * R;
}

double HINHTRON::tinhDTTron() const
{
	return PI * pow(R, 2);
}
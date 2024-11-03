#include "DiemMau3c.h"
int DiemMau3c::dem = 0;
DiemMau3c::~DiemMau3c()
{
	cout << "Da huy 1 diem mau 3C => Con " << --dem << " diem mau 3C\n";
}
DiemMau3c::DiemMau3c(double x, double y, double z, double r, double g, double b) : Diem3c(x, y, z)
{
	SetRGB(r, g, b);
	cout << "Da tao 1 diem mau 3C => Co " << ++dem << " diem mau 3C\n";
}
int DiemMau3c::GetR() const
{
	return r;
}
int DiemMau3c::GetG() const
{
	return g;
}
int DiemMau3c::GetB() const
{
	return b;
}
void DiemMau3c::SetR(int r)
{
	while (r < 0 || r > 255)
	{
		cout << "Nhap lai thong so mau red tu 0 den 255: ";
		cin >> r;
	}
	this->r = r;
}
void DiemMau3c::SetG(int g)
{
	while (g < 0 || g > 255)
	{
		cout << "Nhap lai thong so mau green tu 0 den 255: ";
		cin >> g;
	}
	this->g = g;
}
void DiemMau3c::SetB(int b)
{
	while (b < 0 || b > 255)
	{
		cout << "Nhap lai thong so mau blue tu 0 den 255: ";
		cin >> b;
	}
	this->b = b;
}
void DiemMau3c::SetRGB(int r, int g, int b)
{
	SetR(r);
	SetG(g);
	SetB(b);
}
int DiemMau3c::GetDem()
{
	return dem;
}
void DiemMau3c::Nhap()
{
	Diem3c::Nhap();
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}
void DiemMau3c::Xuat() const
{
	Diem3c::Xuat();
	cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}
bool DiemMau3c::KiemTraTrung(const DiemMau3c& m3c) const
{
	return Diem3c::KiemTraTrung(m3c) && m3c.r == r && m3c.g == g && m3c.b == b;
}
istream& operator>>(istream& is, DiemMau3c& m3c)
{
	m3c.Diem3c::Nhap();
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		is >> m3c.r >> m3c.g >> m3c.b;
	} while (m3c.r < 0 || m3c.r > 255 || m3c.g < 0 || m3c.g > 255 || m3c.b < 0 || m3c.b > 255);
	return is;
}
ostream& operator<<(ostream& os, const DiemMau3c& m3c)
{
	m3c.Diem3c::Xuat();
	os << " - Mau RGB(" << m3c.r << ", " << m3c.g << ", " << m3c.b << ")";
	return os;
}
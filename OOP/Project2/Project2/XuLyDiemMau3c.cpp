#include "DIEMMAU3C.h"
int DIEMMAU3C::dem = 0;
DIEMMAU3C::~DIEMMAU3C()
{
	cout << "Da huy 1 DIEM mau 3C => Con " << --dem << " DIEM mau 3C\n";
}
DIEMMAU3C::DIEMMAU3C(double x, double y, double z, double r, double g, double b) : DIEM3C(x, y, z)
{
	SetRGB(r, g, b);
	cout << "Da tao 1 DIEM mau 3C => Co " << ++dem << " DIEM mau 3C\n";
}
int DIEMMAU3C::GetR() const
{
	return r;
}
int DIEMMAU3C::GetG() const
{
	return g;
}
int DIEMMAU3C::GetB() const
{
	return b;
}
void DIEMMAU3C::SetR(int r)
{
	while (r < 0 || r > 255)
	{
		cout << "Nhap lai thong so mau red tu 0 den 255: ";
		cin >> r;
	}
	this->r = r;
}
void DIEMMAU3C::SetG(int g)
{
	while (g < 0 || g > 255)
	{
		cout << "Nhap lai thong so mau green tu 0 den 255: ";
		cin >> g;
	}
	this->g = g;
}
void DIEMMAU3C::SetB(int b)
{
	while (b < 0 || b > 255)
	{
		cout << "Nhap lai thong so mau blue tu 0 den 255: ";
		cin >> b;
	}
	this->b = b;
}
void DIEMMAU3C::SetRGB(int r, int g, int b)
{
	SetR(r);
	SetG(g);
	SetB(b);
}
int DIEMMAU3C::GetDem()
{
	return dem;
}
void DIEMMAU3C::Nhap()
{
	DIEM3C::Nhap();
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}
void DIEMMAU3C::Xuat() const
{
	DIEM3C::Xuat();
	cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}
bool DIEMMAU3C::KiemTraTrung(const DIEMMAU3C& m3c) const
{
	return DIEM3C::KiemTraTrung(m3c) && m3c.r == r && m3c.g == g && m3c.b == b;
}
istream& operator>>(istream& is, DIEMMAU3C& m3c)
{
	m3c.DIEM3C::Nhap();
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		is >> m3c.r >> m3c.g >> m3c.b;
	} while (m3c.r < 0 || m3c.r > 255 || m3c.g < 0 || m3c.g > 255 || m3c.b < 0 || m3c.b > 255);
	return is;
}
ostream& operator<<(ostream& os, const DIEMMAU3C& m3c)
{
	m3c.DIEM3C::Xuat();
	os << " - Mau RGB(" << m3c.r << ", " << m3c.g << ", " << m3c.b << ")";
	return os;
}
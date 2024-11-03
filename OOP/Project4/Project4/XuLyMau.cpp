#include "MAU.h"
int MAU::dem = 0;
MAU::~MAU()
{
	cout << "Da huy 1 MAU => Con " << --dem << " MAU\n";
}
MAU::MAU(double r, double g, double b)
{
	SetRGB(r, g, b);
	cout << "Da tao 1 MAU => Co " << ++dem << " MAU\n";
}
MAU::MAU(const MAU& color)
{
	SetRGB(color.r, color.g, color.b);
	cout << "Da tao 1 MAU => Co " << ++dem << " MAU\n";
}
int MAU::GetR() const
{
	return r;
}
int MAU::GetG() const
{
	return g;
}
int MAU::GetB() const
{
	return b;
}
void MAU::SetR(int r)
{
	while (r < 0 || r > 255)
	{
		cout << "Nhap lai thong so MAU red tu 0 den 255: ";
		cin >> r;
	}
	this->r = r;
}
void MAU::SetG(int g)
{
	while (g < 0 || g > 255)
	{
		cout << "Nhap lai thong so MAU green tu 0 den 255: ";
		cin >> g;
	}
	this->g = g;
}
void MAU::SetB(int b)
{
	while (b < 0 || b > 255)
	{
		cout << "Nhap lai thong so MAU blue tu 0 den 255: ";
		cin >> b;
	}
	this->b = b;
}
void MAU::SetRGB(int r, int g, int b)
{
	SetR(r);
	SetG(g);
	SetB(b);
}
int MAU::GetDem()
{
	return dem;
}
void MAU::Nhap()
{
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}
void MAU::Xuat() const
{
	cout << " - MAU RGB(" << r << ", " << g << ", " << b << ")";
}
bool MAU::KiemTraTrung(const MAU& m) const
{
	return m.r == r && m.g == g && m.b == b;
}
istream& operator>>(istream& is, MAU& m)
{
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		is >> m.r >> m.g >> m.b;
	} while (m.r < 0 || m.r > 255 || m.g < 0 || m.g > 255 || m.b < 0 || m.b > 255);
	return is;
}
ostream& operator<<(ostream& os, const MAU& m)
{
	os << " - MAU RGB(" << m.r << ", " << m.g << ", " << m.b << ")";
	return os;
}
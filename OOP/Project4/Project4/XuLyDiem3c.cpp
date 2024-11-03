#include "DIEM3C.h"
int DIEM3C::dem = 0;
DIEM3C::~DIEM3C()
{
    cout << "Da huy 1 DIEM 3C => Con " << --dem << " DIEM 3C\n";
}

DIEM3C::DIEM3C(double x, double y, double z) : DIEM(x, y), z(z)
{
    cout << "Da tao 1 DIEM 3C => Co " << ++dem << " DIEM 3C\n";
}

DIEM3C::DIEM3C(const DIEM3C& d3c) : DIEM(d3c.x, d3c.y), z(d3c.z)
{
    cout << "Da tao 1 DIEM 3C => Co " << ++dem << " DIEM 3C\n";
}

double DIEM3C::GetZ() const
{
    return z;
}

void DIEM3C::SetZ(double z)
{
    this->z = z;
}

void DIEM3C::SetXYZ(double x, double y, double z)
{
    SetXY(x, y);
    SetZ(z);
}

int DIEM3C::GetDem()
{
    return dem;
}

void DIEM3C::Nhap()
{
    DIEM::NhapDIEM();
    cout << "Nhap cao do: ";
    cin >> z;
}

void DIEM3C::Xuat() const
{
    DIEM::XuatDIEM();
    cout << ", " << z;
}

bool DIEM3C::KiemTraTrung(const DIEM3C& d3c) const
{
    return DIEM::TrungNhau(d3c) && z == d3c.z;
}

void DIEM3C::DiChuyen(double dx, double dy, double dz)
{
    DIEM::DiChuyen(dx, dy);
    z += dz;
}

double DIEM3C::TinhKhoangCach(const DIEM3C& d3c) const
{
    return sqrt(pow(x - d3c.x, 2) + pow(y - d3c.y, 2) + pow(z - d3c.z, 2));
}

DIEM3C DIEM3C::DoiXung() const
{
    return DIEM3C(x == 0 ? 0 : -x, y == 0 ? 0 : -y, z == 0 ? 0 : -z);
}

double DIEM3C::TinhChuVi(const DIEM3C& d2, const DIEM3C& d3) const
{
    double a = this->TinhKhoangCach(d2);
    double b = d2.TinhKhoangCach(d3);
    double c = d3.TinhKhoangCach(*this);
    return a + b + c;
}

double DIEM3C::TinhDienTich(const DIEM3C& d2, const DIEM3C& d3) const
{
    double a = this->TinhKhoangCach(d2);
    double b = d2.TinhKhoangCach(d3);
    double c = d3.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

istream& operator>>(istream& is, DIEM3C& data)
{
    data.DIEM::NhapDIEM();
    cout << "Nhap do cao: ";
    is >> data.z;
    return is;
}

ostream& operator<<(ostream& os, const DIEM3C& data)
{
    data.DIEM::XuatDIEM();
    cout << ", " << data.z;
    return os;
}
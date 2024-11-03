#include "DIEM3c.h"
int DIEM3c::dem = 0;
DIEM3c::~DIEM3c()
{
    cout << "Da huy 1 DIEM 3C => Con " << --dem << " DIEM 3C\n";
}

DIEM3c::DIEM3c(double x, double y, double z) : DIEM(x, y), z(z)
{
    cout << "Da tao 1 DIEM 3C => Co " << ++dem << " DIEM 3C\n";
}

DIEM3c::DIEM3c(const DIEM3c& d3c) : DIEM(d3c.x, d3c.y), z(d3c.z)
{
    cout << "Da tao 1 DIEM 3C => Co " << ++dem << " DIEM 3C\n";
}

double DIEM3c::GetZ() const
{
    return z;
}

void DIEM3c::SetZ(double z)
{
    this->z = z;
}

void DIEM3c::SetXYZ(double x, double y, double z)
{
    SetXY(x, y);
    SetZ(z);
}

int DIEM3c::GetDem()
{
    return dem;
}

void DIEM3c::Nhap()
{
    DIEM::NhapDIEM();
    cout << "Nhap cao do: ";
    cin >> z;
}

void DIEM3c::Xuat() const
{
    DIEM::XuatDIEM();
    cout << ", " << z;
}

bool DIEM3c::KiemTraTrung(const DIEM3c& d3c) const
{
    return DIEM::TrungNhau(d3c) && z == d3c.z;
}

void DIEM3c::DiChuyen(double dx, double dy, double dz)
{
    DIEM::DiChuyen(dx, dy);
    z += dz;
}

double DIEM3c::TinhKhoangCach(const DIEM3c& d3c) const
{
    return sqrt(pow(x - d3c.x, 2) + pow(y - d3c.y, 2) + pow(z - d3c.z, 2));
}

DIEM3c DIEM3c::DoiXung() const
{
    return DIEM3c(x == 0 ? 0 : -x, y == 0 ? 0 : -y, z == 0 ? 0 : -z);
}

double DIEM3c::TinhChuVi(const DIEM3c& d2, const DIEM3c& d3) const
{
    double a = this->TinhKhoangCach(d2);
    double b = d2.TinhKhoangCach(d3);
    double c = d3.TinhKhoangCach(*this);
    return a + b + c;
}

double DIEM3c::TinhDienTich(const DIEM3c& d2, const DIEM3c& d3) const
{
    double a = this->TinhKhoangCach(d2);
    double b = d2.TinhKhoangCach(d3);
    double c = d3.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

istream& operator>>(istream& is, DIEM3c& data)
{
    data.DIEM::NhapDIEM();
    cout << "Nhap do cao: ";
    is >> data.z;
    return is;
}

ostream& operator<<(ostream& os, const DIEM3c& data)
{
    data.DIEM::XuatDIEM();
    cout << ", " << data.z;
    return os;
}
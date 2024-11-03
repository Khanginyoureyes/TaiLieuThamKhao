#include"DIEM2c.h"
int DIEM::dem = 0;
DIEM::DIEM(double x, double y) : x(x), y(y){}

DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y){}

double DIEM::GetX() const
{
    return x;
}

double DIEM::GetY() const
{
    return y;
}

void DIEM::SetX(double x)
{
    this->x = x;
}

void DIEM::SetY(double y)
{
    this->y = y;
}

void DIEM::SetXY(double x, double y)
{
    SetX(x);
    SetY(y);
}

int DIEM::GetDem()
{
    return dem;
}

void DIEM::NhapDIEM()
{
    cout << "Nhap diem x: ";
    cin >> x;
    cout << "Nhap diem y: ";
    cin >> y;
}

void DIEM::XuatDIEM() const
{
    cout << x << ", " << y;
}

void DIEM::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool DIEM::TrungNhau(const DIEM& p) const
{
    return p.x == x && p.y == y;
}

double DIEM::KhoangCach(const DIEM& p) const
{
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

DIEM DIEM::DoiXung() const
{
    return DIEM(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

DIEM::~DIEM(){}

bool DIEM::KiemTraTGHopLe(const DIEM& p1, const DIEM& p2) const
{
    double a = KhoangCach(p1);
    double b = p1.KhoangCach(p2);
    double c = p2.KhoangCach(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}

double DIEM::ChuVi(const DIEM& p1, const DIEM& p2) const
{
    double a = this->KhoangCach(p1);
    double b = p1.KhoangCach(p2);
    double c = p2.KhoangCach(*this);
    return a + b + c;
}

double DIEM::DienTich(const DIEM& p1, const DIEM& p2) const
{
    double a = this->KhoangCach(p1);
    double b = p1.KhoangCach(p2);
    double c = p2.KhoangCach(*this);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& p1, const DIEM& p2) const
{
    double a = this->KhoangCach(p1);
    double b = p1.KhoangCach(p2);
    double c = p2.KhoangCach(*this);
    float d = 0.00001;
    if (a <= 0 || b <= 0 || c <= 0 && a + b)
        return "Khong phai tam giac";
    if (a == b && b == c)
        return "Tam giac deu";
    else if (a == b || a == c || b == c) {
        if (a * a + b * b - c * c <= d || a * a + c * c - b * b <= d || b * b + c * c - a * a <= d)
            return "Tam giac vuong can";
        else
            return "Tam giac can";
    }
    else if (a * a + b * b - c * c <= d || a * a + c * c - b * b <= d || b * b + c * c - a * a <= d)
        return "Tam giac vuong";
    else
        return "Tam giac binh thuong";
}

istream& operator>>(istream& is, DIEM& data)
{
    cout << "Nhap hoanh do: ";
    is >> data.x;
    cout << "Nhap tung do: ";
    is >> data.y;
    return is;
}

ostream& operator<<(ostream& os, const DIEM& data)
{
    os << data.x << ", " << data.y;
    return os;
}
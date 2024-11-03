#include "NVBC.h"

NVBC::NVBC(string ms, string ht, string pb, double hsl, double hspc) : NV(ms, ht, pb), hsl(hsl), hspc(hspc) {}

double NVBC::getHSL()
{
    return hsl;
}

double NVBC::getHSPC()
{
    return hspc;
}

void NVBC::setHSL(double hsl)
{
    this->hsl = hsl;
}

void NVBC::setHSPC(double hspc)
{
    this->hspc = hspc;
}

void NVBC::Nhap()
{
    NV::Nhap();
    do
    {
        cout << "Nhap he so luong: ";
        cin >> hsl;
    } while (hsl < 0);
    do
    {
        cout << "Nhap he so phu cap: ";
        cin >> hspc;
    } while (hspc < 0);
}

void NVBC::Xuat()
{
    NV::Xuat();
    cout << "\tHe so luong: " << hsl << "\tHe so phu cap: " << hspc << endl;
}
string NVBC::getLoai()
{
    return "NVBC";
}
long NVBC::tinhTienLuong()
{
    long tienluong = 0;
    tienluong = (1 + hsl + hspc) * 1000;
    return tienluong;
}
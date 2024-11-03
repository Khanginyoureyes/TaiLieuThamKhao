#include "NVHD.h"
NVHD::NVHD(string ms, string ht, string pb, double tc, double hsvg, int snc) : NV(ms, ht, pb), tiencong(tc), hsvg(hsvg), songaycong(snc) {}

double NVHD::getTienCong()
{
    return tiencong;
}

double NVHD::getHSVG()
{
    return hsvg;
}

int NVHD::getSNC()
{
    return songaycong;
}

void NVHD::setTienCong(double tc)
{
    tiencong = tc;
}

void NVHD::setHSVG(double hsvg)
{
    this->hsvg = hsvg;
}

void NVHD::setSNC(int snc)
{
    songaycong = snc;
}

void NVHD::Nhap()
{
    NV::Nhap();
    do
    {
        cout << "Nhap tien cong: ";
        cin >> tiencong;
    } while (tiencong < 0);
    do
    {
        cout << "Nhap so ngay cong: ";
        cin >> songaycong;
    } while (songaycong < 0);
    do
    {
        cout << "Nhap he so vuot gio: ";
        cin >> hsvg;
    } while (hsvg < 0);
}

void NVHD::Xuat()
{
    NV::Xuat();
    cout << "\tTien cong: " << tiencong << "\tSo ngay cong: " << songaycong << "\tHe so vuot gio: " << hsvg << endl;
}
string NVHD::getLoai()
{
    return "NVHD";
}
long NVHD::tinhTienLuong() {
    long tienluong = 0;
    tienluong = tiencong * songaycong * (1 + hsvg);
    return tienluong;
}

#pragma once
#include <iostream>
#include <math.h>
using namespace std;
#ifndef _DIEM

class DIEM
{
protected:
    double x, y;
    static int dem;
public:
    DIEM(double = 0, double = 0);
    DIEM(const DIEM&);
    ~DIEM();
    double GetX() const;
    double GetY() const;
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    static int GetDem();
    void NhapDIEM();
    void XuatDIEM() const;
    void DiChuyen(double, double);
    bool TrungNhau(const DIEM&) const;
    double KhoangCach(const DIEM&) const;
    DIEM DoiXung() const;
    double ChuVi(const DIEM&, const DIEM&) const;
    double DienTich(const DIEM&, const DIEM&) const;
    string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
    bool KiemTraTGHopLe(const DIEM&, const DIEM&) const;
    friend istream& operator>>(istream&, DIEM&);
    friend ostream& operator<<(ostream&, const DIEM&);
};
#endif
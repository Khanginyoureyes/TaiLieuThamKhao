#pragma once
#ifndef _DIEM3c
#define _DIEM3c
#include "DIEM2c.h"
class DIEM3c : public DIEM
{
protected:
    double z;
    static int dem;
public:
    ~DIEM3c();
    DIEM3c(double = 0, double = 0, double = 0);
    DIEM3c(const DIEM3c&);
    double GetZ() const;
    void SetZ(double);
    void SetXYZ(double, double, double);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEM3c&) const;
    void DiChuyen(double, double, double);
    double TinhKhoangCach(const DIEM3c&) const;
    DIEM3c DoiXung() const;
    friend istream& operator>>(istream&, DIEM3c&);
    friend ostream& operator<<(ostream&, const DIEM3c&);
    double TinhChuVi(const DIEM3c&, const DIEM3c&) const;
    double TinhDienTich(const DIEM3c&, const DIEM3c&) const;
};
#endif
#pragma once
#ifndef _NVHD
#define _NVHD
#include "NV.h"
class NVHD : public NV {
private:
    double tiencong;
    int songaycong;
    double hsvg;
public:
    NVHD(string = "", string = "", string = "", double = 0, double = 0, int = 0);
    double getTienCong();
    double getHSVG();
    int getSNC();
    void setTienCong(double);
    void setHSVG(double);
    void setSNC(int);
    void Nhap();
    void Xuat();
    long tinhTienLuong();
    string getLoai();
};
#endif // !_NVHD

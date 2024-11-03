#pragma once
#ifndef _NVBC
#define _NVBC
#include "NV.h"
class NVBC : public NV {
private:
    double hsl;
    double hspc;
public:
    NVBC(string = "", string = "", string = "", double = 0, double = 0);
    double getHSL();
    double getHSPC();
    void setHSL(double);
    void setHSPC(double);
    void Nhap();
    void Xuat();
    long tinhTienLuong();
    string getLoai();
};
#endif // !_NVBC

#pragma once
#ifndef _NV
#define _NV
#include <iostream>
#include <string>
using namespace std;
class NV {
protected:
    string maso;
    string hoten;
    string phongban;
public:
    NV(string = "", string = "", string = "");
    string GetMaSo();
    string GetHoTen();
    string GetPhongBan();
    void SetHoTen(string);
    void SetPhongBan(string);
    virtual void Nhap();
    virtual void Xuat();
    virtual long tinhTienLuong() = 0;
    virtual string getLoai() = 0;
};

#endif 

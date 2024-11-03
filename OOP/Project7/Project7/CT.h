#pragma once
#ifndef _CT
#define _CT
#include "NV.h"

class CT {
private:
    NV** dsnv;
    int sl;
public:
    CT();
    ~CT();
    int getSL();
    void Nhap();
    void Xuat();
    NV* Nhap1();
    void lietKeNVCoHSLTu35TroLen();
    int demNCHDCoSNC26();
    long tinhTongTienLuong();
    long tinhTienLuongTBCuaNVBC();
    bool kiemTraNVHDKhongDiLam();
    void timNVBCCoHSLCaoNhat();
    void themNVMoi(NV*, int);
    int xoaNV(string);
    string doiChuoiInHoa(string);
    void sapXepMaSoTangDan();
    void GhiFile(string);
    void DocFile(string);
    void LuuFile(string);
};

#endif // !_CT

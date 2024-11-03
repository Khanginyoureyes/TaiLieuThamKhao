#include "NV.h"

NV::NV(string ms, string ht, string pb) : maso(ms), hoten(ht), phongban(pb) {}

string NV::GetMaSo() {
    return maso;
}

string NV::GetHoTen() {
    return hoten;
}

string NV::GetPhongBan() {
    return phongban;
}

void NV::SetHoTen(string hoten)
{
    this->hoten = hoten;
}

void NV::SetPhongBan(string phongban)
{
    this->phongban = phongban;
}

void NV::Nhap() {
    cin.ignore();
    cout << "Nhap ma so: ";
    getline(cin, maso);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap phong ban: ";
    getline(cin, phongban);
}

void NV::Xuat() {
    cout << "MS: " << maso << "\tHoTen: " << hoten << "\tPhongBan: " << phongban << "\tLoai: " << getLoai() << "\tTien Luong: " << tinhTienLuong();
}

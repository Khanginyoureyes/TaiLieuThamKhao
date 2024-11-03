#include "DETAIKH.h"

DETAIKH::DETAIKH(string maDT, string tenDT, int ngayDK, int thoiGianThucHien, int ngayNghiemThu, int soLuongBaiBao) : maDT(maDT), tenDT(tenDT), ngayDK(ngayDK), thoiGianThucHien(thoiGianThucHien), ngayNghiemThu(ngayNghiemThu), soLuongBaiBao(soLuongBaiBao){}

DETAIKH::~DETAIKH(){}

void DETAIKH::Nhap()
{
	cin.ignore();
	cout << "Nhap ma de tai: ";
	getline(cin, maDT);
	cout << "Nhap ten de tai: ";
	getline(cin, tenDT);
	cout << "Nhap ngay dang ky: ";
	cin >> ngayDK;
	cout << "Nhap thoi gian thuc hien: ";
	cin >> thoiGianThucHien;
	cout << "Nhap ngay thuc hien: ";
	cin >> ngayNghiemThu;
	cout << "Nhap so luong bai bao: ";
	cin >> soLuongBaiBao;
}

void DETAIKH::Xuat()
{
	cout << "\t Ma de tai: " << maDT << "\t Ten de tai: " << tenDT << "\t Ngay dang ky: " << ngayDK << "\t Thoi gian thuc hien: " << thoiGianThucHien << "\t Ngay nghiem thu: " << ngayNghiemThu << "\t So luong bai bao: " << soLuongBaiBao;
}
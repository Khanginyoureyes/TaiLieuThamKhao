#pragma once
#ifndef _CongTy
#define _CongTy
#include "NVXS.h"
#include "NVCT.h"
#include "TTS.h"
#include "algorithm"

class CongTy {
private:
	NVXS** dsxs;
	int sl;
public:
	CongTy();
	~CongTy();
	int GetSL();
	void Nhap();
	NVXS* Nhap1();
	void Xuat();
	double TinhTienThuongTrungBinhCuaNhanVien();
	void LietKeNhanVienCoTienThuongCaoHonTB();
	bool KiemTraTTSKhongCoThuongNhungCoDCMTu8();
	bool soSanhNVCTGiamDan(NVXS*, NVXS*);
	bool soSanhTTSTangDan(NVXS*, NVXS*);
	void SapXepNhanSu();
	void TimNhanSuCoMaSo(string);
	void sapXepNVCTGiamDan(NVXS**, int);
	void sapXepTTSTangDan(NVXS**, int);
};

#endif // !_CongTy

#pragma once
#ifndef _TDH
#define _TDH
#include "SV.h"
#include "SVCQ.h"
#include "SVLT.h"

class TDH
{
private:
	SV** dssv;
	int sl;
public:
	~TDH();
	TDH();
	int getSL();
	void Nhap();
	void Xuat();
	SV* Nhap1();
	string doiChuoiInHoa(string);
	void lietKeSVCQCoDRL100();
	int demSoLuongSVLTKhongNghi();
	long tinhTongHocBong();
	double tinhDTBCuaSVCQDuocCapHocBong();
	bool kiemTraSVLTCoDTB9VaKhongNghi();
	void timSVCQCoDTBCaoNhat();
	void sapXepDanhSachTangDan();
	void them1SVMoi(SV*, int);
	int xoa1SV(string);
	void timKiemSV(string, string, string, double, long);
};
#endif // !_TDH

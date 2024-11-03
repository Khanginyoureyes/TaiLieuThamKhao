#pragma once
#ifndef _SV
#define _SV
#include "NGUOI.h"

class SV : public NGUOI {
protected:
	int namhoc;
	pair<int, int> nienkhoa;
	string truonghoc;
	string nganhhoc;
public:
	SV(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0, int = 1, pair<int, int> = { 0, 0 }, string = "", string = "");
	~SV();
	int GetNamHoc();
	pair<int, int> GetNienKhoa();
	string GetTruongHoc();
	string GetNganhHoc();
	void SetNamHoc(int);
	void SetNienKhoa(pair<int, int>);
	void SetTruongHoc(string);
	void SetNganhHoc(string);
	string GetLoai();
	void Nhap();
	void Xuat();

};

#endif // !_SV

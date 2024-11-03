#pragma once
#ifndef _HS
#define _HS
#include "NGUOI.h"

class HS : public NGUOI {
protected:
	string truonghoc;
	string lophoc;
public:
	HS(string = "", CDate ngaysinh = CDate(1, 1, 1), string = "", int = 0, string = "", string = "");
	~HS();
	string GetTruongHoc();
	string GetLopHoc();
	void SetTruongHoc(string);
	void SetLopHoc(string);
	string GetLoai();
	void Nhap();
	void Xuat();

};

#endif 

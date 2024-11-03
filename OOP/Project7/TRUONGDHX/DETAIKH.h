#pragma once
#ifndef _DETAIKH
#define _DETAIKH
#include "BAIBAO.h"

class DETAIKH
{
private:
	string maDT, tenDT;
	int ngayDK, thoiGianThucHien, ngayNghiemThu, soLuongBaiBao;
public:
	DETAIKH(string = "", string = "", int = 0, int = 0, int = 0, int = 0);
	~DETAIKH();
	void Nhap();
	void Xuat();

};

#endif // !

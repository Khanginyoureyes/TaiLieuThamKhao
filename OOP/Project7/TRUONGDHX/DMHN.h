#pragma once
#ifndef _DMHN
#define _DMHN
#include "BAIBAO.h"

class DMHN : public BAIBAO
{
private:
	int XepHang;
public:
	DMHN(int = 0);
	~DMHN();
	void Nhap();
	void Xuat();

	int getTongSoTiet();
};
#endif // !_DMHN
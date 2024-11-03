#pragma once
#ifndef _BAIBAO
#define _BAIBAO
#include <iostream>
#include <string>
using namespace std;

class BAIBAO
{
protected:
	string mabb, tenbb, lienket, tgchinh, dongtg;
	int namsb;
	bool deTaiNghienCuu;
public:
	BAIBAO(string = "", string = "", string = "", string = "", string = "", int = 0);
	~BAIBAO();
	virtual void Nhap();
	virtual void Xuat();

	virtual int getTongSoTiet() = 0;
};

#endif // !_BAIBAO

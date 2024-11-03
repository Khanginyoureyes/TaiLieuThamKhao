#pragma once
#ifndef _HINHCAU
#define _HINHCAU
#include "HinhTron.h"

class HINHCAU : public HINHTRON
{
public:
	HINHCAU(double = 0, double = 0, double = 0, double = 1);
	HINHCAU(const HINHCAU&);
	~HINHCAU();
	double tinhDTMatCau() const;
	double tinhTTCau() const;
};
#endif // !_HINHCAU

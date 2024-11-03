#include "HinhCau.h"

HINHCAU::~HINHCAU(){}

HINHCAU::HINHCAU(double x, double y, double z, double R) : HINHTRON(x, y, z, R){}

HINHCAU::HINHCAU(const HINHCAU& hc) : HINHTRON(hc.x, hc.y, hc.z, hc.R){}

double HINHCAU::tinhDTMatCau() const
{
	return 4 * PI * pow(R, 2);
}

double HINHCAU::tinhTTCau() const
{
	return (4.0 / 3.0) * PI * pow(R, 3);
}
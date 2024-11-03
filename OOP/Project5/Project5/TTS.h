#ifndef _TTS
#define _TTS
#include "NVXS.h"

class TTS : public NVXS {
protected:
	double diemchuyencan;
	double diemchuyenmon;
public:
	TTS(string = "", string = "", string = "", double = 0, double = 0);
	~TTS();
	double GetDCC();
	double GetDCM();
	void SetDCC(double);
	void SetDCM(double);
	string GetLoai();
	double TinhTienThuong();
	void Nhap();
	void Xuat();
};
#endif // !_TTS

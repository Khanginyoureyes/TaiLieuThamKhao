#include "TTS.h"

TTS::TTS(string maso, string hoten, string diachi, double diemchuyencan, double diemchuyenmon) : NVXS(maso, hoten, diachi),
diemchuyencan(diemchuyencan), diemchuyenmon(diemchuyenmon) {}

TTS::~TTS()
{

}

double TTS::GetDCC()
{
	return diemchuyencan;
}

double TTS::GetDCM()
{
	return diemchuyenmon;
}

void TTS::SetDCC(double dcc)
{
	diemchuyencan = dcc;
}

void TTS::SetDCM(double dcm)
{
	diemchuyenmon = dcm;
}

string TTS::GetLoai()
{
	return "TTS";
}

double TTS::TinhTienThuong()
{
	if (diemchuyencan >= 8)
	{
		if (diemchuyenmon >= 8 && diemchuyenmon < 9)  return 5000000;
		else if (diemchuyenmon >= 9 && diemchuyenmon < 10) return 8000000;
		else if (diemchuyenmon == 10)  return 10000000;
	}
	else return 0;
}

void TTS::Nhap()
{
	NVXS::Nhap();
	cout << "Nhap diem chuyen can: ";
	cin >> diemchuyencan;
	cout << "Nhap diem chuyen mon: ";
	cin >> diemchuyenmon;
}

void TTS::Xuat()
{
	NVXS::Xuat();
	cout << "\t Diem chuyen can: " << diemchuyencan << "\t Diem chuyen mon: " << diemchuyenmon << endl;
}
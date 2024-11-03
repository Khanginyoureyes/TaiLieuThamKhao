#include "XH.h"

XH::XH()
{
	dsnguoi = NULL;
	sl = 0;
}

XH::~XH()
{
	if (dsnguoi != NULL)
	{
		for (int i = 0; i < sl; i++)
			delete dsnguoi[i];
		delete[]dsnguoi;
		dsnguoi = NULL;
		sl = 0;
	}
}

void XH::Nhap()
{
	int loai;
	do
	{
		cout << "Nhap so luong nguoi: ";
		cin >> sl;
	} while (sl < 1);
	dsnguoi = new NGUOI * [sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "------------------------------------\n";
		cout << "Nhap thong tin nguoi thu " << i + 1 << ": \n";
		do
		{
			cout << "Nhap loai (1: Sinh Vien, 2: Hoc Sinh, 3: Cong Nhan, 4: Ca Si, 5: Nghe Si): ";
			cin >> loai;
		} while (loai < 1 || loai > 5);
		if (loai == 1)
			dsnguoi[i] = new SV;
		if (loai == 2)
			dsnguoi[i] = new HS;
		if (loai == 3)
			dsnguoi[i] = new CN;
		if (loai == 4)
			dsnguoi[i] = new CS;
		if (loai == 5)
			dsnguoi[i] = new NS;
		dsnguoi[i]->Nhap();
	}
}
NGUOI* XH::Nhap1()
{
	int loai;
	NGUOI* NGUOI = NULL;
	do
	{
		cout << "Nhap loai (1: Sinh Vien, 2: Hoc Sinh, 3: Cong Nhan, 4: Ca Si, 5: Nghe Si): ";
		cin >> loai;
	} while (loai < 1 || loai > 5);
	if (loai == 1)
		NGUOI = new SV;
	if (loai == 2)
		NGUOI = new HS;
	if (loai == 3)
		NGUOI = new CN;
	if (loai == 4)
		NGUOI = new CS;
	if (loai == 5)
		NGUOI = new NS;
	NGUOI->Nhap();
	return NGUOI;
}

void XH::Xuat()
{
	if (dsnguoi == NULL)
		cout << "Danh sach nhan vien rong\n";
	else
		for (int i = 0; i < sl; i++)
			dsnguoi[i]->Xuat();
}
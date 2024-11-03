#include "CT.h"
#include "NVSX.h"
#include "NVVP.h"

CT::CT()
{
	dsnv = NULL;
	sl = 0;
}

CT::~CT()
{
	if (dsnv != NULL)
	{
		for (int i = 0; i < sl; i++)
			delete dsnv[i];
		delete[]dsnv;
		dsnv = NULL;
		sl = 0;
	}
}

void CT::Nhap()
{
	int loai;
	do
	{
		cout << "Nhap so luong nhan vien: ";
		cin >> sl;
	} while (sl < 1);
	dsnv = new NV * [sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "------------------------------------\n";
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ": \n";
		do
		{
			cout << "Nhap loai (1: NVSX, 2: NVVP): ";
			cin >> loai;
		} while (loai < 1 || loai > 2);
		if (loai == 1)
			dsnv[i] = new NVSX;
		if (loai == 2)
			dsnv[i] = new NVVP;
		dsnv[i]->Nhap();
	}
}

NV* CT::Nhap1()
{
	int loai;
	NV* nv = NULL;
	do
	{
		cout << "Nhap loai (1: NVSX, 2: NVVP): ";
		cin >> loai;
	} while (loai < 1 || loai > 2);
	if (loai == 1)
		nv = new NVSX;
	else if (loai == 2)
		nv = new NVVP;
	nv->Nhap();
	return nv;
}

void CT::Xuat()
{
	if (dsnv == NULL)
		cout << "Danh sach nhan vien rong\n";
	else
		for (int i = 0; i < sl; i++)
			dsnv[i]->Xuat();
}
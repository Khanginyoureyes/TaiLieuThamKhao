	#include "TRUONGDAIHOC.h"

TDH::~TDH()
{
	if (dssv != NULL)
	{
		for (int i = 0; i < sl; i++)
		{
			delete dssv[i];
		}
		delete[] dssv;
	}
	
}

TDH::TDH()
{
	dssv = NULL;
	sl = 0;
}

int TDH::getSL()
{
	return sl;
}

void TDH::Nhap()
{
	do
	{
		cout << "Nhap so luong sinh vien: ";
		cin >> sl;
	} while (sl < 0);
	dssv = new SV* [sl];
	for (int i = 0; i < sl; i++)
	{
		int loai;
		do
		{
			cout << "Nhap loai (1 - SVCQ, 2 - SVLT): ";
			cin >> loai;
		} while (loai < 1 || loai > 2);
		if (loai == 1)
		{
			dssv[i] = new SVCQ;
		}
		else if (loai == 2)
		{
			dssv[i] = new SVLT;
		}
		dssv[i]->Nhap();
	}
}

void TDH::Xuat()
{
	if (sl != 0)
	{
		for (int i = 0; i < sl; i++)
		{
			dssv[i]->Xuat();
			cout << endl;
		}
	}
	else cout << "Danh sach rong!\n";
}

SV* TDH::Nhap1()
{
	SV* sv = NULL;
	int loai;
	do
	{
		cout << "Nhap loai (1 - SVCQ, 2 - SVLT): ";
		cin >> loai;
	} while (loai < 1 || loai > 2);
	if (loai == 1)
	{
		sv = new SVCQ;
	}
	else if (loai == 2)
	{
		sv = new SVLT;
	}
	sv->Nhap();
	return sv;
}

string TDH::doiChuoiInHoa(string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

void TDH::lietKeSVCQCoDRL100()
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
	{
		if (dssv[i]->getLoai() == "SVCQ" && dssv[i]->getDRL() == 100)
		{
			dssv[i]->Xuat();
			dem++;
		}
	}
	if (dem == 0)
	{
		cout << "Khong co SVCQ co drl la 100\n";
	}
}

int TDH::demSoLuongSVLTKhongNghi()
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
	{	
		if (dssv[i]->getSoBuoiVang() == 0 && dssv[i]->getLoai() == "SVLT")
		{
			dem++;
		}
	}
	return dem;
}

long TDH::tinhTongHocBong()
{
	long sum = 0;
	for (int i = 0; i < sl; i++)
	{
		sum += dssv[i]->tinhTienHocBong();
	}
	return sum;
}

double TDH::tinhDTBCuaSVCQDuocCapHocBong()
{
	
	double sum = 0;
	for (int i = 0; i < sl; i++)
	{
		if (dssv[i]->tinhTienHocBong() > 0 && dssv[i]->getLoai() == "SVCQ")
		{
			sum += dssv[i]->getDTB();
		}
	}
	return sum;
}

bool TDH::kiemTraSVLTCoDTB9VaKhongNghi()
{
	for (int i = 0; i < sl; i++)
	{
		if (dssv[i]->getDTB() >= 9 && dssv[i]->getLoai() == "SVLT" && dssv[i]->getSoBuoiVang() == 0)
		{
			return true;
			break;
		}
	}
	return false;
}

void TDH::timSVCQCoDTBCaoNhat()
{
	int vt = -1, max1 = -1;
	for (int i = 0; i < sl; i++)
	{
		if (dssv[i]->getLoai() == "SVCQ")
		{
			vt = i;
			max1 = dssv[i]->getDTB();
			break;
		}
	}
	if (vt != -1)
	{
		for (int i = vt; i < sl; i++)
		{
			if (dssv[i]->getLoai() == "SVCQ" && dssv[i]->getDTB() > max1)
			{
				max1 = dssv[i]->getDTB();
			}
		}
		for (int i = 0; i < sl; i++)
		{
			if (dssv[i]->getLoai() == "SVCQ" && dssv[i]->getDTB() == max1)
			{
				dssv[i]->Xuat();
			}
		}
	}
	else cout << "Khong tim thay SVCQ\n";
}

void TDH::sapXepDanhSachTangDan()
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = i + 1; j < sl; j++)
		{
			if (doiChuoiInHoa(dssv[i]->getMSSV()) > doiChuoiInHoa(dssv[j]->getMSSV()))
			{
				swap(dssv[i], dssv[j]);
			}
		}
	}
}

void TDH::them1SVMoi(SV* sv, int vt)
{
	SV** pnew = new SV * [sl + 1];
	for (int i = 0; i < vt - 1; i++)
	{
		pnew[i] = dssv[i];
	}
	pnew[vt - 1] = sv;
	for (int i = vt; i < sl + 1; i++)
	{
		pnew[i] = dssv[sl - 1];
	}
	delete[]dssv;
	dssv = pnew;
	sl++;
}

int TDH::xoa1SV(string mssv)
{
	int vt = -1;
	for (int i = 0; i < sl; i++)
	{
		if (doiChuoiInHoa(dssv[i]->getMSSV()) == doiChuoiInHoa(mssv))
		{
			vt = i;
			break;
		}
	}
	if (vt != -1)
	{
		SV** pnew = new SV * [sl - 1];
		for (int i = 0; i < vt; i++)
		{
			pnew[i] = dssv[i];
		}
		for (int i = vt; i < sl - 1; i++)
		{
			pnew[i] = dssv[i + 1];
		}
		delete[]dssv;
		dssv = pnew;
		sl--;
	}
	return vt;
}

void TDH::timKiemSV(string mssv, string hoten, string khoa, double dtb, long hocBong)
{
		for (int i = 0; i < sl; i++)
		{
			if (dssv[i]->getMSSV() == mssv && doiChuoiInHoa(dssv[i]->getHoTen()) == doiChuoiInHoa(hoten) && doiChuoiInHoa(dssv[i]->getKhoa()) == doiChuoiInHoa(khoa) && dssv[i]->getDTB() == dtb && dssv[i]->tinhTienHocBong() == hocBong)
			{
				dssv[i]->Xuat();
			}
		}	
}
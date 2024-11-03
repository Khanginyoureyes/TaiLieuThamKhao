#include "CongTy.h"

CongTy::CongTy()
{
	dsxs = NULL;
	sl = 0;
}

CongTy::~CongTy()
{
	if (dsxs != NULL)
	{
		for (int i = 0; i < sl; i++)
			delete dsxs[i];
		delete[] dsxs;
		dsxs = NULL;
		sl = 0;
	}
}

int CongTy::GetSL()
{
	return sl;
}

void CongTy::Nhap()
{
	int loai;
	do
	{
		cout << "Nhap so luong nhan vien: ";
		cin >> sl;
	} while (sl < 1);
	dsxs = new NVXS * [sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "------------------------------------\n";
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ": \n";
		do
		{
			cout << "Nhap loai (1: NVCT, 2: TTS): ";
			cin >> loai;
		} while (loai < 1 || loai > 2);
		if (loai == 1)
			dsxs[i] = new NVCT;
		if (loai == 2)
			dsxs[i] = new TTS;
		dsxs[i]->Nhap();
	}
}

NVXS* CongTy::Nhap1()
{
	int loai;
	NVXS* nv = NULL;
	do
	{
		cout << "Nhap loai (1: NVCT, 2: TTS): ";
		cin >> loai;
	} while (loai < 1 || loai > 2);
	if (loai == 1)
		nv = new NVCT;
	if (loai == 2)
		nv = new TTS;
	nv->Nhap();
	return nv;
}

void CongTy::Xuat()
{
	if (dsxs == NULL)
		cout << "Danh sach nhan vien rong \n";
	else
	{
		for (int i = 0; i < sl; i++)
		{
			dsxs[i]->Xuat();
		}
	}
}

double CongTy::TinhTienThuongTrungBinhCuaNhanVien()
{
	double tongtttb = 0;
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (dsxs[i]->GetLoai() == "NVCT")
		{
			tongtttb += ((NVCT*)dsxs[i])->TinhTienThuong();
			dem++;
		}
	return dem > 0 ? tongtttb / dem : 0;
}

void CongTy::LietKeNhanVienCoTienThuongCaoHonTB()
{
	int dem = 0;
	double tongtttb = TinhTienThuongTrungBinhCuaNhanVien();
	for (int i = 0; i < sl; i++)
		if (dsxs[i]->GetLoai() == "NVCT" && ((NVCT*)dsxs[i])->TinhTienThuong() > tongtttb)
		{
			dsxs[i]->Xuat();
			dem++;
		}
	if (dem == 0) cout << "Khong co nhan vien nao co tien thuong cao hon trung binh \n";
}

bool CongTy::KiemTraTTSKhongCoThuongNhungCoDCMTu8()
{
	bool kiemtra = false;
	for (int i = 0; i < sl; i++)
		if (dsxs[i]->GetLoai() == "TTS" && ((TTS*)dsxs[i])->GetDCC() < 8 && ((TTS*)dsxs[i])->GetDCM() >= 8)
		{
			kiemtra = true;
		}
	return kiemtra;
}
bool CongTy::soSanhNVCTGiamDan(NVXS* a, NVXS* b) {
	return ((NVCT*)a)->TinhTienThuong() > ((NVCT*)b)->TinhTienThuong();
}

bool CongTy::soSanhTTSTangDan(NVXS* a, NVXS* b) {
	return ((TTS*)a)->TinhTienThuong() < ((TTS*)b)->TinhTienThuong();
}

void CongTy::sapXepNVCTGiamDan(NVXS** ds, int soLuong) {
	for (int i = 0; i < soLuong - 1; ++i)
		for (int j = i + 1; j < soLuong; ++j)
			if (!soSanhNVCTGiamDan(ds[i], ds[j]))
				swap(ds[i], ds[j]);
}

void CongTy::sapXepTTSTangDan(NVXS** ds, int soLuong) {
	for (int i = 0; i < soLuong - 1; ++i)
		for (int j = i + 1; j < soLuong; ++j)
			if (!soSanhTTSTangDan(ds[i], ds[j]))
				swap(ds[i], ds[j]);
}

void CongTy::SapXepNhanSu() {
	int soLuongNVCT = 0;
	int soLuongTTS = 0;

	for (int i = 0; i < sl; ++i)
		if (dsxs[i]->GetLoai() == "NVCT")
			soLuongNVCT++;
		else if (dsxs[i]->GetLoai() == "TTS")
			soLuongTTS++;

	NVXS** danhSachNVCT = new NVXS * [soLuongNVCT];
	NVXS** danhSachTTS = new NVXS * [soLuongTTS];

	int chiSoNVCT = 0;
	int chiSoTTS = 0;

	for (int i = 0; i < sl; ++i)
		if (dsxs[i]->GetLoai() == "NVCT")
			danhSachNVCT[chiSoNVCT++] = dsxs[i];
		else if (dsxs[i]->GetLoai() == "TTS")
			danhSachTTS[chiSoTTS++] = dsxs[i];

	sapXepNVCTGiamDan(danhSachNVCT, soLuongNVCT);
	sapXepTTSTangDan(danhSachTTS, soLuongTTS);

	int chiSo = 0;
	for (int i = 0; i < soLuongNVCT; ++i)
		dsxs[chiSo++] = danhSachNVCT[i];
	for (int i = 0; i < soLuongTTS; ++i)
		dsxs[chiSo++] = danhSachTTS[i];

	delete[] danhSachNVCT;
	delete[] danhSachTTS;
}
void CongTy::TimNhanSuCoMaSo(string maso)
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (dsxs[i]->GetMaSo() == maso)
		{
			dsxs[i]->Xuat();
			dem++;
		}
	if (dem == 0) cout << "Khong co nhan su nao co ma so giong ban vua nhap. \n";
}

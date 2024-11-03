#include "BAIBAO.h"

BAIBAO::BAIBAO(string mabb, string tenbb, string lienket, string tgchinh, string dongtg, int namsb) : mabb(mabb), tenbb(tenbb), lienket(lienket), tgchinh(tgchinh), dongtg(dongtg), namsb(namsb) {}

BAIBAO::~BAIBAO(){}

void BAIBAO::Nhap()
{
	cin.ignore();
	cout << "Nhap ma bai bao: ";
	getline(cin, mabb);
	cout << "Nhap ten bai bao: ";
	getline(cin, tenbb);
	cout << "Nhap lien ket tham chieu: ";
	getline(cin, lienket);
	cout << "Nhap nam xuat ban: ";
	cin >> namsb;
	cout << "Bai bao co la de tai nghien cuu khong(0 - khong, 1 - co): ";
	cin >> deTaiNghienCuu;
}

void BAIBAO::Xuat()
{
	cout << "Ma bai bao: " << mabb << "\t Ten bai bao: " << tenbb << "\t Lien ket tham chieu: " << lienket << "\t Nam xuat ban: " << namsb;
	if (deTaiNghienCuu == 0)
	{
		cout << getTongSoTiet();
	}
	else if (deTaiNghienCuu == 1)
	{
		cout << getTongSoTiet() * 65 / 100;
	}	
}


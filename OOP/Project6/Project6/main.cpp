#include "HinhCau.h"

int main()
{
	HINHCAU hc;
	int choice;
	do
	{
		cout << "----------CHUONG TRINH XU LY HINH CAU-------------\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "1. Nhap toa do cua tam va ban kinh\n";
		cout << "2. Xuat toa do va ban kinh hinh cau\n";
		cout << "3. Di chuyen hinh cau\n";
		cout << "4. Tinh dien tich mat cau\n";
		cout << "5. Tinh the tich hinh cau\n";
		cout << "---------------------------------------------------\n";
		cout << "Ban chon la: ";
		cin >> choice;
		switch (choice)
		{
		case 0: 
			cout << "Da thoat chuong trinh\n";
			break;
		case 1:
			cin >> hc;
			break;
		case 2:
			cout << hc;
			break;
		case 3:
			double dx, dy, dz, dR;
			cout << "Nhap toa do va kich thuoc R muon di chuyen\n";
			cout << "Di chuyen x la: ";
			cin >> dx;
			cout << "Di chuyen y la: ";
			cin >> dy;
			cout << "Di chuyen z la: ";
			cin >> dz;
			cout << "Di chuyen R la: ";
			cin >> dR;
			hc.diChuyen(dx, dy, dz, dR);
			break;
		case 4:
			cout << "Dien tich mat cau la: " << hc.tinhDTMatCau() << endl;
			break;
		case 5:
			cout << "The tich hinh cau la: " << hc.tinhTTCau() << endl;
			break;
		default:
			cout << "Ban da chon sai. Hay chon lai!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}
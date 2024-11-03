#include "CongTy.h"

int main()
{
	CongTy ct;
	int chon;
	do
	{
		cout << "==========CHUONG TRINH XU LY CONG TY==========\n";
		cout << "1. Nhap danh sach nhan vien. \n";
		cout << "2. Xuat danh sach nhan vien. \n";
		cout << "3. Liet ke danh sach nhan vien co tien thuong cao hon trung binh. \n";
		cout << "4. Kiem tra cong ty co thuc tap sinh khong co tien thuong nhung co diem chuyen mon tu 8 tro len. \n";
		cout << "5. Sap xep danh sach nhan su. \n";
		cout << "6. Tim nhan su co ma so do nguoi dung nhap vao. \n";
		cout << "0. Thoat khoi chuong trinh.\n";
		cout << "Moi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
			cout << "Dang thoat khoi chuong trinh......\n";
			break;
		case 1:
			ct.Nhap();
			break;
		case 2:
			ct.Xuat();
			break;
		case 3:
			ct.LietKeNhanVienCoTienThuongCaoHonTB();
			break;
		case 4:
			if (ct.KiemTraTTSKhongCoThuongNhungCoDCMTu8())
				cout << "Cong ty co thuc tap sinh khong co tien thuong nhung co diem chuyen mon tu 8 tro len. \n";
			else
				cout << "Cong ty khong co thuc tap sinh khong co tien thuong nhung co diem chuyen mon tu 8 tro len. \n";
			break;
		case 5:
			ct.SapXepNhanSu();
			cout << "Danh sach nhan vien sau khi duoc sap xep: \n";
			ct.Xuat();
			break;
		case 6:
		{
			string masocantim;
			cin.ignore();
			cout << "Nhap ma so can tim: ";
			getline(cin, masocantim);
			ct.TimNhanSuCoMaSo(masocantim);
			break;
		}
		default:
			cout << "Ban nhap sai vui long nhap lai. \n";
			break;
		}
	} while (chon != 0);
}
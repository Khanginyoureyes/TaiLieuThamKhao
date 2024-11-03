#include "CT.h"

int main() {
    CT congty;
    int chon;

    do
    {
        cout << "----------CT QUAN LY NHAN VIEN TRONG CONG TY----------\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "1. Nhap d/s nhan vien\n";
        cout << "2. Xuat d/s nhan vien\n";
        cout << "3. Liet ke d/s nhan vien co he so luong tu 3.5 tro len\n";
        cout << "4. Dem so luong nhan vien hop dong co so ngay cong la 26\n";
        cout << "5. Tinh tong tien luong da tra cho cac nhan vien\n";
        cout << "6. Tinh tien luong trung binh cua cac NVBC\n";
        cout << "7. Kiem tra cong ty co NVHD khong di lam ngay nao khong\n";
        cout << "8. Tim cac NVBC co he so luong cao nhat\n";
        cout << "9. Sap xep d/s nhan vien co thu tu tang dan theo ma so\n";
        cout << "10. Them 1 nhan vien moi vao vi tri bat ki\n";
        cout << "11. Xoa 1 nhan vien\n";
        cout << "12. Ghi file\n";
        cout << "13. Doc file\n";
        cout << "------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 0:
            cout << "Da thoat chuong trinh\n";
            break;
        case 1:
            congty.Nhap();
            break;
        case 2:
            congty.Xuat();
            break;
        case 3:
            congty.lietKeNVCoHSLTu35TroLen();
            break;
        case 4:
            cout << "Co " << congty.demNCHDCoSNC26() << " nhan vien hop dong co so ngay cong la 26 ngay\n";
            break;
        case 5:
            cout << "Tong tien luong da tra cho cac nhan vien la: " << congty.tinhTongTienLuong() << endl;
            break;
        case 6:
            cout << "Tien luong trung binh cua cac nhan vien bien che la: " << congty.tinhTienLuongTBCuaNVBC() << endl;
            break;
        case 7:
            if (congty.kiemTraNVHDKhongDiLam())
            {
                cout << "Co NVHD khong di lam\n";
            }
            else cout << "Khong co NVHD khong di lam\n";
            break;
        case 8:
            congty.timNVBCCoHSLCaoNhat();
            break;
        case 9:
            cout << "Danh sach nhan vien sau khi duoc sap xep tang dan: \n";
            congty.sapXepMaSoTangDan();
            congty.Xuat();
            break;
        case 10:
        {
            NV* nv;
            int vt = 1;
            nv = congty.Nhap1();
            if (congty.getSL() > 0)
            {
                do
                {
                    cout << "Nhap vi tri muon them nhan vien tu 1 den " << congty.getSL() + 1 << endl;
                    cin >> vt;
                } while (vt < 1 || vt > congty.getSL() + 1);
            }
            congty.themNVMoi(nv, vt);
            cout << "Danh sach nhan vien sau khi them la: \n";
            congty.Xuat();
            break;
        }
        case 11:
            if (congty.getSL() > 0)
            {
                string maso;
                cout << "Nhap ma so nhan vien muon xoa: ";
                cin >> maso;
                int kq = congty.xoaNV(maso);
                if (kq != -1)
                {
                    if (congty.getSL() > 0)
                    {
                        cout << "Danh sach sau khi xoa ma so " << maso << " la:\n";
                        congty.Xuat();
                    }
                    else cout << "Danh sach rong\n";
                }
                else cout << "Khong tim thay ma so can xoa\n";
            }
            else cout << "Danh sach rong\n";
            break;
        case 12:
        {
            string tenFile;
            cin.ignore();
            cout << "Nhap ten file:\n";
            getline(cin, tenFile);
            congty.GhiFile(tenFile);
            break;
        }
        case 13:
        {
            string tenFile;
            cin.ignore();
            cout << "Nhap ten file:\n";
            getline(cin, tenFile);
            congty.DocFile(tenFile);
            break;
        }
        default:
            cout << "Ban nhap sai ! Vui long nhap lai !\n";
            break;
        }
    } while (chon != 0);
    return 0;
}
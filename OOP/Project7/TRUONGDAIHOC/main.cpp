#include "TRUONGDAIHOC.h"

int main() {
    TDH truongDH;
    int chon;

    do
    {
        cout << "----------CT QUAN LY SINH VIEN TRONG TRUONG DAI HOC----------\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "1. Nhap d/s sinh vien\n";
        cout << "2. Xuat d/s sinh vien\n";
        cout << "3. Liet ke d/s sinh vien chinh quy co diem ren luyen la 100\n";
        cout << "4. Dem so luong sinh vien lien thong khong vang hoc\n";
        cout << "5. Tinh tong hoc bong cap cho sinh vien\n";
        cout << "6. Tinh DTB cua cac sinh vien duoc cap hoc bong\n";
        cout << "7. Kiem tra SVLT khong vang hoc va DTB la 9 tro len\n";
        cout << "8. Tim cac sinh vien chinh quy co DTB cao nhat\n";
        cout << "9. Sap xep d/s sinh vien tang dan theo ma so\n";
        cout << "10. Them 1 sinh vien moi vao vi tri bat ki\n";
        cout << "11. Xoa 1 sinh vien\n";
        cout << "12. Tim kiem sinh vien theo(Ma so, ho ten, khoa, DTB, hoc bong)\n";
        cout << "------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 0:
            cout << "Da thoat chuong trinh\n";
            break;
        case 1:
            truongDH.Nhap();
            break;
        case 2:
            truongDH.Xuat();
            break;
        case 3:
            truongDH.lietKeSVCQCoDRL100();
            break;
        case 4:
            cout << "Co " << truongDH.demSoLuongSVLTKhongNghi() << " sinh vien lien thong khong vang hoc buoi nao\n";
            break;
        case 5:
            cout << "Tong hoc bong cap cho sinh vien la: " << truongDH.tinhTongHocBong() << endl;
            break;
        case 6:
            cout << "DTB cua cac sinh vien duoc cap hoc bong la: " << truongDH.tinhDTBCuaSVCQDuocCapHocBong() << endl;
            break;
        case 7:
            if (truongDH.kiemTraSVLTCoDTB9VaKhongNghi())
            {
                cout << "Co SVLT co DTB 9.0 tro len va khong vang hoc buoi nao\n";
            }
            else cout << "Khong co SVLT co DTB 9.0 tro len va khong vang hoc buoi nao\n";
            break;
        case 8:
            truongDH.timSVCQCoDTBCaoNhat();
            break;
        case 9:
            cout << "Danh sach sinh vien sau khi duoc sap xep tang dan: \n";
            truongDH.sapXepDanhSachTangDan();
            truongDH.Xuat();
            break;
        case 10:
        {
            SV* sv;
            int vt = 1;
            sv = truongDH.Nhap1();
            if (truongDH.getSL() > 0)
            {
                do
                {
                    cout << "Nhap vi tri muon them sinh vien tu 1 den " << truongDH.getSL() + 1 << endl;
                    cin >> vt;
                } while (vt < 1 || vt > truongDH.getSL() + 1);
            }
            truongDH.them1SVMoi(sv, vt);
            cout << "Danh sach sinh vien sau khi them la: \n";
            truongDH.Xuat();
            break;
        }
        case 11:
            if (truongDH.getSL() > 0)
            {
                string maso;
                cout << "Nhap ma so sinh vien muon xoa: ";
                cin >> maso;
                int kq = truongDH.xoa1SV(maso);
                if (kq != -1)
                {
                    if (truongDH.getSL() > 0)
                    {
                        cout << "Danh sach sau khi xoa ma so " << maso << " la:\n";
                        truongDH.Xuat();
                    }
                    else cout << "Danh sach rong\n";
                }
                else cout << "Khong tim thay ma so can xoa\n";
            }
            else cout << "Danh sach rong\n";
            break;
        case 12:
        {
            string mssv, hoten, khoa;
            double dtb;
            long hocBong;
            cin.ignore();
            cout << "Nhap cac so lieu de tim sinh vien:\n";
            cout << "Ma so sinh vien: ";
            getline(cin, mssv);
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap khoa: ";
            getline(cin, khoa);
            do
            {
                cout << "Nhap diem trung binh cua sinh vien: ";
                cin >> dtb;
            } while (dtb < 0);
            do
            {
                cout << "Nhap gia tri cua hoc bong: ";
                cin >> hocBong;
            } while (hocBong < 0);
            truongDH.timKiemSV(mssv, hoten, khoa, dtb, hocBong);
            cout << endl;
            break;
        }
        default:
            cout << "Ban nhap sai ! Vui long nhap lai !\n";
            break;
        }
    } while (chon != 0);
    return 0;
}
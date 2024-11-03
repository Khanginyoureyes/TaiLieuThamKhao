#include "CT.h"
#include "NVBC.h"
#include "NVHD.h"
#include <vector>
#include <fstream>
CT::CT()
{
    dsnv = nullptr;
    sl = 0;
}

CT::~CT() {
    if (dsnv != nullptr)
    {
        for (int i = 0; i < sl; ++i)
        {
            delete dsnv[i];
        }
        delete[] dsnv;
    }
}

int CT::getSL()
{
    return sl;
}

void CT::Nhap()
{
    do
    {
        cout << "Nhap so luong nhan vien: ";
        cin >> sl;
    } while (sl < 0);
    dsnv = new NV * [sl];
    vector<string> masoList;
    for (int i = 0; i < sl; ++i)
    {
        int loai;
        do
        {
            cout << "Nhap loai nhan vien (1 - Bien che, 2 - Hop dong): ";
            cin >> loai;
        } while (loai < 1 || loai > 2);
        if (loai == 1)
        {
            dsnv[i] = new NVBC();
        }
        else if (loai == 2)
        {
            dsnv[i] = new NVHD();
        }
        string maso;
        bool TrungLap;
        do
        {
            TrungLap = false;
            dsnv[i]->Nhap();
            maso = dsnv[i]->GetMaSo();
            for (int j = 0; j < masoList.size(); j++)
            {
                if (maso == masoList[j])
                {
                    TrungLap = true;
                    cout << "Ma so bi trung vui long nhap lai:\n";
                    break;
                }
            }
        } while (TrungLap);
        masoList.push_back(maso);
    }
}

void CT::Xuat()
{
    if (sl != 0)
    {
        for (int i = 0; i < sl; ++i)
        {
            dsnv[i]->Xuat();
            cout << endl;
        }
    }
    else cout << "Danh sach rong \n";
}

NV* CT::Nhap1()
{
    NV* nv = NULL;
    int loai;
    do
    {
        cout << "Nhap loai nhan vien (1 - Bien che, 2 - Hop dong): ";
        cin >> loai;
    } while (loai < 1 || loai > 2);
    if (loai == 1)
    {
        nv = new NVBC();
    }
    else if (loai == 2)
    {
        nv = new NVHD();
    }
    nv->Nhap();
    return nv;
}
void CT::lietKeNVCoHSLTu35TroLen()
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
        if (dsnv[i]->getLoai() == "NVBC" && ((NVBC*)dsnv[i])->getHSL() >= 3.5)
        {
            dsnv[i]->Xuat();
            dem++;
        }
    if (dem == 0) cout << "Khong co nhan vien nao co he so luong tu 3.5 tro len\n";
}
string CT::doiChuoiInHoa(string str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}
void CT::sapXepMaSoTangDan()
{
    for (int i = 0; i < sl - 1; i++)
        for (int j = i + 1; j < sl; j++)
            if (doiChuoiInHoa(dsnv[i]->GetMaSo()) > doiChuoiInHoa(dsnv[j]->GetMaSo()))
            {
                swap(dsnv[i], dsnv[j]);
            }
}

int CT::demNCHDCoSNC26()
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVHC" && ((NVHD*)dsnv[i])->getSNC() == 26)
        {
            dem++;
        }
    }
    return dem;
}

long CT::tinhTongTienLuong()
{
    long sum = 0;
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVBC")
        {
            sum += ((NVBC*)dsnv[i])->tinhTienLuong();
        }
    }
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVHD")
        {
            sum += ((NVHD*)dsnv[i])->tinhTienLuong();
        }
    }
    return sum;
}

long CT::tinhTienLuongTBCuaNVBC()
{
    long sum = 0;
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVBC")
        {
            sum += ((NVBC*)dsnv[i])->tinhTienLuong();
            dem++;
        }
    }
    return dem > 0 ? sum / dem : 0;
}

bool CT::kiemTraNVHDKhongDiLam()
{
    bool kt = false;
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVHD" && ((NVHD*)dsnv[i])->getSNC() == 0)
        {
            kt = true;
            break;
        }
    }
    return kt;
}

void CT::timNVBCCoHSLCaoNhat()
{
    int vt = -1;
    int maxHSL = -1;
    for (int i = 0; i < sl; i++)
    {
        if (dsnv[i]->getLoai() == "NVBC")
        {
            vt = i;
            maxHSL = ((NVBC*)dsnv[i])->getHSL();
            break;
        }
    }
    if (vt != -1)
    {
        for (int i = vt; i < sl; i++)
        {
            if (dsnv[i]->getLoai() == "NVBC" && ((NVBC*)dsnv[i])->getHSL() > maxHSL)
            {
                maxHSL = ((NVBC*)dsnv[i])->getHSL();
            }
        }
        for (int i = 0; i < sl; i++)
        {
            if (dsnv[i]->getLoai() == "NVBC" && ((NVBC*)dsnv[i])->getHSL() == maxHSL)
            {
                dsnv[i]->Xuat();
            }
        }
    }
    else
    {
        cout << "Khong co NVBC\n";
    }
}

void CT::themNVMoi(NV* nv, int vt)
{
    NV** pnew = new NV * [sl + 1];
    for (int i = 0; i < vt - 1; i++)
    {
        pnew[i] = dsnv[i];
    }
    pnew[vt - 1] = nv;
    for (int i = vt; i < sl + 1; i++)
    {
        pnew[i] = dsnv[sl - 1];
    }
    delete[]dsnv;
    dsnv = pnew;
    sl++;
}

int CT::xoaNV(string maso)
{
    int vt = -1;
    for (int i = 0; i < sl; i++)
    {
        if (doiChuoiInHoa(dsnv[i]->GetMaSo()) == doiChuoiInHoa(maso))
        {
            vt = i;
            break;
        }
    }
    if (vt != -1)
    {
        NV** pnew = new NV * [sl - 1];
        for (int i = 0; i < vt; i++)
        {
            pnew[i] = dsnv[i];
        }
        for (int i = vt; i < sl - 1; i++)
        {
            pnew[i] = dsnv[i + 1];
        }
        delete[]dsnv;
        dsnv = pnew;
        sl--;
    }
    return vt;
}

/*void CT::GhiFile(string tenFile)
{
    string noidung;
    ofstream outputFile(tenFile);
    if (!outputFile.fail())
    {
        cout << "Nhap noi dung cua file (ket thuc bang dau ~):\n";
        while (true)
        {
            getline(cin, noidung);
            if (noidung.back() != '~')
            {
                outputFile << noidung << endl;
            }
            else
            {
                noidung.back() = '\0';
                outputFile << noidung;
                break;
            }
        }
        outputFile.close();
        cout << "Ghi file thanh cong\n";
    }
    else
    {
        cout << "Loi tao file\n";
    }
}

void CT::DocFile(string tenFile)
{
    string noidung;
    ifstream inputFile(tenFile);
    if (!inputFile.fail())
    {
        while (getline(inputFile, noidung))
        {
            cout << noidung << endl;
            inputFile.close();
            cout << "Da doc file thanh cong\n";
        }
    }
    else
    {
        cout << "Doc file khong thanh cong\n";
    }
}*/

void CT::GhiFile(string tenFile)
{
    ofstream outputFile(tenFile);
    if (!outputFile.fail())
    {
        outputFile << sl << endl;
        string loai;
        for (int i = 0; i < sl; i++)
        {
            loai = dsnv[i]->getLoai();
            outputFile << dsnv[i]->GetMaSo() << endl << dsnv[i]->GetHoTen() << endl << dsnv[i]->GetPhongBan() << endl << loai << endl;
            if (loai == "NVBC")
            {
                outputFile << ((NVBC*)dsnv[i])->getHSL() << endl << ((NVBC*)dsnv[i])->getHSPC() << endl;
            }
            else
            {
                outputFile << ((NVHD*)dsnv[i])->getSNC() << endl << ((NVHD*)dsnv[i])->getTienCong() << endl << ((NVHD*)dsnv[i])->getHSVG() << endl;;
            }
            outputFile << dsnv[i]->tinhTienLuong() << endl;
        }
        outputFile.close();
        cout << "Ghi file thanh cong\n";
    }
    else
    {
        cout << "Ghi file khong thanh cong\n";
    }
}

void CT::DocFile(string tenFile)
{
    ifstream inputFile(tenFile);
    if (!inputFile.fail())
    {
        inputFile >> sl;
        if (sl > 0)
        {
            dsnv = new NV * [sl];
            string ms, hoten, phongban, loai;
            int heSoLuong, heSoPhuCap, soNgayCong, heSoVuotGio;
            long tienCong, tienluong;
            for (int i = 0; i < sl; i++)
            {
                inputFile.ignore();
                getline(inputFile, ms);
                getline(inputFile, hoten);
                getline(inputFile, phongban);
                getline(inputFile, loai);
                if (doiChuoiInHoa(loai) == "NVBC")
                {
                    inputFile >> heSoLuong;
                    inputFile >> heSoPhuCap;
                    dsnv[i] = new NVBC(ms, hoten, phongban, heSoLuong, heSoPhuCap);
                }
                else
                {
                    inputFile >> tienCong;
                    inputFile >> soNgayCong;
                    inputFile >> heSoVuotGio;
                    dsnv[i] = new NVHD(ms, hoten, phongban, tienCong, soNgayCong, heSoVuotGio);
                }
                inputFile >> tienluong;
            }
            cout << "Doc file thanh cong\n";
            Xuat();
        }
    }
    else
    {
        cout << "Doc file khong thanh cong\n";
    }
    inputFile.close();

}

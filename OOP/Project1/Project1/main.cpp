#include"DIEM3c.h"

int main()
{
    cout << "So DIEM 3C hien tai la: " << DIEM3c::GetDem() << endl;
    DIEM3c d1, d2(1), d3(1, 2), d4(1, 2, 3), * d5 = new DIEM3c;
    cout << "So DIEM 3C hien tai la: " << DIEM3c::GetDem() << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << *d5 << endl;
    cout << "Nhap lai toa do DIEM d1:\n";
    cin >> d1;
    cout << "d1_moi: " << d1 << endl;
    if (d1.DIEM::TrungNhau(d4))
        cout << "d1 va d4 trung hoanh do va tung do\n";
    else
        cout << "d1 va d4 khong trung hoanh do va tung do\n";

    if (d1.KiemTraTrung(d4))
        cout << "d1 va d4 trung hoanh do, tung do va cao do\n";
    else
        cout << "d1 va d4 khong trung hoanh do, tung do va cao do\n";
    delete d5;
    cout << "So DIEM 3C con lai la: " << DIEM3c::GetDem() << endl;
    return 0;
}
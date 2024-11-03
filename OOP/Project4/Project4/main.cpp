#include "DIEM3CMAU.h"

int main()
{
	cout << "So diem MAU 3C hien tai la: " << DIEM3CMAU::GetDem() << endl;
	DIEM3CMAU d1, d2(1, 2), d3(1, 2, 3, 50), d4(1, 2, 100, 125, 200), * d5 = new DIEM3CMAU;
	cout << "So diem MAU 3C hien tai la: " << DIEM3CMAU::GetDem() << endl;
	cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << *d5 << endl;
	cout << "Nhap lai toa doa diem MAU 3C d1:\n";
	cin >> d1;
	cout << "d1_moi: " << d1 << endl;
	if (d1.DIEM3C::KiemTraTrung(*d5))
		cout << "d1 va d5 trung hoanh do, tung do va cao do\n";
	else
		cout << "d1 va d5 khong trung hoanh do, tung do va cao do\n";

	if (d1.MAU::KiemTraTrung(*d5))
		cout << "d1 va d5 trung MAU\n";
	else
		cout << "d1 va d5 khong trung MAU\n";
	if (d1.KiemTraTrung(*d5))
		cout << "d1 va d5 trung hoanh do, tung do, cao do va MAU\n";
	else
		cout << "d1 va d5 khong trung hoanh do, tung do, cao do va MAU\n";
	delete d5;
	cout << "So diem MAU 3C hien tai la: " << DIEM3CMAU::GetDem() << endl;
	return 0;
}
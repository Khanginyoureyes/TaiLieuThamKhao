#include <iostream>
using namespace std;

void Insertion_sort(int a[], int n)
{
    int i, j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1; // j = 0
        while (j >= 0 && a[j] > temp)
        // Một là kết thúc bằng cách j - 1
        // Hai là so sánh tới có phần tử nhỏ hơn
        {
            a[j + 1] = a[j];
            j = j - 1; 
        }
        a[j + 1] = temp;
    }
}

void NhapMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap phan ts thu " << i << " : ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[10], n;
    cout << "Nhap do dai mang: ";
    cin >> n;
    NhapMang(a, n);
    cout << "Mang duoc nhap la:" << endl;
    XuatMang(a, n);
    cout << endl;
    Insertion_sort(a, n);
    cout << "Mang sau khi sap xep la" << endl;
    XuatMang(a, n);
    return 0;
}
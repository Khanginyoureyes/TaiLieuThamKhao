#include <iostream>
using namespace std;
void Selection_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int Min = i;
        for(int j = i + 1; j < n; j++)// vòng lặp j dùng để xét min
        {
            if(a[j] < a[Min])
            {
                Min = j;
            }
        }
        if(Min != i)
        {
            swap(a[i], a[Min]);
        }
    }
}
// Cho j chạy để duyệt qua các phần tử 
// Nếu có phần tử nhỏ hơn min thì min = phần tử đó
// khi chạy hết min thì nó sẽ swap với a[i]
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
    cout << "Nhap do dai cua mang:";
    cin >> n;
    NhapMang(a, n);
    cout << "Mang duoc nhap la:" << endl;
    XuatMang(a, n);
    cout << endl;
    Selection_sort(a, n);
    cout << "Mang sau khi sap xep la" << endl;
    XuatMang(a, n);
    return 0;
}
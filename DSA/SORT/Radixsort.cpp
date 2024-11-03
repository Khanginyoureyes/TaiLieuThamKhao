#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<int> &arr)
{
    int max = arr[0];
    // Tìm giá trị lớn nhất trong mảng
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    
    // Thực hiện sắp xếp từng chữ số
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        vector<int> output(arr.size());
        int count[10] = {0};
        
        // Đếm số lần xuất hiện của mỗi chữ số
        for (int i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;
        
        // Tính tổng các số đếm
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        // Chuyển vị trí các phần tử trong mảng đầu ra
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Gán mảng đầu ra vào mảng ban đầu
        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
}

int main()
{
    int n;
    cout << "Nhap so luong phan ts: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixSort(arr);
    cout << "Sorted array is:\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
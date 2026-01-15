#include <iostream>

using namespace std;

class MangSoNguyen
{
private:
    int* data;
    int size;

public:
    MangSoNguyen();
    MangSoNguyen(int length);
    MangSoNguyen(int arr[], int length);
    MangSoNguyen(const MangSoNguyen& msn);
    ~MangSoNguyen();

    void Xuat();

};

MangSoNguyen::MangSoNguyen()
{
    size = 0;
    data = nullptr;
}
MangSoNguyen::MangSoNguyen(int length)
{
    size = length;
    data = new int[size];
    for (int i = 0;i < size;i++)
        data[i] = 0;
}

MangSoNguyen::MangSoNguyen(int arr[], int length)
{
    size = length;
    data = new int[size];
    for (int i = 0;i < size;i++)
        data[i] = arr[i];
}
MangSoNguyen::MangSoNguyen(const MangSoNguyen& msn)
{
    size = msn.size;
    data = new int[size];
    for (int i = 0;i < size;i++)
        data[i] = msn.data[i];
}
MangSoNguyen::~MangSoNguyen()
{
    delete[] data;
}

void MangSoNguyen::Xuat()
{
    for (int i = 0;i < size;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    MangSoNguyen msn1;
    msn1.Xuat();
    MangSoNguyen msn2(5);
    msn2.Xuat();
    int arr[10];
    for (int i = 0; i < 8; i++)
        arr[i] = i * i;
    MangSoNguyen msn3(arr, 8);
    msn3.Xuat();
    MangSoNguyen msn4(msn3);
    msn4.Xuat();

    return 0;
}

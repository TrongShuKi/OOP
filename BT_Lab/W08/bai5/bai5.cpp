#include<iostream>
#include<string>
#include<vector>
#include"lib.h"
using namespace std;

int main()
{
	vector<Hinh*> dsHinh;
	dsHinh.push_back(new HinhTron(3.5));
	dsHinh.push_back(new HinhTamGiacDeu(8.5));
	dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
	dsHinh.push_back(new HinhVuong(4.1));
	dsHinh.push_back(new HinhCau(13.5));
	dsHinh.push_back(new HinhLapPhuong(2.9));
	dsHinh.push_back(new HinhHop(1.2, 3.7, 6.3));
	dsHinh.push_back(new HinhTru(6.1, 4.9));
	dsHinh.push_back(new HinhNon(8.7, 3.2));

	for (int i = 0; i < dsHinh.size(); i++)
	{
		cout << *dsHinh[i] << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
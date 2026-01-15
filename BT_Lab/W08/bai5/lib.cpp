#include<iostream>
#include<string>
#include<vector>
#include"lib.h"
using namespace std;
#define PI 3.14159

//Define class Hinh::
ostream& operator<<(ostream& os, const Hinh& hh)
{
	hh.Xuat(os);
	return os;
}

//Define class HinhTron::
HinhTron::HinhTron(const float& bk)
{
	bankinh = bk;
}
void HinhTron::Xuat(ostream& os) const
{
	os << "Hinh Tron [P = " << calChuVi() << ", S = " << calDienTich() << "]";
}
float HinhTron::calChuVi() const
{
	return 2 * PI * bankinh;
} 
float HinhTron::calDienTich() const
{
	return PI * bankinh * bankinh;
}

//Define class HinhTamGiacDeu::
HinhTamGiacDeu::HinhTamGiacDeu(const float& a)
{
	canh = a;
}
void HinhTamGiacDeu::Xuat(ostream& os) const
{
	os << "Hinh Tam Giac Deu [P = " << calChuVi() << ", S = " << calDienTich() << "]";
}
float HinhTamGiacDeu::calChuVi() const
{
	return 3 * canh;
}
float HinhTamGiacDeu::calDienTich() const
{
	return canh * canh * sqrt(3) / 4;
}

//Define class HinhChuNhat::
HinhChuNhat::HinhChuNhat(const float& cd, const float& cr)
{
	dai = cd;
	rong = cr;
}
void HinhChuNhat::Xuat(ostream& os) const
{
	os << "Hinh Chu Nhat [P = " << calChuVi() << ", S = " << calDienTich() << "]";
}
float HinhChuNhat::calChuVi() const
{
	return (dai + rong) * 2;
}
float HinhChuNhat::calDienTich() const
{
	return dai * rong;
}

//Define class HinhVuong::
HinhVuong::HinhVuong(const float& a)
{
	canh = a;
}
void HinhVuong::Xuat(ostream& os) const
{
	os << "Hinh Vuong [P = " << calChuVi() << ", S = " << calDienTich() << "]";
}
float HinhVuong::calChuVi() const
{
	return 4 * canh;
}
float HinhVuong::calDienTich() const
{
	return canh * canh;
}

//Define class HinhCau::
HinhCau::HinhCau(const float& bk)
{
	bankinh = bk;
}
void HinhCau::Xuat(ostream& os) const
{
	os << "Hinh Cau [Sxq = " << calDTXungQuanh() << ", V = " << calTheTich() << "]";
}
float HinhCau::calDTXungQuanh() const
{
	return 4 * PI * bankinh * bankinh;
}
float HinhCau::calTheTich() const
{
	return (4.0f / 3.0f) * PI * bankinh * bankinh * bankinh;
}

//Define class HinhLapPhuong::
HinhLapPhuong::HinhLapPhuong(const float& a)
{
	canh = a;
}
void HinhLapPhuong::Xuat(ostream& os) const
{
	os << "Hinh Lap Phuong [Sxq = " << calDTXungQuanh() << ", V = " << calTheTich() << "]";
}
float HinhLapPhuong::calDTXungQuanh() const
{
	return 4 * canh * canh;
}
float HinhLapPhuong::calTheTich() const
{
	return canh * canh * canh;
}

//Define class HinhHop::
HinhHop::HinhHop(const float& cd, const float& cr, const float& cc)
{
	dai = cd;
	rong = cr;
	cao = cc;
}
void HinhHop::Xuat(ostream& os) const
{
	os << "Hinh Hop [Sxq = " << calDTXungQuanh() << ", V = " << calTheTich() << "]";
}
float HinhHop::calDTXungQuanh() const
{
	return (dai + rong) * 2 * cao;
}
float HinhHop::calTheTich() const
{
	return dai * rong * cao;
}

//Define class HinhTru::
HinhTru::HinhTru(const float& bkd, const float& cc)
{
	bankinhday = bkd;
	cao = cc;
}
void HinhTru::Xuat(ostream& os) const
{
	os << "Hinh Tru [Sxq = " << calDTXungQuanh() << ", V = " << calTheTich() << "]";
}
float HinhTru::calDTXungQuanh() const
{
	return 2 * PI * bankinhday * cao;
}
float HinhTru::calTheTich() const
{
	return PI * bankinhday * bankinhday * cao;
}

//Define class HinhNon::
HinhNon::HinhNon(const float& bkd, const float& cc)
{
	bankinhday = bkd;
	cao = cc;
}
void HinhNon::Xuat(ostream& os) const
{
	os << "Hinh Non [Sxq = " << calDTXungQuanh() << ", V = " << calTheTich() << "]";
}
float HinhNon::calDTXungQuanh() const
{
	float duongsinh = sqrt(bankinhday * bankinhday + cao * cao);
	return PI * bankinhday * duongsinh;
}
float HinhNon::calTheTich() const
{
	return (1.0f / 3.0f) * PI * bankinhday * bankinhday * cao;
}
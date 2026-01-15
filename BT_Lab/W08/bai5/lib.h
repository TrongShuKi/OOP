#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Hinh
{
private:

public:
	virtual void Xuat(ostream& os) const = 0;

	friend ostream& operator<<(ostream& os, const Hinh& hh);
};

class HinhHocPhang : public Hinh
{
private:

public:
	virtual float calChuVi() const = 0;
	virtual float calDienTich() const = 0;

};

class HinhHocKhongGian : public Hinh
{
private:

public:
	virtual float calDTXungQuanh() const = 0;
	virtual float calTheTich() const = 0;
};

class HinhTron :public HinhHocPhang
{
private:
	float bankinh;
public:
	HinhTron(const float& bk);

	void Xuat(ostream& os) const;
	float calChuVi() const;
	float calDienTich() const;
};

class HinhTamGiacDeu :public HinhHocPhang
{
private:
	float canh;

public:
	HinhTamGiacDeu(const float& a);

	void Xuat(ostream& os) const;
	float calChuVi() const;
	float calDienTich() const;
};

class HinhChuNhat :public HinhHocPhang
{
private:
	float dai, rong;

public:
	HinhChuNhat(const float& cd, const float& cr);

	void Xuat(ostream& os) const;
	float calChuVi() const;
	float calDienTich() const;
};

class HinhVuong :public HinhHocPhang
{
private:
	float canh;

public:
	HinhVuong(const float& a);

	void Xuat(ostream& os) const;
	float calChuVi() const;
	float calDienTich() const;
};

class HinhCau :public HinhHocKhongGian
{
private:
	float bankinh;

public:
	HinhCau(const float& bk);

	void Xuat(ostream& os) const;
	float calDTXungQuanh() const;
	float calTheTich() const;
};

class HinhLapPhuong :public HinhHocKhongGian
{
private:
	float canh;

public:
	HinhLapPhuong(const float& a);

	void Xuat(ostream& os) const;
	float calDTXungQuanh() const;
	float calTheTich() const;
};

class HinhHop :public HinhHocKhongGian
{
private:
	float dai, rong, cao;
public:
	HinhHop(const float& cd, const float& cr, const float& cc);

	void Xuat(ostream& os) const;
	float calDTXungQuanh() const;
	float calTheTich() const;
};

class HinhTru :public HinhHocKhongGian
{
private:
	float bankinhday, cao;

public:
	HinhTru(const float& bkd, const float& cc);

	void Xuat(ostream& os) const;
	float calDTXungQuanh() const;
	float calTheTich() const;
};

class HinhNon :public HinhHocKhongGian
{
private:
	float bankinhday, cao;

public:
	HinhNon(const float& bkd, const float& cc);

	void Xuat(ostream& os) const;
	float calDTXungQuanh() const;
	float calTheTich() const;
};
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class HinhHocPhang
{
protected:

public:
	virtual void Xuat(ostream& os) const = 0;
	virtual void Nhap(istream& is) = 0;
	virtual float CalDienTich() = 0;
	virtual float CalChuVi() = 0;
	virtual string GetType() = 0;

	friend ostream& operator<<(ostream& os, const HinhHocPhang& HHP);
	friend istream& operator>>(istream& is, HinhHocPhang& HHP);

};

class QuanLyHinhHocPhang
{
private:
	vector<HinhHocPhang*> listHHP;

public:
	void addHHP(HinhHocPhang* HHP);
	bool readFile(const char* filename);
	void ThongKe();
};

class HinhChuNhat : public HinhHocPhang
{
private:
	float dai, rong;

public:
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	float CalDienTich();
	float CalChuVi();
	string GetType();
};

class HinhTron : public HinhHocPhang
{
private:
	float bankinh;

public:
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	float CalDienTich();
	float CalChuVi();
	string GetType();

};

class HinhTamGiac : public HinhHocPhang
{
private:
	float a, b, c;

public:
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	float CalDienTich();
	float CalChuVi();
	string GetType();

};

class HinhThangVuong : public HinhHocPhang
{
private:
	float dl, db, h;

public:
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	float CalDienTich();
	float CalChuVi();
	string GetType();

};

//Class QuanLyHinhHocPhang
void QuanLyHinhHocPhang::addHHP(HinhHocPhang* HHP)
{
	listHHP.push_back(HHP);
}
bool QuanLyHinhHocPhang::readFile(const char* filename)
{
	ifstream iF(filename);
	if (!iF)
	{
		cout << "Khong the mo file!\n";
		return false;
	}
	string line;
	while (getline(iF, line)) {
		if (line.empty())
			continue;

		stringstream ss(line);
		string type, params;
		getline(ss, type, ':');
		getline(ss, params);

		for (int i = 0; i < params.size(); i++)
		{
			if (params[i] == ',')
				params[i] = ' ';
		}

		HinhHocPhang* h = nullptr;
		if (type == "hcn") h = new HinhChuNhat();
		else if (type == "htr") h = new HinhTron();
		else if (type == "htg") h = new HinhTamGiac();
		else if (type == "hthv") h = new HinhThangVuong();
		stringstream ssparam(params);
		if (h != nullptr) {
			ssparam >> *h;
			addHHP(h);
		}
	}
	iF.close();
	return true;
}
void QuanLyHinhHocPhang::ThongKe()
{
	int numhcn = 0, numhtr = 0, numhtg = 0, numhthv = 0;
	float TotalS = 0, TotalCV = 0;
	for (int i = 0; i < listHHP.size(); i++)
	{
		string type = listHHP[i]->GetType();
		if (type == "hcn") numhcn++;
		else if (type == "htr") numhtr++;
		else if (type == "htg") numhtg++;
		else if (type == "hthv") numhthv++;

		TotalS += listHHP[i]->CalDienTich();
		TotalCV += listHHP[i]->CalChuVi();
	}

	cout << "Tong so hinh:     " << listHHP.size() << endl;
	cout << "Hinh Chu Nhat:    " << numhcn << endl;
	cout << "Hinh Tron:        " << numhtr << endl;
	cout << "Hinh Tam Giac:    " << numhtg << endl;
	cout << "Hinh Thang Vuong: " << numhthv << endl;
	cout << "\nTong Chu Vi:    " << TotalCV << endl;
	cout << "Tong Dien Tich: " << TotalS << endl;
}

//class HinhHocPhang
ostream& operator<<(ostream& os, const HinhHocPhang& HHP)
{
	HHP.Xuat(os);
	return os;
}
istream& operator>>(istream& is, HinhHocPhang& HHP)
{
	HHP.Nhap(is);
	return is;
}

//class HinhChuNhat
void HinhChuNhat::Xuat(ostream& os) const
{
	os << "hcn: " << dai << " " << rong;
}
void HinhChuNhat::Nhap(istream& is)
{
	is >> dai >> rong;
}
float HinhChuNhat::CalDienTich()
{
	return dai * rong;
}
float HinhChuNhat::CalChuVi()
{
	return (dai + rong) * 2;
}
string HinhChuNhat::GetType()
{
	return "hcn";
}

#define PI 3.14159
//class HinhTron
void HinhTron::Xuat(ostream& os) const
{
	os << "htr: " << bankinh;
}
void HinhTron::Nhap(istream& is)
{
	is >> bankinh;
}
float HinhTron::CalDienTich()
{
	return PI * bankinh * bankinh;
}
float HinhTron::CalChuVi()
{
	return 2 * PI * bankinh;
}
string HinhTron::GetType()
{
	return "htr";
}

//class HinhTamGiac
void HinhTamGiac::Xuat(ostream& os) const
{
	os << "htg: " << a << " " << b << " " << c;
}
void HinhTamGiac::Nhap(istream& is)
{
	is >> a >> b >> c;
}
float HinhTamGiac::CalDienTich()
{
	float p = CalChuVi() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
float HinhTamGiac::CalChuVi()
{
	return a + b + c;
}
string HinhTamGiac::GetType()
{
	return "htg";
}

//class HinhThangVuong
void HinhThangVuong::Xuat(ostream& os) const
{
	os << "hcn: " << dl << " " << db << " " << h;
}
void HinhThangVuong::Nhap(istream& is)
{
	is >> dl >> db >> h;
}
float HinhThangVuong::CalDienTich()
{
	return (dl + db) * h / 2;
}
float HinhThangVuong::CalChuVi()
{
	float canhdayhieu = abs(dl - db);
	float canhhuyen = sqrt(canhdayhieu * canhdayhieu + h * h);
	return dl + db + h + canhhuyen;
}
string HinhThangVuong::GetType()
{
	return "hthv";
}

int main()
{
	QuanLyHinhHocPhang manage;
	manage.readFile("hhp.txt");
	manage.ThongKe();
	return 0;
}
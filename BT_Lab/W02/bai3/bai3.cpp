#include <iostream>
#include <cstring>
using namespace std;

class HocSinh
{
private:
	char* HoTen;
	float mon1, mon2, mon3;
	float dtb;
	int MSSV;

	static int MSCount;
	static float dtbMax;
	static HocSinh* HSGI;

	float calDTB(const float& a, const float& b, const float& c);

public:
	HocSinh();
	HocSinh(const char* hoten, const float& a, const float& b, const float& c);
	HocSinh(const HocSinh& hs);
	~HocSinh();

	void DatHoTen(const char* hoten);
	void GanDiem(const float& a, const float& b, const float& c);
	void In(ostream& os);
	static HocSinh HSDiemTBCaoNhat();
};

float HocSinh::calDTB(const float& a, const float& b, const float& c)
{
	return (a + b + c) / 3;
}

HocSinh::HocSinh()
{
	HoTen = new char[6];
	strcpy_s(HoTen, 6, "*****");
	MSSV = ++MSCount;
	mon1 = mon2 = mon3 = 0;
	dtb = 0;
	if (dtb > dtbMax)
	{
		dtbMax = dtb;
		HSGI = this;
	}
}

HocSinh::HocSinh(const char* hoten, const float& a, const float& b, const float& c)
{
	HoTen = new char[strlen(hoten) + 1];
	strcpy_s(HoTen, strlen(hoten) + 1, hoten);
	MSSV = ++MSCount;
	mon1 = (a < 0) ? 0 : ((a > 10) ? 10 : a);
	mon2 = (b < 0) ? 0 : ((b > 10) ? 10 : b);
	mon3 = (c < 0) ? 0 : ((c > 10) ? 10 : c);
	dtb = calDTB(mon1, mon2, mon3);
	if (dtb > dtbMax)
	{
		dtbMax = dtb;
		HSGI = this;
	}
}

HocSinh::HocSinh(const HocSinh& hs) 
{
	HoTen = new char[strlen(hs.HoTen) + 1];
	strcpy_s(HoTen, strlen(hs.HoTen) + 1, hs.HoTen);
	mon1 = hs.mon1;
	mon2 = hs.mon2;
	mon3 = hs.mon3;
	dtb = hs.dtb;
	MSSV = hs.MSSV;
}

HocSinh::~HocSinh()
{
	delete[] HoTen;
}

void HocSinh::DatHoTen(const char* hoten)
{
	if (HoTen)
		delete[] HoTen;
	HoTen = new char[strlen(hoten) + 1];
	strcpy_s(HoTen, strlen(hoten) + 1, hoten);
}

void HocSinh::GanDiem(const float& a, const float& b, const float& c)
{
	mon1 = (a < 0) ? 0 : ((a > 10) ? 10 : a);
	mon2 = (b < 0) ? 0 : ((b > 10) ? 10 : b);
	mon3 = (c < 0) ? 0 : ((c > 10) ? 10 : c);
	dtb = calDTB(mon1, mon2, mon3);
	if (dtb > dtbMax)
	{
		dtbMax = dtb;
		HSGI = this;
	}
}
void HocSinh::In(ostream& os)
{
	os << "HS: " << HoTen << ", MS: " << MSSV << ", DTB:  " << dtb;
}

HocSinh HocSinh::HSDiemTBCaoNhat()
{
	return *HSGI;
}


int HocSinh::MSCount = 24120000;
float HocSinh::dtbMax = 0;
HocSinh* HocSinh::HSGI = nullptr;

int main()
{
	HocSinh hs1;
	hs1.DatHoTen("Nguyan Van A");
	hs1.GanDiem(7, 8, 10);
	HocSinh hs2("Tran Thi B", 5, 8, 4.5);
	HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
	HocSinh hs4("Le Van D", 7.5, 9, -10);

	hs1.In(cout);
	cout << endl;
	hs2.In(cout);
	cout << endl;
	hs3.In(cout);
	cout << endl;
	hs4.In(cout);
	cout << endl;
	cout << "Hoc sinh co diem TB cao nhat: " << endl;
	HocSinh::HSDiemTBCaoNhat().In(cout);
	cout << endl;

	system("pause");
	return 0;
}
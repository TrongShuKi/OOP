#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class NhanVien
{
protected:
	string HoTen, DiaChi;

public:
	virtual void Xuat(ostream& os) const;
	virtual void Nhap(istream& is);
	virtual bool checkNVXS() = 0;
	virtual bool writeFile(ostream& os) = 0;

	friend ostream& operator<<(ostream& os, const NhanVien& nhanvien);
	friend istream& operator>>(istream& is, NhanVien& nhanvien);

};

class CongTy
{
private:
	vector<NhanVien*> listNhanVien;

public:
	void addNhanVien(NhanVien* nhanvien);
	void displaylistNV();
	void displayNVXS();
	bool readFile(const char* filename);
	bool writeFile(const char* filename);
};

class NhanVienThuKy : public NhanVien
{
private:
	string langCertificate;
	int numReport;

public:
	NhanVienThuKy(string name, string addr, string cert, int numreport);
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	bool checkNVXS();
	bool writeFile(ostream& os);
};

class NhanVienKyThuat : public NhanVien
{
private:
	string proCertificate;
	int numIdea;

public:
	NhanVienKyThuat(string name, string addr, string cert, int numidea);
	void Xuat(ostream& os) const;
	void Nhap(istream& is);
	bool checkNVXS();
	bool writeFile(ostream& os);

};

//class CongTy
void CongTy::addNhanVien(NhanVien* nhanvien)
{
	listNhanVien.push_back(nhanvien);
}
void CongTy::displaylistNV()
{
	for (int i = 0; i < listNhanVien.size(); i++)
		cout << *listNhanVien[i] << endl;
}
void CongTy::displayNVXS()
{
	for (int i = 0; i < listNhanVien.size(); i++)
	{
		if (listNhanVien[i]->checkNVXS())
			cout << *listNhanVien[i] << endl;
	}
}
bool CongTy::readFile(const char* filename)
{
	ifstream iF(filename);
	if (!iF)
	{
		cout << "Khong the mo file!\n";
		return false;
	}
	string line;
	while (getline(iF, line))
	{
		string type, name, addr, cert, numstr;
		stringstream ss(line);
		string temp;
		getline(ss, type, ':');
		getline(ss, temp, ' ');//
		getline(ss, name, '(');
		getline(ss, addr, ')');
		getline(ss, temp, '[');//
		getline(ss, cert, ']');
		getline(ss, temp, '<');//
		getline(ss, numstr, '>');
		if (!name.empty() && name.back() == ' ') {
			name.pop_back();
		}
		if (type == "nvkt")
		{
			NhanVienKyThuat* nvkt = new NhanVienKyThuat(name, addr, cert, stoi(numstr));
			addNhanVien(nvkt);
		}
		else if (type == "nvtk")
		{
			NhanVienThuKy* nvtk = new NhanVienThuKy(name, addr, cert, stoi(numstr));
			addNhanVien(nvtk);
		}
		else
		{
			cout << "Loi dinh dang nghe nghiep!\n";
		}
	}
	iF.close();
	return true;
}
bool CongTy::writeFile(const char* filename)
{
	ofstream oF(filename);
	if (!oF)
	{
		cout << "Khong the mo file!\n";
		return false;
	}
	for (int i = 0; i < listNhanVien.size(); i++)
	{
		listNhanVien[i]->writeFile(oF);
	}
	oF.close();
	return true;
}

//class NhanVien
ostream& operator<<(ostream& os, const NhanVien& nhanvien)
{
	nhanvien.Xuat(os);
	return os;
}
istream& operator>>(istream& is, NhanVien& nhanvien)
{
	nhanvien.Nhap(is);
	return is;
}
void NhanVien::Xuat(ostream& os) const
{
	os << HoTen << " (" << DiaChi << ") ";
}
void NhanVien::Nhap(istream& is) {
	getline(is, HoTen);
	getline(is, DiaChi);
}

//class NhanVienThuKy
NhanVienThuKy::NhanVienThuKy(string name, string addr, string cert, int numreport)
{
	HoTen = name;
	DiaChi = addr;
	langCertificate = cert;
	numReport = numreport;
}
void NhanVienThuKy::Xuat(ostream& os) const
{
	NhanVien::Xuat(os);
	os << "[" << langCertificate << "] <" << numReport << "> ";
}
void NhanVienThuKy::Nhap(istream& is)
{
	NhanVien::Nhap(is);
	getline(is, langCertificate);
	is >> numReport;
}
bool NhanVienThuKy::checkNVXS()
{
	return numReport >= 12;
}
bool NhanVienThuKy::writeFile(ostream& os)
{
	os << "nvtk: " << HoTen << " (" << DiaChi << ") " << "[" << langCertificate << "] " << "<" << numReport << ">\n";
	return true;
}

//class NhanVienKyThuat
NhanVienKyThuat::NhanVienKyThuat(string name, string addr, string cert, int numidea)
{
	HoTen = name;
	DiaChi = addr;
	proCertificate = cert;
	numIdea = numidea;
}

void NhanVienKyThuat::Xuat(ostream& os) const
{
	NhanVien::Xuat(os);
	os << "[" << proCertificate << "] <" << numIdea << "> ";
}
void NhanVienKyThuat::Nhap(istream& is)
{
	NhanVien::Nhap(is);
	getline(is, proCertificate);
	is >> numIdea;
}
bool NhanVienKyThuat::checkNVXS()
{
	return numIdea >= 6;
}
bool NhanVienKyThuat::writeFile(ostream& os)
{
	os << "nvkt: " << HoTen << " (" << DiaChi << ") " << "[" << proCertificate << "] " << "<" << numIdea << ">\n";
	return true;
}

int main()
{
	CongTy MvT;
	MvT.readFile("input.txt");
	MvT.writeFile("output.txt");
	cout << "----DANH SACH NHAN VIEN XUAT SAC----\n";
	MvT.displayNVXS();
	return 0;
}
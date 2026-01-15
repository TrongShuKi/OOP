#include<iostream>
#include<vector>

using namespace std;

class ChiTietMay
{
protected:
	string maso;
	void indent(ostream& os, int level) const 
	{
		for (int i = 0; i < level; ++i) {
			os << "   ";
		}
	}
public:
	ChiTietMay(const string& MS)
	{
		maso = MS;
	}

	virtual float getWeight() = 0;
	virtual float getPrice() = 0;
	virtual void Xuat(ostream& os, int level) const = 0;
};

class ChiTietDon : public ChiTietMay
{
private:
	double weight, price;

public:
	ChiTietDon(const string& MS, const double& W, const double& P): ChiTietMay(MS)
	{
		weight = W;
		price = P;
	}

	float getWeight()
	{
		return weight;
	}
	float getPrice()
	{
		return price;
	}

	void Xuat(ostream& os, int level) const
	{
		indent(os, level);
		os << maso << " " << weight << " " << (long long)price << endl;
	}
};

class ChiTietPhuc : public ChiTietMay
{
private:
	vector<ChiTietMay*> ChiTietCon;

public:
	ChiTietPhuc(const string& MS) : ChiTietMay(MS) {}

	void ThemChiTiet(ChiTietMay* ctm)
	{
		ChiTietCon.push_back(ctm);
	}
	

	float getWeight()
	{
		double totalW = 0;
		for (int i = 0; i < ChiTietCon.size(); i++)
		{
			totalW += ChiTietCon[i]->getWeight();
		}
		return totalW * 1.1;
	}
	float getPrice()
	{
		double totalP = 0;
		for (int i = 0; i < ChiTietCon.size(); i++)
		{
			totalP += ChiTietCon[i]->getPrice();
		}
		return totalP * 1.2;
	}
	void Xuat(ostream& os,int level) const 
	{
		indent(os, level);
		os << maso << ":\n";
		for (int i = 0; i < ChiTietCon.size(); i++)
		{
			ChiTietCon[i]->Xuat(os, level + 1);
		}
	}
};

class CoMay
{
private:
	vector<ChiTietMay*> listCTM;

public:
	void ThemChiTietMay(ChiTietMay* ctm)
	{
		listCTM.push_back(ctm);
	}

	float TrongLuong()
	{
		double totalW = 0;
		for (int i = 0; i < listCTM.size(); i++)
		{
			totalW += listCTM[i]->getWeight();
		}
		return totalW;
	}
	long long GiaThanh()
	{
		double totalP = 0;
		for (int i = 0; i < listCTM.size(); i++)
		{
			totalP += listCTM[i]->getPrice();
		}
		return totalP;
	}

	void Xuat(ostream& os) const
	{
		for (int i = 0; i < listCTM.size(); i++)
		{
			listCTM[i]->Xuat(os, 0);
		}
	}
	friend ostream& operator<<(ostream& os, const CoMay& ctm)
	{
		ctm.Xuat(os);
		return os;
	}
};

int main()
{
	CoMay* pcm = new CoMay();
	pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));

	ChiTietMay* pctm = new ChiTietPhuc("CTP001");
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));

	ChiTietMay* pctm1 = new ChiTietPhuc("CTP002");
	((ChiTietPhuc*)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));

	((ChiTietPhuc*)pctm)->ThemChiTiet(pctm1);

	pcm->ThemChiTietMay(pctm);
	pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
	pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));

	cout << "Thong tin co may: " << endl << *pcm << endl;

	cout << "Trong luong: " << pcm->TrongLuong() << endl;

	cout << "Gia Thanh: " << pcm->GiaThanh() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}
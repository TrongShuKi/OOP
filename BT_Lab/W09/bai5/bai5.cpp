#include<iostream>
#include<vector>

using namespace std;

class Component
{
protected:
	void indent(ostream& os, int level) const
	{
		for (int i = 0; i < level; i++)
			os << "   ";
	}
public:
	string name;

	Component(const string& N)
	{
		name = N;
	}

	virtual void Xuat(ostream& os, int level = 0) const = 0;
	virtual int cntFile() = 0;
	virtual int cntFolder() = 0;
	virtual float getSize() = 0;

	friend ostream& operator<<(ostream& os, const Component& disk)
	{
		disk.Xuat(os);
		return os;
	}
};

class File : public Component
{
private:
	float size;

public:
	File(const string& N, const float& Size) : Component(N)
	{
		size = Size;
	}

	void Xuat(ostream& os, int level) const
	{
		indent(os, level);
		os << name << " (" << size << " B)" << endl;
	}

	int cntFile()
	{
		return 1;
	}
	int cntFolder()
	{
		return 0;
	}
	float getSize()
	{
		return size;
	}
};

class Folder : public Component
{
private:
	vector<Component*> listComponent;

public:
	Folder(const string& N) : Component(N) {}
	void addComponent(Component* comp)
	{
		listComponent.push_back(comp);
	}

	void Xuat(ostream& os, int level) const
	{
		indent(os, level);
		os << "[" << name << "]\n";
		for (int i = 0; i < listComponent.size(); i++)
		{
			listComponent[i]->Xuat(os, level + 1);
		}
	}

	int cntFile()
	{
		int cnt = 0;
		for (int i = 0; i < listComponent.size(); i++)
		{
			cnt += listComponent[i]->cntFile();
		}
		return cnt;
	}
	int cntFolder()
	{
		int cnt = 1; // Tính cả chính nó
		for (int i = 0; i < listComponent.size(); i++)
		{
			cnt += listComponent[i]->cntFolder();
		}
		return cnt;
	}
	float getSize()
	{
		float totalSize = 0;
		for (int i = 0; i < listComponent.size(); i++)
		{
			totalSize += listComponent[i]->getSize();
		}
		return totalSize;
	}
};

int main()
{
	Folder* C = new Folder("C");

	Folder* Baitap= new Folder("Bai tap");
	Folder* LyThuyet = new Folder("Ly thuyet");
	Folder* BaitapC = new Folder("Bai tap C");

	File* BT1doc = new File("BT1.doc", 123.456);
	File* BT2cpp = new File("BT2.cpp", 1.280);
	File* BT2xls = new File("BT2.xls", 23.456);
	File* Ch1 = new File("Ch1.ppt", 34.567);

	BaitapC->addComponent(BT2cpp);

	Baitap->addComponent(BT1doc);
	Baitap->addComponent(BaitapC);
	Baitap->addComponent(BT2xls);

	LyThuyet->addComponent(Ch1);

	C->addComponent(Baitap);
	C->addComponent(LyThuyet);

	//Xuat cay thu muc
	cout << "Cay thu muc:\n" << *C << endl;

	//Dem so tap tin va thu muc ( đếm sâu vào tất cả bên trong )
	cout << "So tap tin va thu muc trong Folder C" << endl;
	cout << "So File: " << C->cntFile() << endl;
	cout << "So Folder: " << C->cntFolder() - 1 << endl; // Đếm Folder bên trong k bao gồm chính nó

	//Tinh kich thuoc thu muc
	C->getSize();
	cout << "Kich thuoc Folder C: " << C->getSize() << " B" << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}
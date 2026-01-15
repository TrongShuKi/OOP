#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class CItem
{
protected:
	string name;
	bool read_only, hidden;

public:
	CItem(const string& N);
	string getName() const;
	bool getHidden() const;
	virtual float getSize() = 0;
	virtual void Xuat() = 0;
	virtual void Print(bool PrintHiddenItem) = 0;
	virtual CItem* RemoveByName(const string& N);
	virtual CItem* FindByName(const string& N);
	virtual void SetHidden(bool isHidden, bool isApplyToSubItem) = 0;
};

class CFile: public CItem
{
private:
	float size;

public:
	CFile(const string& N, const float& Size);
	float getSize();
	void Xuat();
	void Print(bool PrintHiddenItem);
	void SetHidden(bool isHidden, bool isApplyToSubItem);
};

class CFolder: public CItem
{
private:
	vector<CItem*> listItem;

public:
	CFolder(const string& N);
	void Add(CItem* comp);
	float getSize();
	void Xuat();
	void Print(bool PrintHiddenItem);
	CItem* RemoveByName(const string& N);
	CItem* FindByName(const string& N);
	void SetHidden(bool isHidden, bool isApplyToSubItem);
};
#include<iostream>
#include"lib.h"
#include<vector>
using namespace std;

//Implement class CItem
CItem::CItem(const string& N)
{
	name = N;
	read_only = false;
	hidden = false;
}
string CItem::getName() const
{
	return name;
}
bool CItem::getHidden() const
{
	return hidden;
}
CItem* CItem::RemoveByName(const string& N)
{
	return nullptr;
}
CItem* CItem::FindByName(const string& N)
{
	return nullptr;
}

//Implement class CFile
CFile::CFile(const string& N, const float& Size) : CItem(N)
{
	size = Size;
}
float CFile::getSize()
{
	return size;
}
void CFile::Xuat()
{
	cout << "Name:" << name << " Size:" << getSize() << " Read-Only:" << read_only << " Hidden:" << hidden << endl;
}
void CFile::Print(bool PrintHiddenItem)
{
	if (PrintHiddenItem)
		Xuat();
	else
		if (!hidden)
			Xuat();
}
void CFile::SetHidden(bool isHidden, bool isApplyToSubItem)
{
	hidden = isHidden;
}

//Implement class CFolder
CFolder::CFolder(const string& N) : CItem(N) {}
void CFolder::Add(CItem* comp)
{
	listItem.push_back(comp);
}
float CFolder::getSize()
{
	float totalSize = 0;
	for (int i = 0; i < listItem.size(); i++)
	{
		totalSize += listItem[i]->getSize();
	}
	return totalSize;
}
void CFolder::Xuat()
{
	cout << "Name:" << name << " Size:" << getSize() << " Read-Only:" << read_only << " Hidden:" << hidden << endl;
}
void CFolder::Print(bool PrintHiddenItem)
{
	for (int i = 0; i < listItem.size(); i++)
	{
		if (PrintHiddenItem)
			listItem[i]->Xuat();
		else
			if (!listItem[i]->getHidden())
				listItem[i]->Xuat();
	}
}
CItem* CFolder::RemoveByName(const string& N)
{
	CItem* pTemp = nullptr;
	for (int i = 0; i < listItem.size(); i++)
	{
		if (listItem[i]->getName() == N)
		{
			pTemp = listItem[i];
			listItem.erase(listItem.begin() + i);
			return pTemp;
		}
	}
	return nullptr;
}
CItem* CFolder::FindByName(const string& N)
{
	CItem* pTemp = nullptr;
	for (int i = 0; i < listItem.size(); i++)
	{
		if (listItem[i]->getName() == N)
		{
			pTemp = listItem[i];
			return pTemp;
		}
		pTemp = listItem[i]->FindByName(N);
		if (pTemp) break;

	}
	return pTemp;
}
void CFolder::SetHidden(bool isHidden, bool isApplyToSubItem)
{
	hidden = isHidden;
	if (isApplyToSubItem)
	{
		for (int i = 0; i < listItem.size(); i++)
		{
			listItem[i]->SetHidden(isHidden, isApplyToSubItem);
		}
	}
}
#include<iostream>
#include<string>
#include"lib.h"
using namespace std;

//Define Class FS


//Define Class Disk
Disk::Disk(string Name, float Capacity)
{
	name = Name;
	capacity = Capacity;
}
bool Disk::addComponent(Component* comp)
{
	if (comp && getFreeSpace() >= comp->getSize())
	{
		listComponent.push_back(comp);
		return true;
	}
	else
	{
		cout << "Not enough free space!";
		return false;
	}
}
float Disk::getFreeSpace()
{
	float freeSpace = capacity;
	for (int i = 0; i < listComponent.size(); i++)
	{
		freeSpace -= listComponent[i]->getSize();
	}
	return freeSpace;
}

//Define Class Component


//Define Class Folder
Folder::Folder(string Name)
{
	name = Name;
}
void Folder::addComponent(Component* comp)
{
	if (comp)
		listComponent.push_back(comp);
}
float Folder::getSize()
{
	float totalSize = 0;
	for (int i = 0; i < listComponent.size(); i++)
	{
		totalSize += listComponent[i]->getSize();
	}
	return totalSize;
}

//Define Class File
File::File(string Name, string Type, float Size)
{
	name = Name;
	type = Type;
	size = Size;
}
float File::getSize()
{
	return size;
}

//Define Class Shortcut
Shortcut::Shortcut(string Name, Component* Source)
{
	name = Name;
	source = Source;
}
float Shortcut::getSize()
{
	return 1;
}

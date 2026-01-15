#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Component
{
protected:
	string name;

public:
	virtual float getSize() = 0;

};

class Disk
{
private:
	string name;
	float capacity;
	vector<Component*> listComponent;

public:
	Disk(string Name, float Capacity);

	bool addComponent(Component* comp);
	float getFreeSpace(); //KB
};

class FS
{
private:
	vector<Disk*> listDisk;

public:

};

class Folder :public Component
{
private:
	vector<Component*> listComponent;

public:
	Folder(string Name);

	void addComponent(Component* comp);
	float getSize();
};

class File : public Component
{
private:
	string type;
	float size;

public:
	File(string Name, string Type, float Size);

	float getSize();

};

class Shortcut : public Component
{
private:
	Component* source;
public:
	Shortcut(string Name, Component* Source);

	float getSize();

};


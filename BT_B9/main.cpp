#include<iostream>
#include<string>
#include"lib.h"
using namespace std;

int main ()
{
	Disk D("D", 1024);

	Folder folder1("folder1");
	Folder folder2("folder2");

	File file1("file1","text",100);
	File file2("file2", "binary", 50);

	Shortcut sc1("file1_sc", &file1);
	Shortcut sc2("folder2_sc", &folder2);

	D.addComponent(&folder1);
	D.addComponent(&file1);
	D.addComponent(&sc2);
	folder1.addComponent(&folder2);
	folder1.addComponent(&file2);
	folder2.addComponent(&file1);
	folder2.addComponent(&sc1);

	cout << "FreeSpace = " << D.getFreeSpace() << endl;
	return 0;
}
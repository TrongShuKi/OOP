#pragma once
#include <iostream>
using namespace std;

bool ascending(int a, int b);
bool descending(int a, int b);

class Array
{
private:
	int* data;
	int size;

public:
	Array();
	Array(int length);
	Array(const int arr[], int length);
	Array(const Array& other);
	~Array();

	void input();
	void output();
	int getSize();
	void setSize(int newSize);
	int getElement(int index);
	void setElement(int index,int value);
	int find(int value);
	void sortArr(bool (*oder)(int a,int b));

};
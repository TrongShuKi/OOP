#pragma once
#include <iostream>
using namespace std;

class Array
{
protected:
	int size;
	int* data;

public:
	Array();
	Array(int Size, int Data[]);
	Array(const Array& arr);
	~Array();

	int& operator[](int i);
	Array& operator=(const Array& arr);

	int getValue(int index);
	void setValue(int index, int value);
	void display();
};

class HistogramArray : public Array
{
private:
	int* histogram;
	int histSize;

public:
	HistogramArray();
	HistogramArray(int size, int Data[], int hissize);
	HistogramArray(const HistogramArray& hisarr);
	~HistogramArray();
	
	int& operator[](int i);
	HistogramArray& operator=(const HistogramArray& hisarr);

	void setValue(int index, int value);
	void computeHistogram();
	void display();
};
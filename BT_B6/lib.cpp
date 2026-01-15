#include <iostream>
#include "lib.h"
using namespace std;

//class Array
Array::Array()
{
	size = 0;
	data = nullptr;
}

Array::Array(int Size, int Data[])
{
	size = Size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = Data[i];
}

Array::Array(const Array& arr)
{
	size = arr.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = arr.data[i];
	}
}

Array::~Array()
{
	delete[] data;
}

Array& Array::operator=(const Array& arr)
{
	if (this != &arr)
	{
		delete[] data;
		size = arr.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr.data[i];
		}
	}
	return *this;
}

int& Array::operator[](int i)
{
	if (i < 0 || i >= size)
		throw exception("Out of range");
	return data[i];
}

int Array::getValue(int index)
{
	if (index < 0 || index >= size)
		throw exception("Out of range");
	return data[index];
}

void Array::setValue(int index, int value)
{
	if (index < 0 || index >= size)
		throw exception("Out of range");
	data[index] = value;
}

void Array::display()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}


//class HistogramArray
HistogramArray::HistogramArray() : Array()
{
	histSize = 0;
	histogram = nullptr;
}

HistogramArray::HistogramArray(int Size, int Data[], int histsize) :Array(Size, Data)
{
	histSize = histsize;
	histogram = new int[histSize];
	for (int i = 0; i < histSize; i++) {
		histogram[i] = 0;
	}
}

HistogramArray::HistogramArray(const HistogramArray& histarr)
{
	histSize = histarr.histSize;
	histogram = new int[histSize];
	for (int i = 0; i < histSize; i++)
		histogram[i] = histarr.histogram[i];
}

HistogramArray::~HistogramArray()
{
	delete[] histogram;
}

HistogramArray& HistogramArray::operator=(const HistogramArray& hisarr)
{
	if (this != &hisarr)
	{
		histSize = hisarr.histSize;
		histogram = new int[histSize];
		for (int i = 0; i < histSize; i++)
			histogram[i] = hisarr.histogram[i];
	}
	return *this;
}

int& HistogramArray::operator[](int i)
{
	return Array::operator[](i);
}

void HistogramArray::setValue(int index, int value)
{
	Array::setValue(index, value);
	computeHistogram(); 
}

void HistogramArray::computeHistogram()
{
	for (int i = 0; i < histSize; i++)
	{
		histogram[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (data[i] < histSize)
		{
			histogram[data[i]]++;
		}
	}
}

void HistogramArray::display()
{
	cout << "Data     : ";
	Array::display();
	cout << "Histogram: ";
	for (int i = 0; i < histSize; i++)
		cout << histogram[i] << " ";
	cout << endl;
}
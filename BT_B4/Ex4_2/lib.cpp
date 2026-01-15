#include <iostream>
#include "lib.h"
using namespace std;

Array::Array()
{
	size = 0;
	data = nullptr;
}

Array::Array(const Array& arr)
{
	size = arr.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = arr.data[i];
}

Array::~Array()
{
	delete[] data;
}

Array Array::operator+(const Array& arr)
{
	Array res;
	res.size = size + arr.size;
	res.data = new int[res.size];
	for (int i = 0; i < size; i++)
		res.data[i] = data[i];
	for (int i = 0; i < arr.size; i++)
		res.data[i + size] = arr.data[i];
	return res;
}

Array& Array::operator=(const Array& arr)
{
	if (this != &arr)
	{
		delete[] data;
		size = arr.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = arr.data[i];
	}
	return *this;
}

Array& Array::operator+=(const Array& arr)
{
	*this = *this + arr;
	return *this;
}

int& Array::operator[](int idx)
{
	return data[idx];
}

const int& Array::operator[](int idx) const 
{
	return data[idx];
}

Array::operator int* ()
{
	return data;
}

istream& operator>>(istream& in, Array& arr)
{
	in >> arr.size;
	if (arr.data) delete[] arr.data;
	arr.data = new int[arr.size];
	for (int i = 0; i < arr.size; i++)
		in >> arr.data[i];
	return in;
}

ostream& operator<<(ostream& out, const Array& arr)
{
	for (int i = 0; i < arr.size; i++)
		out << arr[i]<<" ";
	return out;
}
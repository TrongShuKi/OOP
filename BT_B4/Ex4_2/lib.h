#pragma once
#include <iostream>
using namespace std;

class Array
{
private:
	int size;
	int* data;

public:
	Array();
	Array(const Array& arr);
	~Array();

	Array operator+(const Array& arr);

	Array& operator=(const Array& arr);
	Array& operator+=(const Array& arr);

	int& operator[](int indx);
	const int& operator[](int idx) const;

	operator int* ();

	friend istream& operator>>(istream& in, Array& arr);
	friend ostream& operator<<(ostream& in, const Array& arr);
};
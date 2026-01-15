#include <iostream>
#include "lib.h"
using namespace std;

Array::Array()
{
	size = 0;
	data = nullptr;
}

Array::Array(int length)
{
	if (length <= 0)
	{
		size = 0;
		data = nullptr;
	}
	else
	{
		size = length;
		data = new int[size];
		for (int i = 0;i < size;i++)
		{
			data[i] = 0;
		}
	}
}

Array::Array(const int arr[], int length)
{
	if (length <= 0)
	{
		size = 0;
		data = nullptr;
	}
	else
	{
		size = length;
		data = new int[size];
		for (int i = 0;i < size;i++)
		{
			data[i] = arr[i];
		}
	}
}

Array::Array(const Array& other)
{
	size = other.size;
	if (size > 0)
	{
		data = new int[size];
		for (int i = 0;i < size;i++)
		{
			data[i] = other.data[i];
		}
	}
	else data = nullptr;
}

Array::~Array()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

void Array::input()
{
	cout << "Enter Size: ";
	cin >> size;

	if (size <= 0)
	{
		size = 0;
		delete[] data;
		data = nullptr;
		return;
	}

	delete[] data;
	data = new int[size];
	cout << "Enter Elements: ";
	for (int i = 0;i < size;i++)
	{
		cin >> data[i];
	}
}

void Array::output()
{
	for (int i = 0;i < size;i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

int Array::getSize()
{
	return size;
}

void Array::setSize(int newSize)
{
	if (newSize < 0) newSize = 0;

	int* newArr = new int[newSize];
	if (data == nullptr) 
	{
		for (int i = 0;i < newSize;i++)
		{
			newArr[i] = 0;
		}
	}
	if (newSize > size && data!=nullptr)
	{
		for (int i = 0;i < size;i++)
		{
			newArr[i] = data[i];
		}
		for (int i = size;i < newSize;i++)
		{
			newArr[i] = 0;
		}
	}
	if (newSize < size && data != nullptr)
	{
		for (int i = 0;i < newSize;i++)
		{
			newArr[i] = data[i];
		}
	}

	delete[] data;
	data = newArr;
	size = newSize;
}

int Array::getElement(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index\n";
		return 0;
	}
	return data[index];
}

void Array::setElement(int index, int value)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index\n";
		return;
	}
	data[index] = value;
}

int Array::find(int value)
{
	for (int i = 0;i < size;i++)
	{
		if (data[i] == value)
			return i;
	}
	return -1;
}

bool ascending(int a,int b)
{
	return a > b;
}
bool descending(int a,int b)
{
	return a < b;
}
void Array::sortArr(bool (*oder)(int a, int b))
{
	if (size <= 1) return;

	for (int i = 0;i < size - 1;i++)
	{
		for (int j = 0;j < size - i - 1;j++)
		{
			if (oder(data[j], data[j + 1]))
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}
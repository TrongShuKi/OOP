#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
	char* data;
	int length;

public:
	MyString();
	~MyString();
	MyString(const MyString& ms);
	MyString(const char* str);

	MyString& operator=(const MyString& ms);
	MyString operator+(const MyString& ms);
	char& operator[](int index);
	char operator[](int index) const;
	SLList<MyString> Split(const SLList<char>& delimiters, bool rmEmpty) const;

	friend MyString operator+(const char* str, const MyString& ms);
	friend ostream& operator<<(ostream& os, const MyString& ms);
};

MyString::MyString()
{
	length = 0;
	data = new char[length + 1];
	data[0] = '\0';
}

MyString::~MyString()
{
	delete[] data;
}

MyString::MyString(const MyString& ms)
{
	length = ms.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, ms.data);
}

MyString::MyString(const char* str)
{
	length = strlen(str);
	data = new char[length + 1];
	strcpy_s(data, length + 1, str);
}

MyString& MyString::operator=(const MyString& ms)
{
	if (this != &ms)
	{
		delete[] data;
		length = ms.length;
		data = new char[length + 1];
		strcpy_s(data, length + 1, ms.data);
	}
	return *this;
}

MyString MyString::operator+(const MyString& ms)
{
	MyString kq;
	kq.length = length + ms.length;
	kq.data = new char[kq.length + 1];

	if (data != nullptr)
		strcpy_s(kq.data, kq.length + 1, data);
	else
		kq.data[0] = '\0';

	if (ms.data!=nullptr)
		strcat_s(kq.data, kq.length + 1, ms.data);
	return kq;
}

char& MyString::operator[](int index)
{
	return data[index];
}

char MyString::operator[](int index) const
{
	return data[index];
}

SLList<MyString> MyString::Split(const SLList<char>& delimiters, bool rmEmpty) const
{
	SLList<MyString> kq;
	MyString token;
	for (int i = 0; i < length; i++)
	{
		bool isDelim = false;
		for (int j = 0; j < delimiters.size(); j++)
		{
			if (delimiters[j] == data[i])
			{
				isDelim = true;
				break;
			}
		}

		if (!isDelim)
		{
			char tmp[2] = { data[i],'\0' };
			token = token + MyString(tmp);
		}
		else
		{
			if (!rmEmpty || token.length > 0)
				kq.push_back(token);
			token = MyString();
		}
	}

	if (!rmEmpty || token.length > 0)
		kq.push_back(token);

	return kq;
}

MyString operator+(const char* str, const MyString& ms)
{
	MyString ms1(str);
	return ms1 + ms;
}

ostream& operator<<(ostream& os, const MyString& ms)
{
	for (int i = 0; i < ms.length; i++)
		os << ms.data[i];
	return os;
}
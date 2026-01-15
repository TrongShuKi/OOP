#pragma once
#include <iostream>
#include "LinkedList.h"
using namespace std;

class SoNguyenLon
{
private:
	int length;
	LinkedList<int> data;

public:
	SoNguyenLon();
	SoNguyenLon(const int& hso);
	SoNguyenLon(const int& num, const int& len);
	SoNguyenLon(const SoNguyenLon& snl);

	bool operator>(const SoNguyenLon& snl);
	bool operator<(const SoNguyenLon& snl);
	bool operator<=(const SoNguyenLon& snl);
	bool operator>=(const SoNguyenLon& snl);
	bool operator==(const SoNguyenLon& snl);

	SoNguyenLon& operator=(const SoNguyenLon& snl);
	SoNguyenLon operator+(const SoNguyenLon& snl);
	SoNguyenLon operator-(const SoNguyenLon& snl);
	SoNguyenLon operator*(const SoNguyenLon& snl);

	SoNguyenLon chuanhoaLength(const int& newLen);
	const SoNguyenLon chuanhoaLength(const int& newLen) const;

	friend SoNguyenLon operator-(const int& value, const SoNguyenLon& snl);
	friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);
};
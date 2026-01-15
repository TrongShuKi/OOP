#include <iostream>
#include <iomanip>
using namespace std;

class ThoiGian
{
private:
	int h, m, s;

public:
	ThoiGian();
	ThoiGian(int second);
	ThoiGian(int minute, int second);
	ThoiGian(int hour, int minute, int second);

	ThoiGian operator+(const ThoiGian& tg);
	ThoiGian operator-(const ThoiGian& tg);
	ThoiGian& operator=(const ThoiGian& tg);
	bool operator>(const ThoiGian& tg);
	bool operator<=(const ThoiGian& tg);

	friend ThoiGian operator+(const int& second, const ThoiGian& tg);
	friend ThoiGian operator-(const int& second, const ThoiGian& tg);
	friend bool operator<=(const int& second, const ThoiGian& tg);

	friend ostream& operator<<(ostream& os, const ThoiGian& tg);

	void Chuanhoa();
};

void ThoiGian::Chuanhoa()
{
	h = abs(h);
	m = abs(m);
	s = abs(s);

	long long sTemp;
	sTemp = h * 3600 + m * 60 + s;
	h = sTemp / 3600;

	sTemp %= 3600;
	m = sTemp / 60;

	sTemp %= 60;
	s = sTemp;
}

ThoiGian::ThoiGian()
{
	h = m = s = 0;
}

ThoiGian::ThoiGian(int second)
{
	s = second;
	h = m = 0;
	Chuanhoa();
}

ThoiGian::ThoiGian(int minute, int second)
{
	m = minute;
	s = second;
	h = 0;
	Chuanhoa();
}

ThoiGian::ThoiGian(int hour, int minute, int second)
{
	h = hour;
	m = minute;
	s = second;
	Chuanhoa();
}

ThoiGian& ThoiGian::operator=(const ThoiGian& tg)
{
	h = tg.h;
	m = tg.m;
	s = tg.s;
	return *this;
}

ThoiGian ThoiGian::operator+(const ThoiGian& tg)
{
	long long totals1 = h * 3600 + m * 60 + s;
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	ThoiGian res(totals1 + totals2);
	return res;
}

ThoiGian ThoiGian::operator-(const ThoiGian& tg)
{
	long long totals1 = h * 3600 + m * 60 + s;
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	ThoiGian res;
	if ((totals1 - totals2) <= 0)
		res = ThoiGian(0);
	else
		res = ThoiGian(totals1 - totals2);
	return res;
}

bool ThoiGian::operator>(const ThoiGian& tg)
{
	long long totals1 = h * 3600 + m * 60 + s;
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	if (totals1 > totals2) 
		return true;
	else 
		return false;
}

bool ThoiGian::operator<=(const ThoiGian& tg)
{
	return !(*this > tg);
}

ThoiGian operator+(const int& second, const ThoiGian& tg)
{
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	ThoiGian res(second + totals2);
	return res;
}

ThoiGian operator-(const int& second, const ThoiGian& tg)
{
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	ThoiGian res;
	if ((second - totals2) <= 0)
		res = ThoiGian(0);
	else
		res = ThoiGian(second - totals2);
	return res;
}

bool operator<=(const int& second, const ThoiGian& tg)
{
	long long totals2 = tg.h * 3600 + tg.m * 60 + tg.s;
	if (second <= totals2) 
		return true;
	else 
		return false;
}

ostream& operator<<(ostream& os, const ThoiGian& tg)
{
	os << setw(2) << setfill('0') << tg.h << ":" 
		<< setw(2) << setfill('0') << tg.m << ":" 
		<< setw(2) << setfill('0') << tg.s;
	return os;
}

int main()
{
	ThoiGian tg1;
	ThoiGian tg2(1212);
	ThoiGian tg3(125, 45);
	ThoiGian tg4(12, 239, -78);
	ThoiGian tg5 = tg2 + tg3;
	ThoiGian tg6 = 5000 + tg2;
	ThoiGian tg7 = tg4 - tg6;
	ThoiGian tg8 = 12300 - tg4;
	ThoiGian tg9, tg10;
	if (tg8 <= tg3)
	{
		tg9 = tg1 + tg2 + 36000;
	}
	if (12345 <= tg5)
	{
		tg10 = tg5 + 12345;
	}
	cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;
	cout << tg5 << endl << tg6 << endl << tg7 << endl << tg8 << endl;
	cout << tg9 << endl << tg10 << endl;
	return 0;
}
#include <iostream>
using namespace std;

class Ngay
{
private:
	int day, month, year;
	static int arrNgayCuaThang[][13];
	static bool LaNamNhuan(const int& n);
	void chuanhoa();
	
public:
	long long dateToDays();
	Ngay();
	Ngay(const int& d, const int& m, const int& y);
	Ngay(const int& d);

	Ngay operator+(const Ngay& date);
	Ngay operator-(const Ngay& date);
	bool operator>(const Ngay& date);

	friend Ngay operator+(const int& d, const Ngay& date);
	friend Ngay operator-(const int& d, const Ngay& date);
	friend ostream& operator<<(ostream& os, const Ngay& date);
};

int Ngay::arrNgayCuaThang[][13] = { {-1,31,28,31,30,31,30,31,31,30,31,30,31},
{-1,31,29,31,30,31,30,31,31,30,31,30,31} };

bool Ngay::LaNamNhuan(const int& n)
{
	return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}

void Ngay::chuanhoa()
{
	day = abs(day);
	month = abs(month);
	year = abs(year);

	while (month > 12) {
		month -= 12;
		year++;
	}
	int idxN = LaNamNhuan(year);
	while (day > arrNgayCuaThang[idxN][month])
	{
		day -= arrNgayCuaThang[idxN][month];
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
			idxN = LaNamNhuan(year);
		}
	}
}

long long Ngay::dateToDays()
{
	long long totalDays = 0;
	for (int y = 1; y < year; y++)
		totalDays += LaNamNhuan(year) ? 366 : 365;
	for (int m = 1; m < month; m++)
		totalDays += arrNgayCuaThang[LaNamNhuan(year)][m];
	totalDays += day;
	return totalDays;
}

Ngay::Ngay()
{
	day = month = year = 1;
}

Ngay::Ngay(const int& d, const int& m, const int& y)
{
	day = d;
	month = m;
	year = y;
	chuanhoa();
}

Ngay::Ngay(const int& d)
{
	day = d;
	month = year = 1;
	chuanhoa();
}

Ngay Ngay::operator+(const Ngay& date)
{

	Ngay dt = *this;
	dt.day += date.day;
	dt.month += date.month;
	dt.year += date.year;
	dt.chuanhoa();
	return dt;
}

Ngay Ngay::operator-(const Ngay& date)
{
	Ngay dt(this->dateToDays() - Ngay(date).dateToDays());
	dt.chuanhoa();
	return dt;
}

bool Ngay::operator>(const Ngay& date)
{
	int flag = 0;
	if (year > date.year) 
		flag = 1;
	if (year == date.year && month > date.month) 
		flag = 1;
	if (year == date.year && month == date.month && day > date.day)
		flag = 1;
	return flag;
}

Ngay operator+(const int& d, const Ngay& date)
{
	Ngay dt(date);
	return Ngay(d + dt.dateToDays());
}

Ngay operator-(const int& d, const Ngay& date)
{
	Ngay dt(d);
	return dt - date;
}

ostream& operator<<(ostream& os, const Ngay& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

int main()
{
	Ngay n1;
	Ngay n2(2, 10, 2014);
	Ngay n3(-10, 16, 2000);
	Ngay n4(1000);
	Ngay n5 =n2 + n3;
	Ngay n6 = n1 + 5000;
	Ngay n7 = 1234 + n4;
	Ngay n8 = 190 + n6 + n7;
	Ngay n9 = n8 - n6;
	Ngay n10 = 12000 - n9;
	if (n10 > n6)
	{
		n10 = n2 - 1000 + n6;
	}
	cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
	cout << n5 << endl << n6 << endl << n7<< endl << n8 << endl;
	cout << n9 << endl << n10 << endl;
	system("pause");
	return 0;
}
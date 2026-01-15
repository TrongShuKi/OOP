#include <iostream>
using namespace std;


class Ngay
{
private:
	int Day;
	int Month;
	int Year;
public:
	Ngay();
	Ngay(const int& day, const int& month, const int& year);
	Ngay(const int& value);
	Ngay(const char* s);
	~Ngay();

	void Xuat();
	void Chuanhoa();
};

Ngay::Ngay()
{
	Day = Month = Year = 1;
}

Ngay::Ngay(const int& day, const int& month, const int& year)
{
	Day = abs(day);
	Month = abs(month);
	Year = abs(year);
	Chuanhoa();
}

Ngay::Ngay(const int& value)
{
	Day = abs(value);
	Month = Year = 1;
	Chuanhoa();
}

Ngay::Ngay(const char* s)
{
	int len = strlen(s);
	char* sTemp = new char[len + 1];
	strcpy_s(sTemp, len + 1, s);

	const char* delimiters = "-/";
	char* temp = nullptr;
	char* sCur = strtok_s(sTemp, delimiters, &temp);
	if (sCur)
		Day = atoi(sCur);
	if (sCur)
	{
		sCur = strtok_s(nullptr, delimiters, &temp);
		if (sCur)
			Month = atoi(sCur);
	}
	if (sCur)
	{
		sCur = strtok_s(nullptr, delimiters, &temp);
		if (sCur)
			Year = atoi(sCur);
	}

	delete[] sTemp;
	Chuanhoa();
}

Ngay::~Ngay()
{

}

void Ngay::Xuat()
{
	cout << Day << "/" << Month << "/" << Year;
}

void Ngay::Chuanhoa()
{
	Day = abs(Day);
	Month = abs(Month);
	Year = abs(Year);
	int monthDu = (Day - 1) / 30;
	Day = (Day - 1) % 30 + 1;
	Month += monthDu;
	int yearDu = (Month - 1) / 12;
	Month = (Month - 1) % 12 + 1;
	Year += yearDu;
}


int main()
{
	Ngay n1;
	n1.Xuat();
	cout << endl;
	Ngay n2(2, 10, 2024);
	n2.Xuat();
	cout << endl;
	Ngay n3(-100, 16, 1990);
	n3.Xuat();
	cout << endl;
	Ngay n4(1403);
	n4.Xuat();
	cout << endl;
	Ngay n5("12-12-2012");
	n5.Xuat();
	cout << endl << endl;

	system("pause");
	return 0;
}
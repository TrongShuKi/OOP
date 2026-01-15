#include <iostream>
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

	void Chuanhoa();
	void Xuat();
};

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

void ThoiGian::Chuanhoa()
{
	if (h < 0) h = 0;
	if (m < 0) m = 0;
	if (s < 0) s = 0;

	long long sTemp;
	sTemp = h * 3600 + m * 60 + s;
	h = sTemp / 3600;

	sTemp %= 3600;
	m = sTemp / 60;

	sTemp %= 60;
	s = sTemp;
}

void ThoiGian::Xuat()
{
	printf("%02d:%02d:%02d\n", h, m, s);
}

int main()
{
	ThoiGian tg1;
	tg1.Xuat();
	ThoiGian tg2(1212);
	tg2.Xuat();
	ThoiGian tg3(125, 45);
	tg3.Xuat();
	ThoiGian tg4(12, 239, -78);
	tg4.Xuat();

	return 0;
}
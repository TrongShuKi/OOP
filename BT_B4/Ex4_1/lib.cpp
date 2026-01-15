#include <iostream>
#include "lib.h"
using namespace std;

Fraction Fraction::operator+(const Fraction& frac)
{
	Fraction res;
	res.num = num * frac.denom + frac.num * denom;
	res.denom = denom * frac.denom;
	return res;
}

Fraction Fraction::operator-(const Fraction& frac)
{
	Fraction res;
	res.num = num * frac.denom - frac.num * denom;
	res.denom = denom * frac.denom;
	return res;
}

Fraction Fraction::operator*(const Fraction& frac)
{
	Fraction res;
	res.num = num * frac.num;
	res.denom = denom * frac.denom;
	return res;
}

Fraction Fraction::operator/(const Fraction& frac)
{
	Fraction res;
	res.num = num * frac.denom;
	res.denom = denom * frac.num;
	return res;
}

bool Fraction::operator>(const Fraction& frac)
{
	return (num * frac.denom > frac.num * denom);
}

bool Fraction::operator<(const Fraction& frac)
{
	return (num * frac.denom < frac.num * denom);
}

bool Fraction::operator>=(const Fraction& frac)
{
	return (num * frac.denom >= frac.num * denom);
}

bool Fraction::operator<=(const Fraction& frac)
{
	return (num * frac.denom <= frac.num * denom);
}

bool Fraction::operator==(const Fraction& frac)
{
	return (num * frac.denom == frac.num * denom);
}

bool Fraction::operator!=(const Fraction& frac)
{
	return (num * frac.denom != frac.num * denom);
}

Fraction& Fraction::operator=(const Fraction& frac)
{
	if (this != &frac)
	{
		num = frac.num;
		denom = frac.denom;
	}
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& frac)
{
	*this = *this + frac;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac)
{
	*this = *this * frac;
	return *this;
}

Fraction& Fraction::operator++()
{
	num = num + denom;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	num = num + denom;
	return temp;
}

Fraction& Fraction::operator--()
{
	num = num - denom;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	num = num - denom;
	return temp;
}

Fraction::operator float() const
{
	return (float)num / denom;
}

Fraction::operator int() const
{
	return num / denom;
}

istream& operator>>(istream& in, Fraction& frac)
{
	in >> frac.num >> frac.denom;
	return in;
}

ostream& operator<<(ostream& out, const Fraction& frac)
{
	out << frac.num << "/" << frac.denom;
	return out;
}
#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int num;
	int denom;

public:
	Fraction operator+(const Fraction& frac);
	Fraction operator-(const Fraction& frac);
	Fraction operator*(const Fraction& frac);
	Fraction operator/(const Fraction& frac);

	bool operator>(const Fraction& frac);
	bool operator<(const Fraction& frac);
	bool operator>=(const Fraction& frac);
	bool operator<=(const Fraction& frac);
	bool operator==(const Fraction& frac);
	bool operator!=(const Fraction& frac);

	Fraction& operator=(const Fraction& frac);
	Fraction& operator+=(const Fraction& frac);
	Fraction& operator*=(const Fraction& frac);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	operator float() const;
	operator int() const;

	friend istream& operator>>(istream& in, Fraction& frac);
	friend ostream& operator<<(ostream& out, const Fraction& frac);
};
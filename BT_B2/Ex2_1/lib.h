#pragma once
#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b);

class Fraction
{
private:
	int num;
	int denom;

public:
	Fraction();
	Fraction(int Num, int Denom);
	Fraction(int value);
	Fraction(string str);
	Fraction(const Fraction& frac);

	void input();
	void output();
	int getNum();
	void setNum(int newNum);
	int getDenom();
	void setDenom(int newDenom);
	Fraction reduce();
	Fraction inverse();
	Fraction add(Fraction a);
	int compare(Fraction a);

};
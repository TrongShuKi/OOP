#include <iostream>
#include <string>
#include <sstream>
#include "lib.h"
using namespace std;

Fraction::Fraction()
{
	num = 0;
	denom = 1;
}

Fraction::Fraction(int Num, int Denom)
{
	if (Denom == 0)
	{
		cout << "Error:Denom must except 0. Auto Change Denom to 1\n";
		Denom = 1;
	}
	num = Num;
	denom = Denom;
}

Fraction::Fraction(int value)
{
	num = value;
	denom = 1;
}

Fraction::Fraction(string str)
{
	stringstream ss(str);
	string strNum,strDenom;
	getline(ss, strNum, '/');
	getline(ss, strDenom);
	
	int Num, Denom;
	if (!strNum.empty() || !strDenom.empty())
	{
		Num = stoi(strNum);
		Denom = stoi(strDenom);

		if (Denom == 0)
		{
			cout << "Error:Denom must except 0. Auto Change Denom to 1\n";
			Denom = 1;
		}

		num = Num;
		denom = Denom;
	}
	else
	{
		cout << "Error Num or Denom. Call Default Fraction\n";
		Fraction();
	}
}

Fraction::Fraction(const Fraction& frac) 
{
	num = frac.num;
	denom = frac.denom;
}

void Fraction::input()
{
	cin >> num;
	cin >> denom;
}

void Fraction::output()
{
	cout << num << "/" << denom << endl;
}

int Fraction::getNum()
{
	return num;
}

void Fraction::setNum(int newNum)
{
	num = newNum;
}

int Fraction::getDenom()
{
	return denom;
}

void Fraction::setDenom(int newDenom)
{
	if (newDenom == 0)
	{
		cout << "Error:Denom must except 0. Auto Change Denom to 1\n";
		newDenom = 1;
	}
	denom = newDenom;
}

int GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
Fraction Fraction::reduce()
{
	Fraction result;

	int gcd = GCD(num, denom);
	result.num = num / gcd;
	result.denom = denom / gcd;

	return result;
}

Fraction Fraction::inverse()
{
	Fraction inv;
	if (num == 0)
	{
		cout << "Error:Cannot inverse 0\n";
		inv.num = num;
		inv.denom = denom;
	}
	else
	{
		inv.num = denom;
		inv.denom = num;
	}

	return inv;
}

Fraction Fraction::add(Fraction a)
{
	Fraction sum;
	sum.num = num * a.denom + denom * a.num;
	sum.denom = denom * a.denom;
	sum = sum.reduce();

	return sum;
}

int Fraction::compare(Fraction a)
{
	float val1 = num * a.denom;
	float val2 = a.num * denom;
	if (val1 > val2) return 1;
	else if (val1 < val2) return -1;
	else return 0;
}
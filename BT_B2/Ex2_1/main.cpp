#include <iostream>
#include <string>
#include "lib.h"
using namespace std;

int main()
{
	cout << "* Test initialize a fraction = 0 by default\n";
	cout << "f1 = "; 
	Fraction f1;
	f1.output(); 
	cout << endl;

	cout << "* Test initialize a fraction with num and denom\n";
	cout << "f2 = "; 
	Fraction f2(5, 6);
	f2.output(); 
	cout << endl;

	cout << "* Test initialize a fraction with an integer value\n";
	cout << "f3 = "; 
	Fraction f3(4);
	f3.output(); 
	cout << endl;

	cout << "* Test initialize a fraction with a string ('num/denom')\n";
	cout << "f4 = "; 
	Fraction f4("7/3");
	f4.output();
	cout << endl;

	cout << "* Test initialize a fraction from another fraction\n";
	cout << "f5 (copy f2) = "; 
	Fraction f5(f2);
	f5.output();
	cout << endl;

	cout << "* Test input and output\n";
	Fraction ps1;
	cout << "Input (num and denom): ";
	ps1.input();
	cout << "Output: ";
	ps1.output();
	cout << endl;

	cout << "* Test getNum and getDenom\n";
	cout << "Num of f2: " << f2.getNum() << endl;
	cout << "Denom of f2: " << f2.getDenom() << endl;
	cout << endl;

	cout << "* Test setNum and setDenom\n";
	cout << "Original f2: ";
	f2.output();
	int newNum, newDenom;
	cout << "Enter newNum and newDenom: ";
	cin >> newNum >> newDenom;
	f2.setNum(newNum);
	f2.setDenom(newDenom);
	cout << "f2 after setNum and setDenom: ";
	f2.output();
	cout << endl;

	cout << "* Test Reduce\n";
	Fraction ps2(4,6);
	cout << "Original ps2:";
	ps2.output();
	cout << "Reduce ps2: ";
	ps2 = ps2.reduce();
	ps2.output();
	cout << endl;

	cout << "* Test Inverse\n";
	cout << "Original ps2:";
	ps2.output();
	cout << "ps2 after inverse: ";
	ps2 = ps2.inverse();
	ps2.output();
	cout << endl;

	cout << "* Test Add\n";
	Fraction frac1(3, 4), frac2(2, 4), frac3;
	cout << "frac1 : ";
	frac1.output();
	cout << "frac2 : ";
	frac2.output();
	cout << "Result frac1 + frac2: ";
	frac3 = frac1.add(frac2);
	frac3.output();
	cout << endl;

	cout << "* Test Compare\n";
	cout << "frac1 : ";
	frac1.output();
	cout << "frac2 : ";
	frac2.output();
	cout << "Result: "<< frac1.compare(frac2);
	cout << endl;

	return 0;
}
#include <iostream>
#include "lib.h"
using namespace std;

int main() {
    Fraction a, b;
    cout << "Enter fraction a: ";
    cin >> a;
    cout << "Frac a: " << a << endl;
    cout << "Enter fraction b: ";
    cin >> b;
    cout << "Frac b: " << b << endl;

    cout << "\nArithmetic:\n";
    cout << "a= " << a << "; b= " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    cout << "\nComparation:\n";
    cout << "a= " << a << "; b= " << b << endl;
    cout << "a == b -> " << (a == b) << endl;
    cout << "a > b  -> " << (a > b) << endl;
    cout << "a < b  -> " << (a < b) << endl;
    cout << "a >= b -> " << (a >= b) << endl;
    cout << "a <= b -> " << (a <= b) << endl;

    cout << "\nAssignment::\n";
    cout << "a= " << a << "; b= " << b << endl;
    a = b;
    cout << "a = b -> " << "a= " << a << "; b= " << b << endl;
    a += b;
    cout << "a += b -> " << "a= " << a << "; b= " << b << endl;
    a *= b;
    cout << "a *= b -> " << "a= " << a << "; b= " << b << endl;

    cout << "\nIncrement & Decrement::\n";
    cout << "a= " << a << endl;
    cout << "++a = " << ++a << endl;
    cout << "a++ = " << a++ << " after a = " << a << "\n";

    cout << "\nType-cast:\n";
    cout << "a= " << a << endl;
    cout << "float(a) = " << float(a) << endl;
    cout << "int(a)   = " << int(a) << endl;

    return 0;
}
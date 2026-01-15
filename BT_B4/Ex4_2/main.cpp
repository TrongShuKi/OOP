#include <iostream>
#include "lib.h"
using namespace std;

int main() {
    Array a, b;
    cout << "Enter SIZE and Elements for a: "; cin >> a;
    cout << "Aray a: " << a << endl;
    cout << "Enter SIZE and Elements for b: "; cin >> b;
    cout << "Aray b: " << b << endl;

    cout << "\nConcatenation:\n";
    cout << "a + b = " << a + b << endl;

    cout << "\nAssignment:\n";
    b += a;
    cout << "After b += a, b = " << b << endl;
    a = b;
    cout << "After a = b, a = " << a << endl;

    cout << "\nArray indexer:\n";
    cout << "Get a[0]: " << a[0] << endl;

    cout << "\nType-case: (int*)\n";
    int* data = (int*)a;
    cout << "First element of data via (int*) cast: " << data[0] << endl;

    return 0;
}
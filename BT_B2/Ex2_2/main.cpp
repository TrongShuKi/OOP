#include <iostream>
#include "lib.h"
using namespace std;

int main()
{
    cout << "* Test default constructor with zero length\n";
    Array a1;
    cout << "a1 (default): ";
    a1.output();
    cout << "Size = " << a1.getSize() << "\n\n";

    cout << "* Test constructor with length and all elements = 0\n";
    Array a2(5);
    cout << "a2 (length=5): ";
    a2.output();
    cout << endl;

    cout << "* Test constructor from int array and length\n";
    int arr[] = { 7, 5, 4, 9, 2, 3 };
    Array a3(arr, 6);
    cout << "a3: ";
    a3.output();
    cout << endl;

    cout << "* Test copy constructor\n";
    Array a4(a3);
    cout << "a4 (copy a3): ";
    a4.output();
    cout << endl;

    cout << "* Test input() and output()\n";
    Array a5;
    a5.input();
    cout << "a5: ";
    a5.output();
    cout << endl;

    cout << "* Test getElement() and setElement()\n";
    cout << "a3: ";
    a3.output();
    cout << "Get element at index 2 of a3: " << a3.getElement(2) << endl;
    a3.setElement(2, 13);
    cout << "a3 after set a3[2] = 13: ";
    a3.output();
    cout << endl;

    cout << "* Test find()\n";
    cout << "a3: ";
    a3.output();
    cout << "Find 2 in a3 (index) = " << a3.find(2) << endl;
    cout << "Find 66 in a3 (index) = " << a3.find(66) << endl;
    cout << endl;

    cout << "* Test setSize()\n";
    cout << "Original a3 (size="<<a3.getSize()<<"):\n";
    a3.output();
    cout << "Resize a3 to 8:\n";
    a3.setSize(8);
    a3.output();
    cout << "Resize a3 to 4:\n";
    a3.setSize(4);
    a3.output();
    cout << endl;

    cout << "* Test sortArr()\n";
    cout << "Original a3: ";
    a3.output();
    a3.sortArr(ascending);
    cout << "a3 sorted ascending: ";
    a3.output();
    a3.sortArr(descending);
    cout << "a3 sorted descending: ";
    a3.output();
    cout << endl;

	return 0;
}
#include <iostream>
#include "lib.h"
using namespace std;

int main()
{
	int arr[6] = { 0,1,0,2,3,4 };
	Array a1(6, arr);
	cout << "Array a1 initial:\n";
	a1.display();
	cout << "Array a1 after set a[3]=4:\n";
	a1.setValue(3, 4);
	a1.display();
	cout << endl;

	HistogramArray a2(6, arr, 5);
	a2.computeHistogram();
	a2.display();
	cout << endl;

	cout << "After set a[3]=4 by operator[]\n";
	a2[3] = 4;
	a2.computeHistogram();
	a2.display();
	cout << endl;

	cout << "After set a[3]=1 'setValue' function (Auto recompute)\n";
	a2.setValue(3, 1);
	a2.display();
	cout << endl;

	return 0;
}
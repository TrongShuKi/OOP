#include <iostream>
using namespace std;

template <typename T>
void swapV(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
bool ascending(T a, T b)
{
	return a > b;
}

template <typename T>
bool descending(T a, T b)
{
	return a < b;
}

template <typename T>
void bubleSort(T arr[], int n,bool (*cp)(T,T))
{
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (cp(arr[j], arr[j + 1]))
				swapV(arr[j], arr[j + 1]);
		}
	}
}

template <typename T>
void printArray(T arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[5] = { 10,4,7,2,9 };
	float b[5] = { 4.2, 1.4, 3.7, 6.2, 4.5 };
	char c[5] = { 'd','b','f','a','c' };

	cout << "Mang ban dau: \n";
	printArray(a, 5);
	printArray(b, 5);
	printArray(c, 5);

	cout << "Mang sau khi sap xep tang dan: \n";
	bubleSort(a, 5, ascending);
	bubleSort(b, 5, ascending);
	bubleSort(c, 5, ascending);
	printArray(a, 5);
	printArray(b, 5);
	printArray(c, 5);

	cout << "Mang sau khi sap xep giam dan: \n";
	bubleSort(a, 5, descending);
	bubleSort(b, 5, descending);
	bubleSort(c, 5, descending);
	printArray(a, 5);
	printArray(b, 5);
	printArray(c, 5);

	return 0;
}
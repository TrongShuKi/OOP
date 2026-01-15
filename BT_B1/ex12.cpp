#include <iostream>
using namespace std;

void swapV(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool ascending(int a, int b)
{
	return a > b;
}

bool descending(int a, int b)
{
	return a < b;
}

void bubleSort(int arr[], int n,bool (*cp)(int,int))
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

void printArray(int arr[], int n)
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

	cout << "Mang ban dau: \n";
	printArray(a, 5);

	cout << "Mang sau khi sap xep tang dan: \n";
	bubleSort(a, 5, ascending);
	printArray(a, 5);

	cout << "Mang sau khi sap xep giam dan: \n";
	bubleSort(a, 5, descending);
	printArray(a, 5);

	return 0;
}
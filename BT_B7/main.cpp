#include <iostream>
#include <vector>
#include <string>
#include "lib.h"
using namespace std;

int main()
{
	Company MvT;
	engineers engin1("Trong", 24);
	managers manag1("Thinh", 8);
	managers manag2("Nhan", 6);
	engineers engin2("Kha", 16);
	MvT.addEmployees(&engin1);
	MvT.addEmployees(&manag1);
	MvT.addEmployees(&manag2);
	MvT.addEmployees(&engin2);

	cout << "----Show all info of each Employee----\n";
	MvT.displayEmployees();
	cout << endl;

	cout << "Total Salary: " << MvT.calTotalSalary() << endl;
	return 0;
}
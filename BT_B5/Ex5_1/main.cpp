#include <iostream>
#include <string>
#include "lib.h"
using namespace std;

int main()
{
	cout << "---- TEST ADDRESS ----" << endl;
	Address addrDefault;
	cout << "Default address: ";
	addrDefault.displayInfo();
	cout << endl;
	Address addrPara("Ta Quang Buu", "Tp.Ho Chi Minh", "Viet Nam");
	cout << "Parameterized address: ";
	addrPara.displayInfo();
	cout << endl << endl;

	cout << "---- TEST STUDENT ----" << endl;
	Student stuDefault;
	cout << "Default student info: ";
	stuDefault.displayInfo();
	cout << endl;
	cout << "Grade: " << stuDefault.getGrade() << endl;
	Student stuParam("Nguyen Van A", 24123456, 3.2, addrPara);
	cout << "Parameterized student info: ";
	stuParam.displayInfo();
	cout << endl;
	cout << "Grade: " << stuParam.getGrade() << endl << endl;

	cout << "---- TEST EXCHANGE STUDENT ----" << endl;
	ExchangeStudent ex2("Alice", 24120111, 3.3, "2nd Street", "Bac Kinh", "China", "China", 16);
	cout << "Ex_student with inline address: ";
	ex2.displayInfo();
	cout << endl;
	ExchangeStudent ex3("George", 24120333, 3.9, addrPara, "Spain", 12);
	cout << "Ex_student with addrPara: ";
	ex3.displayInfo();
	cout << endl;
	cout << "Update duration of George to 5 months" << endl;
	ex3.setDuration(5);
	ex3.displayInfo();
	cout << endl;

	return 0;
}
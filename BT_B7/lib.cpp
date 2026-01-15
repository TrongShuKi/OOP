#include <iostream>
#include <vector>
#include <string>
#include "lib.h"
using namespace std;

//Define class Company
float Company::calTotalSalary()
{
	float totalSalary = 0;
	for (int i = 0; i < empList.size(); i++)
	{
		totalSalary += empList[i]->getSalary();
	}
	return totalSalary;
}
void Company::addEmployees(Employee* empl)
{
	empList.push_back(empl);
}
void Company::displayEmployees()
{
	for (int i = 0; i < empList.size(); i++)
	{
		empList[i]->display();
		cout << endl;
	}
}
void Company::showAllSalary()
{
	for (int i = 0; i < empList.size(); i++)
	{
		cout << empList[i]->getSalary();
	}
}

//Define class engineers
engineers::engineers(const string& Name, int Time)
{
	name = Name;
	time = Time;
}
string engineers::describeWork()
{
	return "I'm engineer";
}
string engineers::getRole()
{
	return "engineer";
}
float engineers::getSalary()
{
	return baseSalary + time * bonusRate;
}
void engineers::display()
{
	cout << name << ": " << describeWork() << ", Role:" << getRole() << ", Salary:" << getSalary();
}

//Define class managers
managers::managers(const string& Name, int Tsize)
{
	name = Name;
	size = Tsize;
}
string managers::describeWork()
{
	return "I'm manager";
}
string managers::getRole()
{
	return "manager";
}
float managers::getSalary()
{
	return baseSalary + size * bonusRate;
}
void managers::display()
{
	cout << name << ": " << describeWork() << ", Role:" << getRole() << ", Salary:" << getSalary();
}
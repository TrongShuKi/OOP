#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class Employee
class Employee
{
protected:
	string name;
	const float baseSalary = 100, bonusRate = 0.8;

public:
	virtual string describeWork() = 0;
	virtual string getRole() = 0;
	virtual float getSalary() = 0;
	virtual void display() = 0;
};

//Class Company
class Company
{
private:
	vector<Employee*> empList;

public:
	float calTotalSalary();
	void addEmployees(Employee* empl);
	void displayEmployees();
	void showAllSalary();
};

//Class engineers
class engineers : public Employee
{
private:
	int time;

public:
	engineers(const string& Name, int Time);

	string describeWork();
	string getRole();
	float getSalary();
	void display();
};

//class managers
class managers : public Employee
{
private:
	int size;

public:
	managers(const string& Name, int Tsize);

	string describeWork();
	string getRole();
	float getSalary();
	void display();

};
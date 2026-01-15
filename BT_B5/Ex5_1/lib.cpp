#include <iostream>
#include <string>
#include "lib.h"
using namespace std;

//Class Address
Address::Address()
{
	street = city = state = "xxxx";
}

Address::Address(const Address& addr)
{
	street = addr.street;
	city = addr.city;
	state = addr.state;
}

Address::Address(string st, string ct, string sta)
{
	street = st;
	city = ct;
	state = sta;
}

void Address::displayInfo()
{
	cout << "Street:"<<street << ", City:" << city << ", State:" << state;
}

//Class Student
Student::Student() :address()
{
	name = "X";
	id = 24120000;
	gpa = 0.0;
}

Student::Student(string Name, int Id, float Gpa, string st, string ct, string sta) : address(st, ct, sta)
{
	name = Name;
	id = Id;
	gpa = Gpa;
}

Student::Student(string Name, int Id, float Gpa, const Address& addr): address(addr)
{
	name = Name;
	id = Id;
	gpa = Gpa;
}

string Student::getGrade()
{
	if (gpa >= 3.5) 
		return "A";
	else if (gpa >= 3.0) 
		return "B";
	else if (gpa >= 2.0) 
		return "C";
	else if (gpa >= 1.0) 
		return "D";
	else 
		return "F";
}
void Student::displayInfo()
{
	cout << "Name:" << name << ", ID:" << id << ", GPA:" << gpa << ", ";
	address.displayInfo();
}

//Class ExchangeStudent
ExchangeStudent::ExchangeStudent() : Student()
{
	country = "xxxx";
	duration = 0;
}

ExchangeStudent::ExchangeStudent(string Name, int Id, float Gpa, string st, string ct, string sta, string Country, int Duration)
	:Student(Name, Id, Gpa, st, ct, sta)
{
	country = Country;
	duration = Duration;
}

ExchangeStudent::ExchangeStudent(string Name, int Id, float Gpa, const Address& addr, string Country, int Duration)
	:Student(Name, Id, Gpa, addr)
{
	country = Country;
	duration = Duration;
}

void ExchangeStudent::setDuration(int Duration)
{
	duration = Duration;
}
void ExchangeStudent::displayInfo()
{
	Student::displayInfo();
	cout << ", Country: "<<country << ", Exchange_Duration:" << duration;
}

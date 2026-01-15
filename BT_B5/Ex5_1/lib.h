#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
	string street;
	string city;
	string state;

public:
	Address();
	Address(string St, string ct, string sta);
	Address(const Address& addr);

	void displayInfo();
};

class Student
{
protected:
	string name;
	int id;
	float gpa;
	Address address;

public:
	Student();
	Student(string Name, int Id, float Gpa, string st, string ct, string sta);
	Student(string Name, int Id, float Gpa, const Address& addr);

	string getGrade();
	void displayInfo();
};

class ExchangeStudent : public Student
{
private:
	string country;
	int duration;

public:
	ExchangeStudent();
	ExchangeStudent(string Name, int Id, float Gpa, string st, string ct, string sta, string Country, int Duration);
	ExchangeStudent(string Name, int Id, float Gpa, const Address& addr, string Country, int Duration);

	void setDuration(int Duration);
	void displayInfo();
};
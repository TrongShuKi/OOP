#pragma once
#include <iostream>
#include <string>
using namespace std;

class Client
{
private:
	string name;
	string id;

public:
	Client();
	Client(const Client& cl);
	Client(string Name, string ID);

	void displayInfo();
};

class Account
{
protected:
	Client client;
	int accNum;
	float balance;

public:
	Account();
	Account(const Account& acc);
	Account(const Client& cl, int acc_Num, float Balance);

	float getBalance();
	void deposit(float amount);
	void withdraw(float amount);
	void displayInfo();
};

class SavingAccount :public Account
{
private:
	float interestRate;

public:
	SavingAccount();
	SavingAccount(float rate, const Account& acc);

	void applyInterest();
	void displayInfo();
};
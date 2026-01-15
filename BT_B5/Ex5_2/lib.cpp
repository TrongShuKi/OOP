#include <iostream>
#include <string>
#include "lib.h"
using namespace std;

//Class Client
Client::Client()
{
	name = "X";
	id = "xxxx";
}

Client::Client(const Client& cl)
{
	name = cl.name;
	id = cl.id;
}

Client::Client(string Name, string ID)
{
	name = Name;
	id = ID;
}

void Client::displayInfo()
{
	cout << "Name:" << name << ", ID:" << id;
}

//Class Account
Account::Account() :client()
{
	accNum = 0;
	balance = 0;
}

Account::Account(const Account& acc) : client(acc.client)
{
	accNum = acc.accNum;
	balance = acc.balance;
}

Account::Account(const Client& cl, int acc_Num, float Balance): client(cl)
{
	accNum = acc_Num;
	balance = Balance;
}

float Account::getBalance()
{
	return balance;
}

void Account::deposit(float amount)
{
	balance += amount;
}

void Account::withdraw(float amount)
{
	balance -= amount;
}

void Account::displayInfo()
{
	client.displayInfo();
	cout << ", Account_Number:" << accNum << ", Balance:" << balance;
}

//Class SavingAccount
SavingAccount::SavingAccount() :Account()
{
	interestRate = 0;
}

SavingAccount::SavingAccount(float rate, const Account& acc) :Account(acc)
{
	interestRate = rate;
}

void SavingAccount::applyInterest()
{
	balance += balance * interestRate;
}

void SavingAccount::displayInfo()
{
	Account::displayInfo();
	cout << ", Interest_Rate:" << interestRate;
}
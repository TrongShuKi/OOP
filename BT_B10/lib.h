#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<exception>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date(int d, int m, int y);
	int day();
	int month();
	int year();

public:
	static Date now();

};

class RenameRule
{
public:
	virtual string rename(const string& filename) = 0;

};

class NormalizeCasing :public RenameRule
{
public:
	string rename(const string& filename);
};

class RemoveSpecialCharacters :public RenameRule
{
private:
	string specialChars;
public:
	RemoveSpecialCharacters(const string& specChars);
	string rename(const string& filename);
};

class AddDatePrefix :public RenameRule
{
private:
	string format;

public:
	AddDatePrefix(const string& fmt);
	string rename(const string& filename);

};

class RenameCVFileUseCase
{
private:
	vector<RenameRule*> listRule;
public:
	string rename(const string& filename);
	void addRule(RenameRule* rule);
	void readFile(const string& filename, vector<string>& ruleConfigs);
};

class RuleFactory {
public:
	static RenameRule* createRule(const string& ruleDescription);
};

// Manage exception
class MyException
{
private:
	string msg;
public:
	MyException(const string& message);
	const char* what() const noexcept;
};

class FileIOException :public MyException
{
public:
	FileIOException(const string& message) :MyException(message) {}
};

class InvalidRuleException : public MyException
{
public:
	InvalidRuleException(const string& message) :MyException(message) {}
};
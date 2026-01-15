#define _CRT_SECURE_NO_WARNINGS
#include"lib.h"

// Date
Date::Date(int d, int m, int y)
{
	_day = d;
	_month = m;
	_year = y;
}

int Date::day()
{
	return _day;
}

int Date::month()
{
	return _month;
}

int Date::year()
{
	return _year;
}

Date Date::now()
{
	time_t t = time(0);
	tm* ltm = localtime(&t);
	return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}

// NormalizeCasing
string NormalizeCasing::rename(const string& filename)
{
	string result = filename;

	bool newword = true;
	for (int i = 0; i < result.length(); i++)
	{
		char ch = result[i];
		if (isalpha(ch))
		{
			if (newword)
			{
				result[i] = toupper(ch);
				newword = false;
			}
			else
				result[i] = tolower(ch);
		}
		else
		{
			newword = true;
		}
	}

	size_t idxLastDot = filename.find_first_of(".");
	if (idxLastDot != string::npos)
		result[idxLastDot + 1] = tolower(result[idxLastDot + 1]);

	return result;
}

// RemoveSpecialCharacters
RemoveSpecialCharacters::RemoveSpecialCharacters(const string& specChars)
{
	specialChars = specChars;
}
string RemoveSpecialCharacters::rename(const string& filename)
{
	string result = "";
	size_t idxLastDot = filename.find_last_of(".");
	string namePart = (idxLastDot == string::npos) ? filename : filename.substr(0, idxLastDot);
	string extPart = (idxLastDot == string::npos) ? "" : filename.substr(idxLastDot);

	for (int i = 0; i < specialChars.length(); i++)
	{
		char c = specialChars[i];
		// change \s to ' '
		if (c == '\\' && (i + 1) < specialChars.length() && specialChars[i + 1] == 's')
		{
			c = ' '; 
			i++; 
		}

		namePart.erase(remove(namePart.begin(), namePart.end(), c), namePart.end());
	}

	result = namePart + extPart;
	return result;
}

// AddDatePrefix
AddDatePrefix::AddDatePrefix(const string& fmt)
{
	this->format = fmt;
}
string AddDatePrefix::rename(const string& filename)
{
	Date nowDate = Date::now();
	string dateStr = to_string(nowDate.year());
	if (nowDate.month() < 10) dateStr += "0";
	dateStr += to_string(nowDate.month());
	if (nowDate.day() < 10) dateStr += "0";
	dateStr += to_string(nowDate.day());

	string prefix = this->format;

	string placeholder = "yyyymmdd";
	size_t pos = prefix.find(placeholder);

	if (pos != string::npos)
	{
		prefix.replace(pos, placeholder.length(), dateStr);
	}

	return prefix + filename;
}

// RenameCVFileUseCase
void RenameCVFileUseCase::addRule(RenameRule* rule)
{
	if (rule != nullptr)
		listRule.push_back(rule);
}
string RenameCVFileUseCase::rename(const string& filename) {
	string currentName = filename;
	for (int i = 0;i<listRule.size();i++) 
	{
		currentName = listRule[i]->rename(currentName);
	}
	return currentName;
}
void RenameCVFileUseCase::readFile(const string& filename, vector<string>& ruleConfigs)
{
	ifstream iF(filename);
	if (!iF)
	{
		throw FileIOException("Error: Could not open rules file: " + filename);
	}
	else
	{
		string line;
		while (getline(iF, line))
		{
			if (line.empty())
				continue;
			ruleConfigs.push_back(line);
		}
	}
}

// RuleFactory
RenameRule* RuleFactory::createRule(const string& line)
{

	if (line.find("NormalizeCasing") != string::npos) 
	{
		return new NormalizeCasing();
	}
	if (line.find("RemoveSpecialCharacters") != string::npos) 
	{
		size_t start = line.find('[');
		size_t end = line.find(']');

		if (start == string::npos || end == string::npos || end <= start)
		{
			throw InvalidRuleException("Invalid format for RemoveSpecialCharacters (missing brackets): " + line);
		}

		string regex = line.substr(start + 1, end - start - 1);

		RemoveSpecialCharacters* removeSpecialChars = new RemoveSpecialCharacters(regex);

		return removeSpecialChars;
	}
	if (line.find("AddDatePrefix") != string::npos) 
	{
		string fmt = "yyyymmdd_";//default
		string key = "Format=";
		size_t pos = line.find(key);

		if (pos != string::npos)
		{
			fmt = line.substr(pos + key.length());
		}

		return new AddDatePrefix(fmt);
	}

	throw InvalidRuleException("Unknown rule configuration: " + line);
}

// MyException
MyException::MyException(const string& message)
{
	msg = message;
}
const char* MyException::what() const noexcept
{
	return msg.c_str();
}
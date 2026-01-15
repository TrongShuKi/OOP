#include<iostream>
#include<vector>
#include<string>
#include"lib.h"
using namespace std;

int main()
{	
	vector<string> filenames = {
		"Nguyen Van Minh.pDF",
		"Tran_Thi_Lan.DOCX",
		"LE-HOANG_ANH.Pdf",
		"PhAm DUc HUy.Docx"
	};

	RenameCVFileUseCase useCase;
	vector<string> ruleConfigs;

	try
	{
		useCase.readFile("rules.txt", ruleConfigs);

		for (int i = 0; i < ruleConfigs.size(); i++)
		{
			RenameRule* rule = RuleFactory::createRule(ruleConfigs[i]);
			if (rule != nullptr)
			{
				useCase.addRule(rule);
			}
		}
	}
	catch (const FileIOException& e)
	{
		cout << "--FILE ERROR--" << e.what() << endl;
	}
	catch (const InvalidRuleException& e)
	{
		cout << "--INVALID RULE--" << e.what() << endl;
		cout << "Please check syntax in file rule." << endl;
	}
	catch (const exception& e) 
	{
		cerr << "--SYSTEM ERROR--" << e.what() << endl;
	}

	cout << "Renameing files...\n";
	for (const auto& origin : filenames)
	{
		auto renamed = useCase.rename(origin);
		cout << origin << "->" << renamed << "\n";
	}

	return 0;
}
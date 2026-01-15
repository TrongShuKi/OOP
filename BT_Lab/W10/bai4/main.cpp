#include<iostream>
#include"lib.h"
using namespace std;

int main()
{
	CFolder C("C");
	CFolder System("System");
	CFolder Windows("Windows");
	CFile a_txt("a.txt", 123);
	CFile b_doc("b.doc", 456);
	System.Add(&a_txt);
	Windows.Add(&b_doc);
	C.Add(&System);
	C.Add(&Windows);
	cout << "Content of folder C ->" << endl;
	bool isPrintHiddenItems = false;
	C.Print(isPrintHiddenItems);
	CItem* p = C.RemoveByName("System");
	cout << "Content of folder C after removing folder System ->" << endl;
	C.Print(false);
	p = C.FindByName("b.doc");
	if (p != NULL) {
		cout << "b.doc is found in folder C" << endl;
	}
	else {
		cout << "b.doc is not found" << endl;
	}
	p = C.FindByName("a.txt");
	if (p != NULL) {
		cout << "a.txt is found" << endl;
	}
	else {
		cout << "a.txt is not found" << endl;
	}
	p = C.FindByName("Windows");
	bool isHidden;
	bool isAlsoApplyToChildrent;
	if (p != NULL) {
		cout << "Folder Windows is folder. Content of folder Windows ->" << endl;
		// set Hidden to folder p and do not change hidden attributes of sub-items
		isHidden = true; isAlsoApplyToChildrent = false;
		p->SetHidden(isHidden, isAlsoApplyToChildrent);
		p->Print(false);
		// set Hidden to folder p and all its items
		isHidden = true; isAlsoApplyToChildrent = true;
		p->SetHidden(isHidden, isAlsoApplyToChildrent);
		p->Print(false);
	}
	else {
		cout << "Folder Windows is not found" << endl;
	}
	return 0;
}

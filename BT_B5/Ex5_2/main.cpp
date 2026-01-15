#include <iostream>
#include <string>
#include "lib.h"
using namespace std;

int main()
{
    cout << "---- TEST CLIENT ----" << endl;
    Client clientDefault;
    cout << "Default Client: ";
    clientDefault.displayInfo();
    cout << endl;
    Client client1("Nguyen Van A", "A00111");
    cout << "Client 1 (Parameterized): ";
    client1.displayInfo();
    cout << endl << endl;


    cout << "---- TEST ACCOUNT ----" << endl;
    Account acc1(client1, 100111222, 50000);   
    cout << "Account 1 (belongs to Client 1): ";
    acc1.displayInfo();
    cout << endl;
    acc1.deposit(30000);        
    cout << "Account 1 after depositing 30000: ";
    acc1.displayInfo();
    cout << endl;
    acc1.withdraw(15000);       
    cout << "Account 1 after withdrawing 15000: ";
    acc1.displayInfo();
    cout << endl << endl;


    cout << "---- TEST SAVING ACCOUNT ----" << endl;
    SavingAccount savAcc1(0.08, acc1); 
    cout << "Saving_Account (from account 1): ";
    savAcc1.displayInfo();
    cout << endl;
    cout << "Applying interest Rate (8%): ";
    savAcc1.applyInterest();
    savAcc1.displayInfo();
    cout << endl << endl;

	return 0;
}
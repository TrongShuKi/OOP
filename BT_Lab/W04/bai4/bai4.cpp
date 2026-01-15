#include <iostream>
#include <ctime>
#include "LinkedList.h"
#include "CString.h"
using namespace std;


int main()
{

    srand((unsigned int)time(NULL));
    const int maxV = 1000, iTest = 2;
    int n = 5 + rand() % 10;
    LinkedList<int> ll;
    for (int i = 0; i < n; i++)
    {
        if (rand() % 2 == 0)
        {
            int val = rand() % maxV;
            ll.AddHead(val);
        }
        else
        {
            int val = rand() % maxV + maxV;
            ll.AddTail(val);
        }
    }
    
    cout << ll << endl;
    ll[iTest] = -123;
    ll[iTest + 2] = 9876;
    ll.RemoveHead();
    ll.RemoveTail();
    cout << "Sau thay doi:" << endl;
    cout << ll << endl;

    LinkedList<CString> llCS;
    llCS.AddTail(CString("cstring-1"));
    llCS.AddTail(CString("cstring-2"));
    llCS.AddTail(CString("cstring-3"));
    cout << "List CString: " << llCS << endl;
    llCS[iTest] = CString("new CString");
    cout << "List CString changed: " << endl << llCS << endl;
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int& t);
    SoPhuc(const int& t, const int& a);
    SoPhuc operator+(const SoPhuc& sp);

    friend SoPhuc operator+(const int& n, const SoPhuc& sp);
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
};

SoPhuc::SoPhuc()
{
    _thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int& t) : SoPhuc()
{
    _thuc = t;
}

SoPhuc::SoPhuc(const int& t, const int& a)
{
    _thuc = t;
    _ao = a;
}

SoPhuc SoPhuc::operator+(const SoPhuc& sp)
{
    SoPhuc rt = *this;
    rt._thuc += sp._thuc;
    rt._ao += sp._ao;
    return rt;
}

SoPhuc operator+(const int& n, const SoPhuc& sp)
{
    SoPhuc spR(n);
    spR._thuc += sp._thuc;
    spR._ao += sp._ao;
    return spR;
}

ostream& operator<<(ostream& os, const SoPhuc& sp)
{
    os << sp._thuc;
    if (sp._ao != 0)
        os << ((sp._ao > 0) ? " + " : " - ") << sp._ao << "*i";
    return os;
}

int main()
{
    SoPhuc sp1(3, 5);
    SoPhuc sp2 = 10 + sp1;
    cout << sp1 << endl;
    cout << sp2 << endl;
    system("pause");
    return 0;
}

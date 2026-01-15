#include <iostream>
#include "SLList.h"
#include <cstring>
using namespace std;

class SoNguyenLon
{
private:
	SLList<unsigned char> lCS;
	void Pow10(const int& n);

public:
	SoNguyenLon(void);
	SoNguyenLon(const int& cs, const int& scs);
	SoNguyenLon(const unsigned long& n);
	SoNguyenLon(const SoNguyenLon& snl);
	SoNguyenLon(const char* s);
    ~SoNguyenLon(void) {};

	int SoCS();
	SoNguyenLon operator+(SoNguyenLon snl);
	SoNguyenLon operator-(SoNguyenLon snl);
	SoNguyenLon operator*(SoNguyenLon snl);
	bool operator>(SoNguyenLon& snl);
	const SoNguyenLon& operator=(const SoNguyenLon& snl);
	SoNguyenLon& operator+=(SoNguyenLon snl);
	friend SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl);
	friend SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl);
	friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);

};

void SoNguyenLon::Pow10(const int& n)
{
    for (int i = 0; i < n; ++i)
    {
        lCS.insert(lCS.begin(), 0);
    }
}

//Constructor
SoNguyenLon::SoNguyenLon(void)
{
    lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs)
{
    int cSR = cs;
    if (cSR < 1)
    {
        cSR = 1;
    }
    if (cSR > 9)
    {
        cSR = 9;
    }

    int soCS = abs(scs);
    if (soCS < 1)
    {
        soCS = 1;
    }

    for (int i = 0; i < soCS; ++i)
    {
        lCS.push_back(cSR);
    }
}

SoNguyenLon::SoNguyenLon(const unsigned long& n)
{
    unsigned long temp = n;
    while (temp > 0)
    {
        lCS.push_back(temp % 10);
        temp /= 10;
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snL)
{
    lCS = snL.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            unsigned char value = s[i] - '0';
            lCS.push_back(value);
        }
        else
            throw invalid_argument("Invalid character in input string");
    }
}

int SoNguyenLon::SoCS()
{
    return lCS.size();
}

//operator
SoNguyenLon SoNguyenLon::operator+ (SoNguyenLon snl)
{
    SoNguyenLon snlMax= (this->lCS.size() > snl.lCS.size()) ? *this : snl;
    SoNguyenLon snlMin= (this->lCS.size() > snl.lCS.size()) ? snl : *this;
    int lenMax = snlMax.lCS.size();
    int lenMin = snlMin.lCS.size();
    SoNguyenLon kq;
    kq.lCS.clear();
    int remember = 0;
    for (int i = 0; i < lenMax; i++)
    {
        int value;
        if (i < lenMin)
            value = snlMax.lCS[i] + snlMin.lCS[i] + remember;
        else
            value = snlMax.lCS[i] + remember;

        if (value > 9)
            remember = 1;
        else
            remember = 0;

        kq.lCS.push_back(value % 10);
    }
    if (remember)
        kq.lCS.push_back(remember);

    return kq;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl)
{
    if (snl > *this)
        return SoNguyenLon("0");

    SoNguyenLon snlMax = *this;
    SoNguyenLon snlMin = snl;
    int lenMax = snlMax.lCS.size();
    int lenMin = snlMin.lCS.size();

    SoNguyenLon kq;
    kq.lCS.clear();
    int borrow = 0;
    for (int i = 0; i < lenMax; i++)
    {
        int value;
        if (i < lenMin)
            value = snlMax.lCS[i] - snlMin.lCS[i] - borrow;
        else
            value = snlMax.lCS[i] - borrow;

        if (value < 0)
        {
            value += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        kq.lCS.push_back(value);
    }
    int cnt = kq.lCS.size() - 1;
    while (cnt > 0 && kq.lCS[cnt] == 0)
    {
        kq.lCS.pop_back();
        cnt--;
    }

    return kq;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl)
{
    SoNguyenLon snLkQ, * psnlTemp;
    SoNguyenLon* snLSCMax = (SoCS() > snl.SoCS()) ? this : &snl;
    SoNguyenLon* snLSCMin = (SoCS() < snl.SoCS()) ? this : &snl;

    int nho = 0, temp;
    for (int t = 0; t < snLSCMin->SoCS(); ++t)
    {
        psnlTemp = new SoNguyenLon;
        psnlTemp->lCS.clear();
        nho = 0;

        for (int j = 0; j < snLSCMax->SoCS(); ++j)
        {
            temp = snLSCMin->lCS[t] * snLSCMax->lCS[j] + nho;
            psnlTemp->lCS.push_back(temp % 10);
            nho = temp / 10;
        }

        if (nho > 0)
            psnlTemp->lCS.push_back(nho);

        psnlTemp->Pow10(t);
        snLkQ += *psnlTemp;
        delete psnlTemp;
    }
    return snLkQ;
}

bool SoNguyenLon::operator>(SoNguyenLon& snl)
{
    if (lCS.size() > snl.lCS.size())
        return true;
    if (lCS.size() < snl.lCS.size())
        return false;

    //lCS.size==snl.lCS.size()
    for (int i = lCS.size() - 1; i >= 0; --i)
    {
        if (lCS[i] == snl.lCS[i])
            continue;
        if (lCS[i] > snl.lCS[i])
            return true;
        return false;
    }
    return false;
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
    lCS = snl.lCS;
    return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl)
{
    SoNguyenLon snlA(*this);
    *this = snlA + snl;
    return *this;
}

//friend
SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
    SoNguyenLon snlA(n);
    return snlA + snl;
}

SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
    SoNguyenLon snlA(n);
    return snlA - snl;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
    for (int i = snl.lCS.size() - 1; i >= 0; --i)
        os << (int)snl.lCS[i];
    return os;
}

//main
int main()
{
    const int iTest = 78912;
    SoNguyenLon snl1(123);
    SoNguyenLon snl2(40000);
    cout << snl1 << " + " << snl2 << " = ";
    cout << (snl1 + snl2) << endl;

    cout << snl1 << " * " << snl2 << " = ";
    cout << (snl1 * snl2) << endl;

    cout << snl1 << " - " << snl2 << " = ";
    cout << (snl1 - snl2) << endl;

    cout << snl2 << " - " << snl1 << " = ";
    cout << (snl2 - snl1) << endl;

    cout << iTest << " - " << snl2 << " = ";
    cout << (iTest - snl2) << endl;

    system("pause");
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

class SoNguyenLon
{
private:
    int length;
    int* data;

    static int maxLength;
    static SoNguyenLon* snlMax;
    
    static int compareSNL(const SoNguyenLon& a, const SoNguyenLon& b);

public:
    SoNguyenLon();
    SoNguyenLon(const int& hso);
    SoNguyenLon(const char* str);
    SoNguyenLon(const int& num, const int& len);
    SoNguyenLon(const SoNguyenLon& snl);
    ~SoNguyenLon();

    SoNguyenLon Tru(const SoNguyenLon& snl);
    SoNguyenLon Cong(const int& hso);   //Cong voi hang so
    static SoNguyenLon HieuVoiHangSo(const int& hso,const SoNguyenLon& snl); //Hieu voi hang so
    static SoNguyenLon SNLMax();
    void In(ostream& os);
    SoNguyenLon chuanhoaLength(const int& newLen);

};

int SoNguyenLon::compareSNL(const SoNguyenLon& a, const SoNguyenLon& b)
{
    if (a.length > b.length)
        return 1;
    else if (a.length < b.length)
        return -1;
    else //a.length=b.length
    {
        for (int i = 0; i < a.length; i++)
        {
            if (a.data[i] > b.data[i])
                return 1;
            else if (a.data[i] < b.data[i])
                return -1;
            else
                continue;
        }
    }
    return 0;
}

SoNguyenLon::SoNguyenLon()
{
    length = 1;
    data = new int[1];
    data[0] = 0;

    if (snlMax == nullptr || compareSNL(*this, *snlMax) == 1)
    {
        delete snlMax;                  
        snlMax = new SoNguyenLon(*this); 
    }
}

SoNguyenLon::SoNguyenLon(const int& hso)
{
    if (hso == 0)
    {
        length = 1;
        data = new int[1];
        data[0] = 0;
    }
    else
    {
        int cntlen = 0;
        int temp = hso;
        while (temp > 0)
        {
            temp /= 10;
            cntlen++;
        }
        length = (cntlen < maxLength) ? cntlen : maxLength;
        data = new int[length];
        temp = hso;
        for (int i = length - 1; i >= 0; i--)
        {
            data[i] = temp % 10;
            temp /= 10;
        }
    }

    if (snlMax == nullptr || compareSNL(*this, *snlMax) == 1)
    {
        delete snlMax;
        snlMax = new SoNguyenLon(*this);
    }
}

SoNguyenLon::SoNguyenLon(const char* str)
{
    length = (int(strlen(str)) < maxLength) ? strlen(str) : maxLength;
    data = new int[length];
    for (int i = 0; i < length; i++)
        data[i] = str[i] - '0'; //change character to number

    if (snlMax == nullptr || compareSNL(*this, *snlMax) == 1)
    {
        delete snlMax;
        snlMax = new SoNguyenLon(*this);
    }
}

SoNguyenLon::SoNguyenLon(const int& num, const int& len)
{
    length = (len < maxLength) ? len : maxLength;
    data = new int[length];
    for (int i = 0; i < length; i++)
    {
        data[i] = num;
    }

    if (snlMax == nullptr || compareSNL(*this, *snlMax) == 1)
    {
        delete snlMax;
        snlMax = new SoNguyenLon(*this);
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl)
{
    length = snl.length;
    data = new int[length];
    for (int i = 0; i < length; i++)
    {
        data[i] = snl.data[i];
    }
}

SoNguyenLon::~SoNguyenLon()
{
    delete[] data;
}

SoNguyenLon SoNguyenLon::chuanhoaLength(const int& newLen)
{
    if (newLen <= length)
        return SoNguyenLon(*this);

    SoNguyenLon ch;
    ch.length = (newLen < maxLength) ? newLen : maxLength;
    ch.data = new int[ch.length];

    int diff = newLen - length;
    for (int i = 0; i < diff; i++)
        ch.data[i] = 0;

    for (int i = diff; i < newLen; i++)
        ch.data[i] = data[i - diff];

    return ch;
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon& snl)
{
    SoNguyenLon snlA(*this);
    SoNguyenLon TsnlB(snl);

    // this<=snl
    if (compareSNL(snlA, TsnlB) == -1 || compareSNL(snlA, TsnlB) == 0)
    {
        SoNguyenLon zero(0);
        return zero;
    }

    // this>snl
    SoNguyenLon snlB = (snlA.length > TsnlB.length) ? TsnlB.chuanhoaLength(snlA.length) : TsnlB;

    //Minus 2 snl have same length
    SoNguyenLon kq;
    kq.length = length;
    kq.data = new int[kq.length];

    int borrow = 0;
    for (int i = kq.length - 1; i >= 0; i--)
    {
        int val = data[i] - (snlB.data[i] + borrow);
        if (val < 0)
        {
            val += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        kq.data[i] = val;
    }

    //count blank
    int cntBlank = 0;
    while (cntBlank < (kq.length - 1) && kq.data[cntBlank] == 0)
        cntBlank++;

    //remove blank
    SoNguyenLon result;
    result.length = kq.length - cntBlank;
    result.data = new int[result.length];
    for (int i = 0; i < result.length; i++)
        result.data[i] = kq.data[cntBlank + i];

    return result;
}

SoNguyenLon SoNguyenLon::Cong(const int& hso)
{
    SoNguyenLon TsnlA(*this);
    SoNguyenLon TsnlB(hso);

    int newlen = (TsnlA.length > TsnlB.length) ? TsnlA.length : TsnlB.length;
    SoNguyenLon snlA = (TsnlA.length != TsnlB.length) ? TsnlA.chuanhoaLength(newlen) : TsnlA;
    SoNguyenLon snlB = (TsnlA.length != TsnlB.length) ? TsnlB.chuanhoaLength(newlen) : TsnlB;

    //Add 2 snl have same length
    SoNguyenLon kq;
    kq.length = newlen;
    kq.data = new int[kq.length];

    int remember = 0;
    for (int i = kq.length - 1; i >= 0; i--)
    {
        int val = snlA.data[i] + snlB.data[i] + remember;
        if (val >  9)
        {
            val %= 10;
            remember = 1;
        }
        else
            remember = 0;
        kq.data[i] = val;
    }
    SoNguyenLon res;
    if (remember != 0)
    {
        res.length = kq.length + 1;
        res.data = new int[res.length];
        res.data[0] = remember;
        for (int i = 1; i < res.length; i++)
            res.data[i] = kq.data[i - 1];
        return res;
    }
    else
        return kq;
}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(const int& hso, const SoNguyenLon& snl)
{
    SoNguyenLon snlA(hso);
    SoNguyenLon TsnlB(snl);

    // this<=snl
    if (compareSNL(snlA, TsnlB) == -1 || compareSNL(snlA, TsnlB) == 0)
    {
        SoNguyenLon zero(0);
        return zero;
    }

    // this>snl
    SoNguyenLon snlB = (snlA.length > TsnlB.length) ? TsnlB.chuanhoaLength(snlA.length) : TsnlB;

    //Minus 2 snl have same length
    SoNguyenLon kq;
    kq.length = snlA.length;
    kq.data = new int[kq.length];

    int borrow = 0;
    for (int i = kq.length - 1; i >= 0; i--)
    {
        int val = snlA.data[i] - (snlB.data[i] + borrow);
        if (val < 0)
        {
            val += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        kq.data[i] = val;
    }

    //count blank
    int cntBlank = 0;
    while (cntBlank < (kq.length - 1) && kq.data[cntBlank] == 0)
        cntBlank++;

    //remove blank
    SoNguyenLon result;
    result.length = kq.length - cntBlank;
    result.data = new int[result.length];
    for (int i = 0; i < result.length; i++)
        result.data[i] = kq.data[cntBlank + i];

    return result;
}

SoNguyenLon SoNguyenLon::SNLMax()
{
    if (snlMax == nullptr) 
        return SoNguyenLon(0);
    return *snlMax;
}

void SoNguyenLon::In(ostream& os)
{
    for (int i = 0; i < length; i++)
        os << data[i];
}

int SoNguyenLon::maxLength = 100;
SoNguyenLon* SoNguyenLon::snlMax=nullptr;

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2("1234567");
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3.Tru(snl2);
    SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
    SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);
    snl1.In(cout);
    cout << endl;
    snl2.In(cout);
    cout << endl;
    snl3.In(cout);
    cout << endl;
    snl4.In(cout);
    cout << endl;
    snl5.In(cout);
    cout << endl;
    snl6.In(cout);
    cout << endl;
    snl7.In(cout);
    cout << endl;

    cout << "SoNguyenLon Max:" << endl;
    SoNguyenLon::SNLMax().In(cout);
    cout << endl;
    system("pause");
    return 0;
}

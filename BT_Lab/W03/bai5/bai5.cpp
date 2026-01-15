#include <iostream>
using namespace std;

class SoNguyenLon
{
private:
    int length;
    int* data;

    static int maxLength;
    static SoNguyenLon snlMax;

public:
    SoNguyenLon();
    SoNguyenLon(const SoNguyenLon& snl);
    ~SoNguyenLon();
    SoNguyenLon(const int& hso);
    SoNguyenLon(const int& num, const int& len);

    bool operator>(const SoNguyenLon& snl);
    bool operator<(const SoNguyenLon& snl);
    bool operator<=(const SoNguyenLon& snl);
    bool operator>=(const SoNguyenLon& snl);
    bool operator==(const SoNguyenLon& snl);

    SoNguyenLon& operator=(const SoNguyenLon& snl);
    SoNguyenLon operator-(const SoNguyenLon& snl);
    SoNguyenLon operator+(const SoNguyenLon& snl);
    SoNguyenLon operator+(const int& hso); 

    friend SoNguyenLon operator-(const int& hso, const SoNguyenLon& snl);
    friend ostream& operator<<(ostream& os,const SoNguyenLon& snl);

    static SoNguyenLon SNLMax();
    SoNguyenLon chuanhoaLength(const int& newLen);

};

SoNguyenLon::SoNguyenLon()
{
    length = 1;
    data = new int[1];
    data[0] = 0;

    if (*this > snlMax)
        snlMax = *this;
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

    if (*this > snlMax)
        snlMax = *this;
}

SoNguyenLon::SoNguyenLon(const int& num, const int& len)
{
    length = (len < maxLength) ? len : maxLength;
    data = new int[length];
    for (int i = 0; i < length; i++)
    {
        data[i] = num;
    }

    if (*this > snlMax)
        snlMax = *this;
}

bool SoNguyenLon::operator>(const SoNguyenLon& snl)
{
    if (length > snl.length)
        return true;
    if (length < snl.length)
        return false;
    for (int i = 0; i < length; i++)
    {
        if (data[i] > snl.data[i])
            return true;
        if (data[i] < snl.data[i])
            return false;
    }
    return false;
}

bool SoNguyenLon::operator<(const SoNguyenLon& snl)
{
    SoNguyenLon temp = snl;
    return (temp > *this);
}

bool SoNguyenLon::operator<=(const SoNguyenLon& snl)
{
    return !(*this > snl);
}

bool SoNguyenLon::operator>=(const SoNguyenLon& snl)
{
    return !(*this < snl);
}

bool SoNguyenLon::operator==(const SoNguyenLon& snl)
{
    return (!(*this < snl) && !(*this > snl));
}

SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
    if (data != snl.data)
    {
        length = snl.length;
        delete[] data;
        data = new int[length];
        for (int i = 0; i < length; i++)
            data[i] = snl.data[i];
    }
    return *this;
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

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl)
{
    SoNguyenLon snlA(*this);
    SoNguyenLon TsnlB(snl);

    // this<=snl
    if (snlA <= TsnlB)
        return 0;

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

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
    SoNguyenLon TsnlA(*this);
    SoNguyenLon TsnlB(snl);

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
        if (val > 9)
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

SoNguyenLon SoNguyenLon::operator+(const int& hso)
{
    SoNguyenLon snlB(hso);
    return (*this + snlB);
}

SoNguyenLon operator-(const int& hso, const SoNguyenLon& snl)
{
    SoNguyenLon snlA(hso);
    return (snlA - snl);
}

SoNguyenLon SoNguyenLon::SNLMax()
{
    return snlMax;
}

ostream& operator<<(ostream& os,const SoNguyenLon& snl)
{
    for (int i = 0; i < snl.length; i++)
        os << snl.data[i];
    return os;
}

int SoNguyenLon::maxLength = 100;
SoNguyenLon SoNguyenLon::snlMax = 0;

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(1234567);
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 45678910 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
   
    cout << snl1 << endl << snl2 << endl << snl3 << endl;
    cout << snl4 << endl << snl5 << endl << snl6 << endl;
    cout << snl7 << endl;

    cout << "SoNguyenLon Max:" << endl;
    cout << SoNguyenLon::SNLMax() << endl;
    cout << endl;
    system("pause");
    return 0;
}

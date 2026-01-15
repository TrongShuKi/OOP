#include <iostream>
#include "LinkedList.h"
#include "SoNguyenLon.h"
using namespace std;

//constructor
SoNguyenLon::SoNguyenLon() :data()
{
    length = 1;
    data.AddTail(0);
}

SoNguyenLon::SoNguyenLon(const int& hso) :data()
{
    if (hso == 0)
    {
        length = 1;
        data.AddTail(0);
    }
    else
    {
        int temp = hso;
        length = 0;
        while (temp != 0)
        {
            data.AddHead(temp % 10);
            length++;
            temp /= 10;
        }
    }
}

SoNguyenLon::SoNguyenLon(const int& num, const int& len) :data()
{
    length = 0;
    for (int i = 0; i < len; i++)
    {
        data.AddTail(num);
        length++;
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) :data()
{
    length = 0;
    for (int i = 0; i < snl.length; i++)
    {
        data.AddTail(snl.data[i]);
        length++;
    }
}

//assigment
SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
    if (this != &snl)
    {
        data.clear();
        length = 0;
        for (int i = 0; i < snl.length; i++)
        {
            data.AddTail(snl.data[i]);
            length++;
        }
    }
    return *this;
}

//operator
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

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl)
{
    SoNguyenLon snlA(*this);
    SoNguyenLon snlB(snl);
    // this<=snl
    if (snlA <= snlB)
        return 0;

    // this>snl
    snlB = (snlA.length > snlB.length) ? snlB.chuanhoaLength(snlA.length) : snlB;

    //Minus 2 snl have same length
    SoNguyenLon kq;
    kq.data.clear();
    int borrow = 0;
    for (int i = snlA.length - 1; i >= 0; i--)
    {
        int val = snlA.data[i] - (snlB.data[i] + borrow);
        if (val < 0)
        {
            val += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        kq.data.AddHead(val);
    }

    //count blank
    kq.length = kq.data.getSize();
    int cntBlank = 0;
    while (cntBlank < (kq.length - 1) && kq.data[cntBlank] == 0)
        cntBlank++;

    //remove blank
    for (int i = 0; i < cntBlank; i++)
        kq.data.RemoveHead();

    kq.length = kq.data.getSize();
    return kq;
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
    SoNguyenLon snlA = *this;
    SoNguyenLon snlB = snl;
    if (snlA == 0) return snlB;
    if (snlB == 0) return snlA;

    if (snlA.length != snlB.length)
    {
        int newlen = (snlA.length > snlB.length) ? snlA.length : snlB.length;
        snlA = (snlA.length < newlen) ? snlA.chuanhoaLength(newlen) : snlA;
        snlB = (snlB.length < newlen) ? snlB.chuanhoaLength(newlen) : snlB;
    }

    //Add 2 snl have same length
    SoNguyenLon kq;
    kq.data.clear();
    int remember = 0;
    for (int i = snlA.length - 1; i >= 0; i--)
    {
        int val = snlA.data[i] + snlB.data[i] + remember;
        if (val > 9)
        {
            val %= 10;
            remember = 1;
        }
        else
            remember = 0;
        kq.data.AddHead(val);
    }
    if (remember != 0)
        kq.data.AddHead(remember);

    kq.length = kq.data.getSize();
    return kq;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon& snl)
{
    SoNguyenLon snlA(*this);
    SoNguyenLon snlB(snl);

    //multiply 
    SoNguyenLon result;
    for (int i = snlB.length - 1; i >= 0; i--)
    {
        SoNguyenLon kq;
        kq.data.clear();
        int remember = 0;
        for (int j = snlA.length - 1; j >= 0; j--)
        {
            int value = snlB.data[i] * snlA.data[j] + remember;
            kq.data.AddHead(value % 10);
            remember= value / 10;
        }
        if (remember != 0)
            kq.data.AddHead(remember);

        for (int k = 0; k < snlB.length - 1 - i; k++)
            kq.data.AddTail(0);

        kq.length = kq.data.getSize();
        result = result + kq;
    }
    result.length = result.data.getSize();
    return result;
}

//other
SoNguyenLon SoNguyenLon::chuanhoaLength(const int& newLen)
{
    SoNguyenLon ch=*this;
    if (newLen >= length)
    {
        for (int i = length; i < newLen; i++)
            ch.data.AddHead(0);
    }
    ch.length = ch.data.getSize();
    return ch;
}

const SoNguyenLon SoNguyenLon::chuanhoaLength(const int& newLen) const
{
    SoNguyenLon ch = *this;
    if (newLen >= length)
    {
        for (int i = length; i < newLen; i++)
            ch.data.AddHead(0);
    }
    ch.length = ch.data.getSize();
    return ch;
}

SoNguyenLon operator-(const int& hso, const SoNguyenLon& snl)
{
    SoNguyenLon snlA(hso);
    return (snlA - snl);
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
    for (int i = 0; i < snl.length; i++)
        os << snl.data[i];
    return os;
}
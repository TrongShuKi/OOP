#include <iostream>
#include <cstring>

using namespace std;

class NgayThang
{
private:
    int Day;
    int Month;
    int Year;
    bool is_NamNhuan(const int& year);

public:
    NgayThang();
    NgayThang(const int& day, const int& month, const int& year);
    ~NgayThang();

    void Chuanhoa();
    void Xuat();
};

class SinhVien
{
private:
    char* MSSV;
    char* HoTen;
    NgayThang NgaySinh;
    float DLT;
    float DTH;

public:
    SinhVien();
    SinhVien(const char* mssv);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const int& dd, const int& mm, const int& yyyy);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const NgayThang& ngaysinh);
    SinhVien(const SinhVien& sv);
    ~SinhVien();

    void Xuat();
};

NgayThang::NgayThang()
{
    Day = Month = Year = 0;
}

NgayThang::NgayThang(const int& day, const int& month, const int& year)
{
    Day = day;
    Month = month;
    Year = year;
    Chuanhoa();
}

bool NgayThang::is_NamNhuan(const int& year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
void NgayThang::Chuanhoa()
{
    //Chuan hoa so am
    Day = abs(Day);
    Month = abs(Month);
    Year = abs(Year);

    //Chuan hoa day,month exactly
    bool flag = true;
    while (flag == true)
    {
        flag = false;

        int dayInMonth = 0;
        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
            dayInMonth = 31;
        if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
            dayInMonth = 30;
        if (Month == 2)
        {
            if (is_NamNhuan(Year))
                dayInMonth = 29;
            else
                dayInMonth = 28;
        }

        int monthDu;
        if (Day > dayInMonth && dayInMonth != 0)
        {
            monthDu = (Day - 1) / dayInMonth;
            Day = (Day - 1) % dayInMonth + 1;
            Month += monthDu;
            flag = true;
        }

        int yearDu;
        if (Month > 12)
        {
            yearDu = (Month - 1) / 12;
            Month = (Month - 1) % 12 + 1;
            Year += yearDu;
            flag = true;
        }
    }
}

NgayThang::~NgayThang()
{

}

void NgayThang::Xuat()
{
    printf("%02d/%02d/%04d", Day, Month, Year);
}


SinhVien::SinhVien()
{
    MSSV = new char[9];
    strcpy_s(MSSV, 9 , "xxxxxxxx");

    HoTen = new char[5];
    strcpy_s(HoTen, 5 , "xxxx");

    DLT = 0;
    DTH = 0;
}

SinhVien::SinhVien(const char* mssv)
{
    MSSV = new char[strlen(mssv) + 1];
    strcpy_s(MSSV, strlen(mssv) + 1, mssv);

    HoTen = new char[5];
    strcpy_s(HoTen, 5 , "xxxx");

    DLT = 0;
    DTH = 0;
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth)
{
    MSSV = new char[strlen(mssv) + 1];
    strcpy_s(MSSV, strlen(mssv) + 1, mssv);

    HoTen = new char[strlen(hoten) + 1];
    strcpy_s(HoTen, strlen(hoten) + 1, hoten);

    DLT = dlt;
    DTH = dth;
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const int& dd, const int& mm, const int& yyyy)
{
    MSSV = new char[strlen(mssv) + 1];
    strcpy_s(MSSV, strlen(mssv) + 1, mssv);

    HoTen = new char[strlen(hoten) + 1];
    strcpy_s(HoTen, strlen(hoten) + 1, hoten);

    DLT = dlt;
    DTH = dth;

    NgayThang ngaysinh(dd, mm, yyyy);
    NgaySinh = ngaysinh;
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const NgayThang& ngaysinh)
{
    MSSV = new char[strlen(mssv) + 1];
    strcpy_s(MSSV, strlen(mssv) + 1, mssv);

    HoTen = new char[strlen(hoten) + 1];
    strcpy_s(HoTen, strlen(hoten) + 1, hoten);

    DLT = dlt;
    DTH = dth;

    NgaySinh = ngaysinh;
}
SinhVien::SinhVien(const SinhVien& sv)
{
    MSSV = new char[strlen(sv.MSSV) + 1];
    strcpy_s(MSSV, strlen(sv.MSSV) + 1, sv.MSSV);

    HoTen = new char[strlen(sv.HoTen) + 1];
    strcpy_s(HoTen, strlen(sv.HoTen) + 1, sv.HoTen);

    DLT = sv.DLT;
    DTH = sv.DTH;

    NgaySinh = sv.NgaySinh;
}

SinhVien::~SinhVien()
{
    delete[] MSSV;
    delete[] HoTen;
}

void SinhVien::Xuat()
{
    cout << "MSSV:" << MSSV << "  HoTen:"<<HoTen<<"  NgaySinh:";
    NgaySinh.Xuat();
    cout << "  DLT:" << DLT << "  DTH:" << DTH << endl;
}

int main()
{
    // MSSV: "xxxxxxxx", HoTen: "xxxx", NgaySinh: xx/xx/xxxx, DLT: 10, DTH: 10.
    SinhVien sv1;
    sv1.Xuat();
    SinhVien sv2("1363001");
    sv2.Xuat();
    SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
    sv3.Xuat();
    SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
    sv4.Xuat();
    NgayThang n(30, 2, 1996);
    SinhVien sv5("1363004", "Ngo Van C", 5, 6, n);
    sv5.Xuat();
    SinhVien sv6(sv5);
    sv6.Xuat();

    return 0;
}

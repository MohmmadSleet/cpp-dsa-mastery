// Perioud Length In Days.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct sDate {
    short Days;
    short Year;
    short Month;
};
struct sPerioud {
    sDate StartDate;
    sDate EndDate;
};
short ReadDays() {
    short Days = 0;
    cout << "Please enter the Days ?";
    cin >> Days;
    return Days;

}
short ReadMonth() {
    short Days = 0;
    cout << "Please enter the Month ?";
    cin >> Days;
    return Days;

}
short ReadYear() {
    short Days = 0;
    cout << "Please enter the Year ?";
    cin >> Days;
    return Days;

}
sDate ReadFullDate() {
    sDate Date;
    Date.Days = ReadDays();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

sPerioud ReadPerioud() {
    sPerioud Perioud;
    cout << "\n\nPlese Enter the Start Date ?\n";
    Perioud.StartDate = ReadFullDate();
    cout << "\n\nPlese Enter the End Date ?\n";
    Perioud.EndDate = ReadFullDate();
    return Perioud;
}
bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr[Month - 1];
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return Date1.Year < Date2.Year ? true : Date1.Year == Date2.Year ? Date1.Month < Date2.Month ? true : Date1.Month == Date2.Month ? Date1.Days < Date2.Days ? true : false : false : false;
}
bool IsLastDayInMonth(sDate Date1) {
    return (Date1.Days) == NumberOfDaysInMonth(Date1.Month, Date1.Year) ? true : false;
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}
sDate IncreaseOneDaysInDate(sDate Date1) {
    if (IsLastDayInMonth(Date1)) {
        if (IsLastMonthInYear(Date1.Month)) {
            Date1.Days = 1;
            Date1.Month = 1;
            Date1.Year++;
        }
        else {
            Date1.Days = 1;
            Date1.Month++;
        }
    }
    else {
        Date1.Days++;
    }
    return Date1;
}
short PerioudLength(sPerioud Perioud,bool IncludeEndDay=false) {
    short Days = 0;
    while (IsDate1BeforeDate2(Perioud.StartDate, Perioud.EndDate)) {
        Days++;
        Perioud.StartDate = IncreaseOneDaysInDate(Perioud.StartDate);
    }
    return IncludeEndDay ? ++Days : Days;
}

int main()
{
    cout << "Please enter Perioud 1 :\n";
    sPerioud Perioud1 = ReadPerioud();

    cout << "\nPerioud Length : " << PerioudLength(Perioud1);
    cout << "\nPerioud Length (Includeing End Dates) is " << PerioudLength(Perioud1,true);
    system("pause>0");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

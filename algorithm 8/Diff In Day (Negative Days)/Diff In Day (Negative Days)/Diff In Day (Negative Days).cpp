// your age in days.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
struct sDate {
    short Year;
    short Month;
    short Day;
};
int ReadDay() {
    int Day = 0;
    cout << "Please enter the Day ?";
    cin >> Day;
    return Day;
}
int ReadMonth() {
    int Day = 0;
    cout << "Please enter the Month ?";
    cin >> Day;
    return Day;
}
int ReadYear() {
    int Day = 0;
    cout << "Please enter the Year ?";
    cin >> Day;
    return Day;
}

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}
bool IsLeapYear(short Year) {
    return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month>12) {
        return 0;
    }
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}
bool IsLastDayInMonth(sDate DateOfBirth) {
    return (DateOfBirth.Day == NumberOfDaysInMonth(DateOfBirth.Month, DateOfBirth.Year));

}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}
bool IsDate1BeforeDate2(sDate DateOfBirth, sDate DateToday) {
    return DateOfBirth.Year < DateToday.Year ? true : DateOfBirth.Year == DateToday.Year ? DateOfBirth.Month < DateToday.Month ? true : DateOfBirth.Month == DateToday.Month ? DateOfBirth.Day < DateToday.Day ? true : false : false : false;
}
sDate IncreaseOneDaysForDate(sDate Date1) {
    if (IsLastDayInMonth(Date1)) {
        if (IsLastMonthInYear(Date1.Month)) {
            Date1.Day = 1;
            Date1.Month = 1;
            Date1.Year++;
        }
        else {
            Date1.Day = 1;
            Date1.Month++;
        }

    }
    else {
        Date1.Day++;
    }
    return Date1;
}
void SwapDate(sDate& Date1, sDate& Date2) {
    sDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
    

}
int GetDiffrent(sDate Date1, sDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    short SwapFaldgDays = 1;
    if (!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDate(Date1, Date2);
        SwapFaldgDays = -1;

    }
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseOneDaysForDate(Date1);
    }
    return IncludeEndDay ? ++Days*SwapFaldgDays : Days*SwapFaldgDays;
}

int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
   
    cout << "Diffrence is : " << GetDiffrent(Date1, Date2) << " Day(s). " << endl;
    cout << "Diffrence (Include End Day) : " << GetDiffrent(Date1, Date2,true) << " Day(s).";
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

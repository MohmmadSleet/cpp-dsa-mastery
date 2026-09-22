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
short NumberOfDaysInMonth(short Month,short Year) {

    if (Month < 1 || Month>12) {
        return 0;
    }
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}
bool IsLastDayInMonth(sDate DateOfBirth) {
    return (DateOfBirth.Day == NumberOfDaysInMonth(DateOfBirth.Month,DateOfBirth.Year));

}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}
bool IsDateOfBirthBeforDateToday(sDate DateOfBirth, sDate DateToday) {
    return DateOfBirth.Year < DateToday.Year ? true : DateOfBirth.Year == DateToday.Year ? DateOfBirth.Month < DateToday.Month ? true : DateOfBirth.Month == DateToday.Month ? DateOfBirth.Day < DateToday.Day ? true : false : false:false;
}
sDate IncreaseOneDaysForDate(sDate DateOfBirth) {
    if (IsLastDayInMonth(DateOfBirth)) {
        if (IsLastMonthInYear(DateOfBirth.Month)) {
            DateOfBirth.Day = 1;
            DateOfBirth.Month = 1;
            DateOfBirth.Year++;
        }
        else {
            DateOfBirth.Day = 1;
            DateOfBirth.Month++;
        }

    }
    else {
        DateOfBirth.Day++;
    }
    return DateOfBirth;
}

int GetAgeInDays(sDate DateOfBirth,sDate DateToday, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDateOfBirthBeforDateToday(DateOfBirth,DateToday)) {
        Days++;
        DateOfBirth = IncreaseOneDaysForDate(DateOfBirth);
    }
    return IncludeEndDay ? ++Days : Days;
}
sDate GetSystemDate() {
    sDate Date; 
    time_t t = time(0); 
    tm* now = localtime(&t); 
    Date.Year = now->tm_year + 1900;  
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday; 
    return Date;
}
int main()
{
    sDate DateOfBirth = ReadFullDate();
    sDate DateToday = GetSystemDate();
    cout << "Your Age is : " << GetAgeInDays(DateOfBirth,DateToday,true) << "Day (s) ";
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

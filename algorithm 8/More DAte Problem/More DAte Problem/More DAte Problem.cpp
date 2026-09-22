// More DAte Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};
bool IsLeapYear(short Year) {

    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberofDaysInAYear(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr[Month - 1];
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
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;    
    a = (14 - Month) / 12;  
    y = Year - a;    
    m = Month + (12 * a) - 2; 
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(sDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder) {

    string arrNameDay[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrNameDay[DayOfWeekOrder];
}
bool IsEndOfWeek(sDate Date) {

    return (DayOfWeekOrder(Date) == 6);
}
bool IsWeekEnd(sDate Date) {

    return (DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6);
}
bool IsBusinessDay(sDate Date) {

    return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(sDate Date1) {
    return (6 - DayOfWeekOrder(Date1));
}
bool IsDateBeforeDateEndsMonth(sDate Date, sDate DateEndsMonth) {

   return   Date.Year < DateEndsMonth.Year ? true : Date.Year == DateEndsMonth.Year ? Date.Month < DateEndsMonth.Month ? true : Date.Month == DateEndsMonth.Month ? Date.Day < DateEndsMonth.Day ? true : false : false:false;
     
}
bool IsLastDayInMonth(short Day,short Month,short Year) {

    return (Day == NumberofDaysInAYear(Month,Year));
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}
sDate IncreaseDateOneDay(sDate Date1) {
    if (IsLastDayInMonth(Date1.Day, Date1.Month, Date1.Year)) {
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
short GetDifferenceInMonth(sDate Date, sDate DateEndsMonth) {

    int Days = 0;
    while (IsDateBeforeDateEndsMonth(Date,DateEndsMonth)) {
        Days++;
        Date = IncreaseDateOneDay(Date);
    }
    return Days;
}
short DaysUntilTheEndOfMonth(sDate Date1) {
    sDate DateEndsMonth;
    DateEndsMonth.Day = NumberofDaysInAYear(Date1.Month, Date1.Year);
    DateEndsMonth.Month = Date1.Month;
    DateEndsMonth.Year = Date1.Year;

    return GetDifferenceInMonth(Date1, DateEndsMonth);

}
short DaysUntilTheEndOfYear(sDate Date1) {
    sDate DateEndsYear;
    DateEndsYear.Day = 31;
    DateEndsYear.Month = 12;
    DateEndsYear.Year = Date1.Year;
    return GetDifferenceInMonth(Date1, DateEndsYear);

}
int main()
{
    sDate Date1 = GetSystemDate();

    cout << "\n\tToday is " << DayShortName(DayOfWeekOrder(Date1)) << " , " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    cout << "\nIs it End Of Week ?";
    if (IsEndOfWeek(Date1)) {
        cout << "\n Yes ,it's saturday. ";
    }
    else {
        cout << "\n No ,it's Not end of week. ";
    }
    cout << "\n\n";
    cout << "Is it WeekEnd ?";
    if (IsWeekEnd(Date1)) {
        cout << "\n Yes,it is a WeekEnd .";
    }
    else {
        cout << "\n No,it isn't a weekEnd  Today : "
            <<DayShortName(DayOfWeekOrder(Date1));
    }
    cout << "\n\n Is it Business Day ?";
    if (IsBusinessDay(Date1)) {
        cout << "\n Yes,it is a Business .";
    }
    else {
        cout << "\n No,it isn't a Business  Today : "
            << DayShortName(DayOfWeekOrder(Date1));
    }
    cout << "\n\nDays until end of week : " 
        << DaysUntilTheEndOfWeek(Date1) << " Day(s)." ;
    cout << "\n\nDays until end of Month : "
        << DaysUntilTheEndOfMonth(Date1) << " Day(s).";
    cout << "\n\nDays until end of Year : "<< DaysUntilTheEndOfYear(Date1) << " Day(s).";

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

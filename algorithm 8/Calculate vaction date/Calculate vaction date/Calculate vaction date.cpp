// Calculate vaction date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;

};
short ReadDay() {
    short Day = 0;
    cout << "Please enter the Day ?";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Day = 0;
    cout << "Please enter the Month ?";
    cin >> Day;
    return Day;
}
short ReadYear() {
    short Day = 0;
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
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ?(IsLeapYear(Year)?29:28) : arr[Month - 1];
}
bool IsLastDayInMonth(short Day, short Month, short Year) {
    return (Day == NumberOfDaysInMonth(Month, Year));
}
bool IsLastMonthInYear(short Month){
    return Month == 12 ? true : false;
}
bool IsDateStartsBeforeDateFinish(sDate DateFrom, sDate DateTo) {

    return DateFrom.Year < DateTo.Year ? true : DateFrom.Year == DateTo.Year ? DateFrom.Month < DateTo.Month ? true : DateFrom.Month == DateTo.Month ? DateFrom.Day < DateTo.Day ? true : false : false:false;
}
sDate IncreasDateByOneDay(sDate DateVactionStrarts) {
    if (IsLastDayInMonth(DateVactionStrarts.Day, DateVactionStrarts.Month, DateVactionStrarts.Year)) {
        if (IsLastMonthInYear(DateVactionStrarts.Month)) {
            DateVactionStrarts.Day = 1;
            DateVactionStrarts.Month = 1;
            DateVactionStrarts.Year++;
        }
        else {
            DateVactionStrarts.Day = 1;
            DateVactionStrarts.Month++;
        }
    }
    else {
        DateVactionStrarts.Day++;
    }
    return DateVactionStrarts;
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
bool IsWeekEnd(sDate DateFrom) {
    return (DayOfWeekOrder(DateFrom) == 5) || (DayOfWeekOrder(DateFrom) == 6);
}
bool IsBusinesDay(sDate DateFrom) {
    return !IsWeekEnd(DateFrom);
}
short GetDiffrenceInDates(sDate DateVactionStrarts, sDate DateVactionFinish) {
    int Days = 0;

    while (IsDateStartsBeforeDateFinish(DateVactionStrarts, DateVactionFinish)) {
       if(IsBusinesDay(DateVactionStrarts))
        Days++;

        DateVactionStrarts = IncreasDateByOneDay(DateVactionStrarts);

    }
    return Days;

}
short  ActualVactionDays(sDate DateVactionStarts, sDate DateVactionFinish) {

    return GetDiffrenceInDates(DateVactionStarts, DateVactionFinish);
}
int main()
{
    cout << " Vaction Starts :\n\n";
    sDate DateFrom = ReadFullDate();
    cout << "\n\n Vaction End :\n";
    sDate DateTo = ReadFullDate();

    cout << "\n\n vaction From : " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << " vaction To : " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "Actual vaction Days = " << ActualVactionDays(DateFrom, DateTo);
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

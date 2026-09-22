// Date1 less than date 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct sDate {
    short Year;
    short Month;
    short Day;
};
bool IsLeapYear(short Year) {
    return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short ReadDay() {
    short Day = 0;
    cout << "\n\nplease enter the Day ?";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Day = 0;
    cout << "please enter the Month ?";
    cin >> Day;
    return Day;
}
short ReadYear() {
    short Day = 0;
    cout << "please enter the Year ?";
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
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr31Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    
    return  (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr31Days[Month - 1];
}
short NumberOfDaysFromBeginingYear(short Year, short Month, short Days) {
    int TotalDays = 0;
    for (int i = 1; i <= Month; i++) {
        TotalDays += NumberOfDaysInMonth(Month, Year);
    }
    TotalDays += Days;
    return TotalDays;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? Date1.Month < Date2.Month : Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false);
}
int main()
{
    sDate Date1, Date2;
    Date1 = ReadFullDate();
    Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1,Date2)) {
        cout << "\nYes , Date1 is less than Date2";

    }
    else {
        cout << "\nNo, Date1 isn't less than Date2";

    }
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

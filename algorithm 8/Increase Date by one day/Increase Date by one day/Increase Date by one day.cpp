// Increase Date by one day.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr31Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr31Days[Month - 1];
}
bool ISLastDayInMonth(sDate Date) {

    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool ISLastMonthInYear(short month ) {

    return (month==12);
}
short ReadDay() {
    short Day = 0;
    cout << "please enter the Day ?";
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
sDate AddMoreDay(sDate Date) {
    if (ISLastDayInMonth(Date)) {
        if (ISLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }

    }
    else {
        Date.Day++;

    }
    return Date;

}
int main()
{
    sDate Date = ReadFullDate();
    
    Date = AddMoreDay(Date);

    cout << "Date After Adding one Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
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

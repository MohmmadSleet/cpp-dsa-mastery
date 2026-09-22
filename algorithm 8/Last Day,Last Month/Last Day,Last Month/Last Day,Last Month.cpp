// Last Day,Last Month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct sDate {
    short Year;
    short Month;
    short Day;
};
short ReadYear() {
    short Year = 0;
    cout << "Please enter the Year ? ";
    cin >> Year;
    return Year;
}
short ReadMonth() {
    short Year = 0;
    cout << "Please enter the Month ? ";
    cin >> Year;
    return Year;
}
short ReadDay() {
    short Year = 0;
    cout << "Please enter the Day ? ";
    cin >> Year;
    return Year;
}
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    

    return Date;
}
bool ISLeapYea(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOFDaysInMonth(short Month,short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr31Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (ISLeapYea(Year)?29:28) : Arr31Days[Month - 1];
}
bool IsLastDayInMonth(sDate Date) {

    return(Date.Day == NumberOFDaysInMonth(Date.Month,Date.Year));
}
bool IsLastMonthInYear(short Month) {

    return  (Month == 12);
}
int main()
{
    sDate Date = ReadFullDate();
    if (IsLastDayInMonth(Date)) {
        cout << "\nYes , Day is last day in month .";
    }
    else {
        cout << "\n No ,Day isn't last day in month .";
    }
    if (IsLastMonthInYear(Date.Month)) {
        cout << "\nYes , Month is last Month in Year .";
    }
    else {
        cout << "\n No ,Month isn't last Month in Year .";
    }

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

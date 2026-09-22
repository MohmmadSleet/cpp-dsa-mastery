// Is Date 1 afert Date 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct sDate {
    short Year;
    short Month;
    short Days;

};
short ReadDays() {
    short Days = 0;
    cout << "please enter the Days ?";
    cin >> Days;
    return Days;
}
short ReadMonth() {
    short Days = 0;
    cout << "please enter the Month ?";
    cin >> Days;
    return Days;
}
short ReadYear() {
    short Days = 0;
    cout << "please enter the Year ?";
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

bool IsDate1beforeDate2(sDate Date1, sDate Date2) {

    return Date1.Year < Date2.Year ? true : Date1.Year == Date2.Year ? Date1.Month < Date2.Month ? true : Date1.Month == Date2.Month ? Date1.Days < Date2.Days ? true : false : false : false;
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {

    return Date1.Year == Date2.Year ?  Date1.Month == Date2.Month  ? Date1.Days ==Date2.Days ? true :false:false:false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2) {

    return (!(IsDate1beforeDate2(Date1, Date2)) && !(IsDate1EqualDate2(Date1, Date2)));
}
int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    
    if (IsDate1AfterDate2(Date1, Date2)) {
        cout << "Yes, Date1 is after Date2 .";
    }
    else {
        cout << "No, Date1 isn't after Date2 .";

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

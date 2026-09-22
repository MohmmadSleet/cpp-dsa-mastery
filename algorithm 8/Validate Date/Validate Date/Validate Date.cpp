// Validate Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct sDate {
    short Days;
    short Month;
    short Year;
};
short ReadDays() {
    short Days = 0;
    cout << "\nPlease enter the Days ?";
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
bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr[Month - 1];
}
bool IsDateValidate(sDate Date1) {
 
    if (Date1.Days < 1 || Date1.Days>31) {
        return false;
    }
    if (Date1.Month < 1 || Date1.Month>12) {
        return false;
    }
    if (Date1.Month == 2) {
        if (IsLeapYear(Date1.Year)) {
            if (Date1.Days > 29)
                return false;
        }
        else {
            if (Date1.Days > 28) {
                return false;
            }
        }

    }
    short NumberOfDays = NumberOfDaysInMonth(Date1.Month, Date1.Year);
    if (Date1.Days > NumberOfDays) {
        return false;
    }
    return true;

    
}
int main()
{
    cout << "Please enter the Date ?";
    sDate Date1 = ReadFullDate();

    if (IsDateValidate(Date1)) {
        cout << "\n\nYes,Date is a validate.";
    }
    else {
        cout << "\n\nNo,Date isn't a validate.";
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

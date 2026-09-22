// Days From The  Beginning of year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
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
bool IsLeapYear(short Year) {
    
    return((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short NumberOfDaysInMonth(short Month,short Year) {
    if (Month > 12 || Month < 1) {
        return 0;
    }
    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : Days[Month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short  Month, short Year) {
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\n\n Number Of Days from  the begining of the year is : " << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

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

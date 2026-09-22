// Day Name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

short ReadYear() {
    short Year = 0;
    cout << "please enter the Year ? ";
    cin >> Year;
    return Year;
}
short ReadMonth() {
    short Year = 0;
    cout << "please enter the Month ? ";
    cin >> Year;
    return Year;
}
short ReadDay() {
    short Year = 0;
    cout << "please enter the Day ? ";
    cin >> Year;
    return Year;
}
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m; 
    a = (14 - Month) / 12;
    y = Year - a; 
    m = Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayName(short DayOrde) {
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return  arrDayNames[DayOrde];
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n Date            : " << Day << "/" << Month << "/" << Year;
    cout << "\n Day Orde        : " << DayOfWeekOrder(Year, Month, Day);
    cout << "\n Day Name        : " << DayName(DayOfWeekOrder(Year, Month, Day));
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

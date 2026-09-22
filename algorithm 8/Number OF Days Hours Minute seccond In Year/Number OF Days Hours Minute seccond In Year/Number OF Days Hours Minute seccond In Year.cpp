// Number OF Days Hours Minute seccond In Year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int PleaseEnterTheYear() {
    int Year = 0;
    cout << "Please eneter Year You check ?";
    cin >> Year;
    return Year;
}
bool IsLeapYear(int Year) {
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}
int NumberOfDays(int Year) {
    int Number = 0;
    
    return IsLeapYear(Year) ? 366 : 365;

}
int NumberOfHours(int Number) {
    return NumberOfDays(Number) * 24;
}
int NumberOfMinutse(int Number) {
    return NumberOfHours(Number) * 60;
}
int NumberOfSecond(int Number) {
    return NumberOfMinutse(Number) * 60;
}
int main()
{
    int Year = PleaseEnterTheYear();
    
    cout << "Number of Days in Year [" << Year << "] is " << NumberOfDays(Year) << endl;
    cout << "Number of hours in Year [" << Year << "] is " << NumberOfHours(Year) << endl;
    cout << "Number of Minute in Year [" << Year << "] is " << NumberOfMinutse(Year) << endl;
    cout << "Number of second in Year [" << Year << "] is " << NumberOfSecond(Year) << endl;

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

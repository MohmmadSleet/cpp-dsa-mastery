// Number Of Days In Moth Short Logic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int ReadTheYear() {
	int Year = 0;
	cout << "please enter the Year ?";
	cin >> Year;
	return Year;
}
int ReadTheMonth() {
	int Year = 0;
	cout << "please enter the Month ?";
	cin >> Year;
	return Year;
}
bool IsLeapYear(int Year) {
	
	return(Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
}
int NumberOfDaysInMonth(int Year, int Month) {
	if (Month < 1 || Month>12) {
		return 0;
	}
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

int main()
{
	int Year = ReadTheYear();
	int Month = ReadTheMonth();
	cout << "Number Of Days in [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
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

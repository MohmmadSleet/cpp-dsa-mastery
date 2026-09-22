// Number of Days Hours Minutes Second In Month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int NumberOfYear() {
	int Year = 0;
	cout << "Please enter the Year ?";
	cin >> Year;
	return Year;
}
int NumberOfMonth() {
	int Month = 0;
	cout << "Please enter the Month ?[1 TO 12]? ";
	cin >> Month;
	return Month;
}
bool ISLeapYear(int Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
int NumberOfDaysInMonth(int Year, int Month) {
	if (Month < 1 || Month>12) {
		return 0;
	}
		if (Month == 2) {
			return ISLeapYear(Year) ? 29 : 28;
		}
		int Arr31Days[7]={ 1,3,5,7,8,10,12 };
		for (short i = 0; i <= 6; i++) {
			if(Arr31Days[i] == Month) {
				return 31;
				}
		}

	
	return 30;
}

int NumberOfHoursInMonth(int Year, int Month) {
	return NumberOfDaysInMonth(Year, Month) * 24;
}
int NumberOfMinutesInMonth(int Year, int Month) {
	return NumberOfHoursInMonth(Year, Month) * 60;
}
int NumberOfSecondInMonth(int Year, int Month) {
	return NumberOfMinutesInMonth(Year, Month) * 60;
}
int main()
{
	int Year = NumberOfYear();
	int Month = NumberOfMonth();
	cout << "Number Of Days in Month[" << Month << "] is " << NumberOfDaysInMonth(Year,Month) << endl;
	cout << "Number Of Hours in Month[" << Month << "] is " << NumberOfHoursInMonth(Year,Month) << endl;;
	cout << "Number Of Minutes in Month[" << Month << "] is " << NumberOfMinutesInMonth(Year,Month) << endl;;
	cout << "Number Of Second in Month[" << Month << "] is " << NumberOfSecondInMonth(Year,Month) << endl;;


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

// Year Calender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

using namespace std;
short ReadYear() {
	short Year = 0;
	cout << "Please enter the Year\n";
	cin >> Year;
	return Year;
}
bool IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short DayOfWeekOrder(short Day,short Month, short Year) {
	short a, y, m; 
	a = (14 - Month) / 12;
	y = Year - a; 
	m = Month + (12 * a) - 2;
	// Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short NumberOfDaysInMonth(short Month, short Year) {
	if (Month > 12 || Month < 1) {
		return 0;
	}
	
	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return(Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}
string ShowMonthName(short Month) {
	string arrMonth[12] = { "Jan","Feb","Mar","April","May","Jun","July","Aug","Sep","Oct","Nov","Dec" };
	return arrMonth[Month - 1];
}
void PrintMonthCalender(short Month, short Year) {
	int counter = DayOfWeekOrder(1,Month, Year);
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);

	printf("______________%s______________", ShowMonthName(Month).c_str());
	printf("\nSun  Mon Tue  Wed  Thu  Fri  Sat\n");
	int i;
	for (i = 0; i < counter; i++) {
		printf("    ");
	}
	for (int j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			cout << endl;
		}
	}
	printf("\n  _________________________________\n");
}
void PrintYearCalender(short Year) {
	cout << "____________________________\n";
	printf("           Calender  .  %d       ", Year);
	cout << "\n____________________________\n";

	for (int i = 1; i <= 12; i++) {
		PrintMonthCalender(i, Year);
	}

}

int main() {

	PrintYearCalender(ReadYear());

	return 0;
}
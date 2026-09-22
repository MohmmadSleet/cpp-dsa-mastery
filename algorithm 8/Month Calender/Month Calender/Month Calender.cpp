#include<iostream>
using namespace std;

bool IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
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
int DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOFWeek) {

	string arrDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDay[DayOFWeek];

}
string MonthShortName(short MonthOfYear) {
	string arrMonth[12] = { "Jan","Feb","Mar","Apr","May","Jun","July","Aug","Sep","Oct","Nov","Dec" };
	return arrMonth[MonthOfYear - 1];
}
int NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month>12) {
		return 0;
	}
		int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : Days[Month - 1];
	
}
void PrintMonthCalender(short Year, short Month) {

	int Counter = DayOfWeekOrder(1, Month, Year);
	int NumberOfDays = NumberOfDaysInMonth(Month,Year);

	printf("\n\n------------%s-----------------\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu Fri  Sat  \n");
	int i;
	for (i = 0; i <= Counter; i++) 
		printf("     ");
	for (int j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}

}
int main() {
	short Year = ReadYear();
	short Month = ReadMonth();
	
	PrintMonthCalender(Year, Month);

	return 0;

}
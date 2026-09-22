#include<iostream>
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
	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay();
	return Date;
}
short ReadDaysToAdd() {
	short Add = 0;
	cout << "\nHow many days to add ? ";
	cin >> Add;
	return Add;
}
bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Month,short Year) {
	if (Month < 1 || Month>12) {
		return 0;
	}
	int Arr31Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ?(IsLeapYear(Year)?29:28) : Arr31Days[Month - 1];

}
short NumberOfDaysFromTheBeginingOfTheYear(short Days,short Month,short Year) {
	int TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++) {
		TotalDays += NumberOfDaysInMonth(Month, Year);
	}
	TotalDays += Days;
	return TotalDays;
}
sDate DateAddDays(short Days, sDate Date) {
	
	
	int RemmainingDays = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year)+Days;
	int MonthDays = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (RemmainingDays>MonthDays) {
			RemmainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12) {
				Date.Month = 1;
				Date.Year++;
			}
		}
		else {
			Date.Day = RemmainingDays;
			break;
		}
	}
	return Date;
}
int main() {
	sDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);
	cout << "\n\n Date After adding Days [" << Days << "] Become : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	system("pause>0");
	return 0;
}
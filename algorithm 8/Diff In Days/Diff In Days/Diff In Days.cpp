#include<iostream>

using namespace std;
struct sDate {
	short Year;
	short Month;
	short Day;
};
short ReadDay() {
	short DAy = 0;
	cout << "please enter the Day ?";
	cin >> DAy;
	return DAy;

}
short ReadMonth() {
	short DAy = 0;
	cout << "please enter the Month ?";
	cin >> DAy;
	return DAy;
}
short ReadYear() {
	short DAy = 0;
	cout << "please enter the Year ?";
	cin >> DAy;
	return DAy;

}

sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
bool IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
int NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month>12) {
		return 0;
	}
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month==2)?(IsLeapYear(Year)?29:28) : arr[Month - 1];

}
bool IsLastDayInMonth(sDate Date) {

	return Date.Day == NumberOfDaysInMonth(Date.Month,Date.Year);
}
bool IsLastMonthInYear(short Month) {
	return (Month == 12) ? true : false;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {

	return Date1.Year < Date2.Year ? true : Date1.Year == Date2.Year ? Date1.Month < Date2.Month ? true : Date1.Month == Date2.Month ? Date1.Day < Date2.Day ? true : false : false : false;
}
sDate IncreaseOnDayToDate1(sDate Date1) {

	if (IsLastDayInMonth(Date1)) {
		if (IsLastMonthInYear(Date1.Month)) {
			Date1.Day = 1;
			Date1.Month = 1;
			Date1.Year++;
		}
		else {
			Date1.Day = 1;
			Date1.Month++;
		}
	}
	else {
		Date1.Day++;
	}
	return Date1;
}
int GetDiffrenceInDays(sDate Date1, sDate Date2,bool IncludeEndDay = false) {
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2)) {
		Days++;
		Date1 = IncreaseOnDayToDate1(Date1);
	}
	
	return IncludeEndDay ? ++Days : Days;
}

int main() {
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	cout << "\n\n Diffrence is :" << GetDiffrenceInDays(Date1, Date2) << " Day(s) .";
	cout << "\n\n Diffrence (Includeing End Day) : " << GetDiffrenceInDays(Date1, Date2,false) << " Day(s) .";



	return 0;
}
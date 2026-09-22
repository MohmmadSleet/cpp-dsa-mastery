// Increase Date Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct sDate {
    short Year;
    short Month;
    short Day;

};
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

    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month>12) {
        return 0;

    }
    int arr[12] = { 31,28,31,30,31,30,31,30,30,31,30,31 };
    
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];

}
bool IsLastDayInMonth(short Day,short Month,short Year) {
    return (Day == NumberOfDaysInMonth(Year, Month));
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}

sDate ReadFullDate() {
    sDate Date1;
    Date1.Day = ReadDay();
    Date1.Month = ReadMonth();
    Date1.Year = ReadYear();
    return Date1;
}
sDate IncreaseDayByOneDay(sDate Date1) {
    if (IsLastDayInMonth(Date1.Day, Date1.Month, Date1.Year)) {
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
sDate IncreaseDayByXDay(short Days,sDate Date1) {

    for (short i = 1; i <= Days; i++) {
        Date1=IncreaseDayByOneDay(Date1);
    }
    return Date1;
}
sDate IncreaseDateByOneWeek(sDate Date1) {
    short Week = 7;
    for (int i = 1; i <= Week; i++) {
        Date1 = IncreaseDayByOneDay(Date1);
    }
    return Date1;
}
sDate IncreaseDateByXWeeks(short Weeks, sDate Date1) {
    for (short i = 1; i <= Weeks; i++) {
        Date1 = IncreaseDateByOneWeek(Date1);
    }
    return Date1;
}
sDate IncreaseDateByOneMonth(sDate Date1) {
    if (Date1.Month == 12) {
        Date1.Month = 1;
        Date1.Year++;
    }
    else {
        Date1.Month++;
    }
    short NumberOfDaysInCurrent = NumberOfDaysInMonth(Date1.Year, Date1.Month);

    if (Date1.Day > NumberOfDaysInCurrent) {
        Date1.Day = NumberOfDaysInCurrent;
    }
    
    return Date1;
}
sDate IncreaseDateByXMonths(short Month, sDate Date1) {
    for (short i = 1; i <= Month; i++) {
        Date1 = IncreaseDateByOneMonth(Date1);
    }
    return Date1;
}
sDate IncreaseDateByOneYear(sDate Date1) {
    Date1.Year++;
    return Date1;
}
sDate IncreaseDateByXYears(short Year, sDate Date1) {
    for (short i = 1; i <= Year; i++) {
        Date1 = IncreaseDateByOneYear(Date1);
    }
    return Date1;
}
sDate IncreaseDateByXYearsFaster(short Year, sDate Date1) {
    
    Date1.Year += Year;
    return Date1;
}

sDate IncreaseDateByOneDecade(sDate Date1) {

    Date1.Year += 10;
    return Date1;
}
sDate IncreaseDateByXDecades(short Decads, sDate Date1) {
    for (short i = 1; i <= Decads; i++) {
        Date1 = IncreaseDateByOneDecade(Date1);
    }
    return Date1;
}
sDate IncreaseDateByXDecadesFaster(short Decads, sDate Date1) {

    Date1.Year += (Decads*10);
    return Date1;
}
sDate IncreaseDateByOneCentury(sDate Date1) {

    Date1.Year += 100;
    return Date1;
}
sDate IncreaseDateByOneMillennium(sDate Date1) {

    Date1.Year += 1000;
    return Date1;
}
int main()
{
    sDate Date1 = ReadFullDate();

    cout << "\n Date after : \n";

    Date1 = IncreaseDayByOneDay(Date1);
    cout << "\n01-Adding One Day = " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDayByXDay(10,Date1);
    cout << "\n02-Adding 10 Day = " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneWeek(Date1);   
    cout << "\n03-Adding one week is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXWeeks(10, Date1);   
    cout << "\n04-Adding 10 weeks is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMonth(Date1);  
    cout << "\n05-Adding one month is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;  

    Date1 = IncreaseDateByXMonths(5, Date1);  
    cout << "\n06-Adding 5 months is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);  
    cout << "\n07-Adding one year is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "\n08-Adding 10 Years is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);  
    cout << "\n09-Adding 10 Years (faster) is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);    
    cout << "\n10-Adding one Decade is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1); 
    cout << "\n11-Adding 10 Decades is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = IncreaseDateByXDecadesFaster(10, Date1); 
    cout << "\n12-Adding 10 Decade (faster) is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "\n13-Adding One Century is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = IncreaseDateByOneMillennium(Date1); 
    cout << "\n14-Adding One Millennium is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

        
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

// Decrease Date Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    cout << "Plesae enter the Day ?";
    cin >> Day;
    return Day;

}
short ReadMonth() {
    short Day = 0;
    cout << "Plesae enter the Month ?";
    cin >> Day;
    return Day;

}
short ReadYear() {
    short Day = 0;
    cout << "Plesae enter the Year ?";
    cin >> Day;
    return Day;

}
bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month>12) {
        return 0;
    }
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear ? 29 : 28) : arr[Month - 1];
}
bool IsLastDayInMonth(short Day,short Month,short Year) {

    return (Day == NumberOfDaysInMonth(Month, Year));
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}

bool IsFirstDayInMonth(short Day, short Month, short Year) {

    return (Day == 1) ? true : false;
}
bool IsFirstMonthInYear(short Month) {
    return (Month == 1) ? true : false;
}
sDate DecreaseDateByOneDay(sDate Date1) {
    if (IsFirstDayInMonth(Date1.Day, Date1.Month, Date1.Year)) {
        if (IsFirstMonthInYear(Date1.Month)) {
            Date1.Day=31;
            Date1.Month = 12;
            Date1.Year--;
        }
        else {
            Date1.Month--;
            Date1.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
            
            
        }
    }
    else {
        Date1.Day--;
    }
    return Date1;
}
sDate DecreaseDateByXDays(short Days, sDate Date1) {
    for (int i = 1; i <= Days; i++) {
        Date1 = DecreaseDateByOneDay(Date1);
    }
    return Date1;
}
sDate DecreaseDateByOneWeek(sDate Date1) {

    for (int i = 1; i <= 7; i++) {
        Date1 = DecreaseDateByOneDay(Date1);
    }
    return Date1;
}
sDate DecreaseDateByXWeeks(short Weeks,sDate Date1) {

    for (int i = 1; i <= Weeks; i++) {
        Date1 = DecreaseDateByOneWeek(Date1);
    }
    return Date1;
}
sDate DecreaseDateByOneMonth(sDate Date1) {
    if (Date1.Month == 1) {
        Date1.Month = 12;
        Date1.Year--;
    }
    else {
        Date1.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date1.Month, Date1.Year);
    if (Date1.Day > NumberOfDaysInCurrentMonth) {
        Date1.Day = NumberOfDaysInCurrentMonth;
    }
    return Date1;
}
sDate DecreaseDateByXMonths(short Month, sDate Date1) {

    for (int i = 1; i <= Month; i++) {
        Date1 = DecreaseDateByOneMonth(Date1);
    }
    return Date1;
}
sDate DecreaseDateByOneYear( sDate Date1) {

    Date1.Year--;
    return Date1;
}
sDate DecreaseDateByXYears(short Years,sDate Date1) {

    for (int i = 1; i <= Years; i++) {
        Date1 = DecreaseDateByOneYear(Date1);
    }
    return Date1;
}
sDate DecreaseDateByXYearsFaster(short Years, sDate Date1) {

    Date1.Year -= Years;
    return Date1;
}
sDate DecreaseDateByOneDecade( sDate Date1) {

    Date1.Year -= 10;
    return Date1;
}
sDate DecreaseDateByXDecades(short Decades,sDate Date1) {

    for (int i = 1; i <= Decades; i++) {
        Date1 = DecreaseDateByOneDecade(Date1);
    }
    
    return Date1;
}
sDate DecreaseDateByXDecadesFaster (short Decades, sDate Date1) {

    Date1.Year -= (Decades * 10);
    
    return Date1;
}
sDate  DecreaseDateByOneCentury(sDate Date1) {

    Date1.Year -= 100 ;

    return Date1;
}
sDate  DecreaseDateByOneMillennium(sDate Date1) {

    Date1.Year -= 1000;

    return Date1;
}
int main()
{
    sDate Date1 = ReadFullDate();
    cout << "\nDate After: \n";  
    Date1 = DecreaseDateByOneDay(Date1);   
    cout << "\n01-Subtracting one day is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByXDays(10, Date1);  
    cout << "\n02-Subtracting 10 days is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByOneWeek(Date1);
    cout << "\n03-Subtracting one week is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXWeeks(10, Date1);  
    cout << "\n04-Subtracting 10 weeks is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByOneMonth(Date1);  
    cout << "\n05-Subtracting one month is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByXMonths(5, Date1);
    cout << "\n06-Subtracting 5 months is: "    
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByOneYear(Date1); 
    cout << "\n07-Subtracting one year is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;  

    Date1 = DecreaseDateByXYears(10, Date1); 
    cout << "\n08-Subtracting 10 Years is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByXYearsFaster(10, Date1); 
    cout << "\n09-Subtracting 10 Years (faster) is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByOneDecade(Date1);   
    cout << "\n10-Subtracting one Decade is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecades(10, Date1);   
    cout << "\n11-Subtracting 10 Decades is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByXDecadesFaster(10, Date1); 
    cout << "\n12-Subtracting 10 Decade (faster) is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = DecreaseDateByOneCentury(Date1);   
    cout << "\n13-Subtracting One Century is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMillennium(Date1);
    cout << "\n14-Subtracting One Millennium is: " 
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

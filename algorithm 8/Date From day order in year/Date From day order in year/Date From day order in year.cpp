// Date From day order in year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
short ReadDay() {
    short Day = 0;
    cout << "please enter the Day ?";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Day = 0;
    cout << "please enter the Month ?";
    cin >> Day;
    return Day;
}
short ReadYear() {
    short Day = 0;
    cout << "please enter the Year ?";
    cin >> Day;
    return Day;
}
bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Year,short Month) {
    if (Month > 12 || Month < 1) {
        return 0;
    }
    int arr31Days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr31Days[Month - 1];
}
short DayOfWeekOrder(short Day, short Month, short Year) {

    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short Order) {
    string DayName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return DayName[Order];
}
string MonthShortName(short Month) {
    string MonthName[12] = { "Jan","Feb","Mar","April","May","Jun","July","Aug","Sep","Oct","Nov","Dec" };
    return MonthName[Month - 1];
}
void PrintMonthCalender(short Year, short Month) {
    int Current = DayOfWeekOrder(1,Month,Year);
        int NumberOfDays = NumberOfDaysInMonth(Year, Month);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        // Print the columns
          printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
          int i;
          for (i = 0; i < Current; i++) {
              printf("     ");
          }
          for (int j = 1; j <= NumberOfDays; j++) {
              printf("%5d", j);
              if (++i == 7) {
                  i = 0;
                  cout << endl;
              }
          }


}
void PrintYearCalender(short Year) {
    printf("\n______________________________\n");
    printf("           Calender .%d   \n", Year);
    printf("______________________________\n");

    for (int i = 1; i <= 12; i++) {
        PrintMonthCalender(Year, i);
    }

}
short NumberofDaysfromthebeginingoftheYear(short Day, short Month, short Year) {
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInMonth(Year,i);
    }
    TotalDays += Day;
    return TotalDays;
}
struct sDate {
    short Year;
    short Month;
    short Day;
};
sDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year) {
    sDate Date;
    Date.Year = Year;
    Date.Month = 1;
    short RemainingDays = DayOrderInYear;
    short MonthDays = 0;

    while (true) {
        MonthDays = NumberOfDaysInMonth(Year,Date.Month);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

    int main() {
        short Day = ReadDay();
        short Month = ReadMonth();
        short Year = ReadYear();
        short DayOrderInYear = NumberofDaysfromthebeginingoftheYear(Day, Month, Year);
        cout << "Number of Days from the begining of the Year = " << DayOrderInYear;
        sDate Date;
        Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);
        cout << "\n\nDate For [" << DayOrderInYear << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
        
        return 0;

    }
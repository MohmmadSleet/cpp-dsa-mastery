/// Compare Date Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct sDate {
    short Year;
    short Month;
    short Day;
};
struct sPerioud {
    sDate StartDate;
    sDate EndDate;
};
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
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
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;

}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return Date1.Year < Date2.Year ? true : Date1.Year == Date2.Year ? Date1.Month < Date2.Month ? true : Date1.Month == Date2.Month ? Date1.Day < Date2.Day ? true : false : false : false;
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
    return Date1.Year == Date2.Year ? Date1.Month == Date2.Month ? Date1.Day == Date2.Day ? true : false : false : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enDateCompare CompareDates(sDate Date1, sDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    /* if (IsDate1AfterDate2(Date1,Date2))
   return enDateCompare::After;*/
   //this is faster 
    return enDateCompare::After;
}
sPerioud ReadPerioud() {
    sPerioud Perioud;
    cout << "\n Enter start Date : \n";
    Perioud.StartDate = ReadFullDate();
    cout << "\n Enter End Date : \n ";
    Perioud.EndDate = ReadFullDate();
    return Perioud;
}
bool IsOverLapPerioud(sPerioud Perioud1, sPerioud Perioud2) {

    if (CompareDates(Perioud2.EndDate, Perioud1.StartDate) == enDateCompare::Before
        || CompareDates(Perioud2.StartDate, Perioud1.EndDate) == enDateCompare::After) {
        return false;
    }
    else {
        return true;
    }
}
bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month <1 || Month>12) {
        return 0;
    }
    int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29:28) : Arr[Month - 1];
}
bool IsLastDayInMonth(sPerioud Perioud) {

    return (Perioud.StartDate.Day == NumberOfDaysInMonth(Perioud.StartDate.Month, Perioud.StartDate.Year)?true:false);
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12) ? true : false;
}
sPerioud  IncreaseOneDaysInDate(sPerioud Perioud) {
    if (IsLastDayInMonth(Perioud)) {
        if (IsLastMonthInYear(Perioud.StartDate.Month)) {
            Perioud.StartDate.Day = 1;
            Perioud.StartDate.Month = 1;
            Perioud.StartDate.Year++;
        }
        else {
            Perioud.StartDate.Day = 1;
            Perioud.StartDate.Month++;
        }
    }
    else {
        Perioud.StartDate.Day++;
    }
    return Perioud;
}
int GetDiffrenceBetweenPerioud(sPerioud Perioud, bool IncludeingEndDate) {
    int Days = 0;
    while(IsDate1BeforeDate2(Perioud.StartDate, Perioud.EndDate)) {
        Days++;
        Perioud = IncreaseOneDaysInDate(Perioud);
    }
    return Days;
}
int PerioudLengthInDays(sPerioud Perioud, bool IncludeingEndDate=false) {
    return GetDiffrenceBetweenPerioud(Perioud, IncludeingEndDate);
}
bool isDateInPeriod(sDate Date, sPerioud Period) { 
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before 
        || CompareDates(Date, Period.EndDate) == enDateCompare::After); }

short CountOverLapDays(sPerioud Perioud1, sPerioud Perioud2) {
    short CountDays = 0;
    int Perioud1Length = PerioudLengthInDays(Perioud1,true);
    int Perioud2Length = PerioudLengthInDays(Perioud2,true);

    if (!IsOverLapPerioud(Perioud1, Perioud2))
        return 0;

    if(Perioud1Length<Perioud2Length){
    
        while (IsDate1BeforeDate2(Perioud1.StartDate, Perioud1.EndDate)) {
            if (isDateInPeriod(Perioud1.StartDate, Perioud2)) {
                CountDays++;
            }
                Perioud1= IncreaseOneDaysInDate(Perioud1);
            
        }


    }
    else {
        while (IsDate1BeforeDate2(Perioud2.StartDate, Perioud2.EndDate)) {
            if (isDateInPeriod(Perioud2.StartDate, Perioud1)) {
                CountDays++;
            }
                Perioud2 = IncreaseOneDaysInDate(Perioud2);
            
        }
    }
    return CountDays;
}
int main()
{
    cout << "\n Enter a Perioud 1 : \n";
    sPerioud Perioud1 = ReadPerioud();
    cout << "\n\n Enter a Perioud 2 : \n";
    sPerioud Perioud2 = ReadPerioud();

    
       cout << "Over Lap Days Count is : " << CountOverLapDays(Perioud1, Perioud2);
   
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

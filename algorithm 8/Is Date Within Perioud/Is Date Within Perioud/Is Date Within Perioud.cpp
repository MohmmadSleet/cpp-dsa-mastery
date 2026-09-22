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
bool IsWithInPerioud(sPerioud Perioud1, sDate DateCheck) {

    if ((IsDate1BeforeDate2(DateCheck,Perioud1.EndDate))&&(IsDate1AfterDate2(DateCheck,Perioud1.StartDate))) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    cout << "\n Enter a Perioud 1 : \n";
    sPerioud Perioud1 = ReadPerioud();
    cout << "\n\n Enter Date to Check : \n";
    sDate DateCheck = ReadFullDate();

    if (IsWithInPerioud(Perioud1, DateCheck)) {
        cout << "Yes,Date With In Perioud .";
    }
    else {
        cout << "No,Date With In Perioud .";
    }

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

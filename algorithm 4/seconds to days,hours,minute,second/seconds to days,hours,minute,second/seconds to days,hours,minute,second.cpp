// seconds to days,hours,minute,second.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<math.h>
using namespace std;
struct strtaskduraion {
    int numbersofhours, numbersofdays, numbersofminutes, numbersofsecond;
};
float ReadPositiveNumbers(string message) {
    float TotalSeconds;
    do {
        cout << message << endl;
        cin >> TotalSeconds;

    } while (TotalSeconds <= 0);
    return TotalSeconds;
}
strtaskduraion secondtotaskduration(int totalseconds) {
    strtaskduraion taskduration;
    const int secondsperday = 24 * 60 * 60;
    const int secondsperhour = 60 * 60;
    const int secondsperminute = 60;
    int remainder = 0;

    taskduration.numbersofdays = floor(totalseconds / secondsperday);
    remainder = totalseconds % secondsperday;
    taskduration.numbersofhours = floor (remainder / secondsperhour);
    remainder = remainder % secondsperhour;
    taskduration.numbersofminutes = floor (remainder / secondsperminute);
    remainder = remainder % secondsperminute;
    taskduration.numbersofsecond = remainder ;
    return taskduration;
}
void printtaskdurationdetails(strtaskduraion taskduration) {

    cout << "task duration in time = " << endl;
    cout << taskduration.numbersofdays << " : " << taskduration.numbersofhours << " : "
        << taskduration.numbersofminutes << " : " << taskduration.numbersofsecond << endl;
}
int main()
{
    int TotalSeconds = ReadPositiveNumbers("please enter the total second : ");
    printtaskdurationdetails(secondtotaskduration(TotalSeconds));
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

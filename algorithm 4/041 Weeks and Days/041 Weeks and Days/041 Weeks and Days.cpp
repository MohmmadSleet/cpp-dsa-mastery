// 041 Weeks and Days.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

float readpositivenumbers(string message) {
    float numbers = 0;
    do {
        cout << message << endl;
        cin >> numbers;

    } while (numbers <= 0);
    return numbers;
}

float calculatenumberofweek(int numberofhour) {
    return (numberofhour / (24.0 * 7));

}
float calculatenumberofdays(int numberofhour) {
    return numberofhour / 24.0;
}
void printvalue(int numbersofhour, float numbersofdays, float numbersofweeks) {
    cout << "number of hour = " << numbersofhour << endl;
    cout << "number of days = " << numbersofdays << endl;
    cout << "number of weeks = " << numbersofweeks << endl;
}
int main()
{
    float numbersofhour = readpositivenumbers("please enter the numbers of hours : ");
    float numbersofweeks = calculatenumberofweek(numbersofhour);
    float numbersofdays = calculatenumberofdays(numbersofhour);
    printvalue(numbersofhour, numbersofdays, numbersofweeks);
}
        
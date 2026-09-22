// digit frequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int ReadPositiveNumber(string message) {
    int numbers = 0;
    do {
        cout << message << endl;
        cin >> numbers;

    } while (numbers < 0);
    return numbers;
}
int countfrequency(int digittocheck, int number) {
    int remainder = 0, frequncy = 0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        if (remainder == digittocheck) {
            frequncy++;
        }
    }
    return frequncy;
}
int main()
{
    int number = ReadPositiveNumber("please enter the number you need ?");
    int digittocheck = ReadPositiveNumber("please enter the number to check ?");
    cout << "\n digits " << digittocheck << "frequecncy is " << countfrequency(digittocheck, number);
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

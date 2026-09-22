// sum of digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void printsumdigits(int number) {
    int Remainder = 0, sum = 0;
    while (number != 0) {
        Remainder = number % 10;
        number = number / 10;
        sum += Remainder;
        }
    cout << "sum of digits = " << sum;
}




int main()
{
    printsumdigits(ReadPositiveNumber("please enter the positve number ?"));
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

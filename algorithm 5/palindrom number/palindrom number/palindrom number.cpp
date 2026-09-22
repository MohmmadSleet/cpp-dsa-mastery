// palindrom number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int readpositivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;

    } while (number < 0);
        return number;
}
int checkpalindrome(int number) {
    int remainder = 0, number2 = 0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    cout << number2 << endl;
    return number2;
}

bool ispalindrome(int number) {
    return (number==checkpalindrome(number));
}
int main()
{
    
    if (ispalindrome(readpositivenumber("please enter the number ?")))
    cout << "yes the number is palindrome\n";
    else
        cout << "no the number is not palindrome\n";
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

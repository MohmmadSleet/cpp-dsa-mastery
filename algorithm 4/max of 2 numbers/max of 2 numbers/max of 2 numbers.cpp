// max of 2 numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct strnumbers {
    int number1;
    int number2;

};
strnumbers read2numbers() {
    strnumbers numbers;
    cout << "please enter the first number : \n";
    cin >> numbers.number1;
    cout << "pleas enter the second number : \n";
    cin >> numbers.number2;
    return numbers;
}
bool checkof2numbers(strnumbers numbers) {
    if (numbers.number1 > numbers.number2)
        return 1;
    else
        return 0;

}
void printMaxof2numbers(strnumbers numbers) {
    if (checkof2numbers(numbers) == 1)
    cout << numbers.number1 << "the number is max ";
    else
        cout << numbers.number2 << "the number is max ";

}

int main()
{
    printMaxof2numbers(read2numbers());
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

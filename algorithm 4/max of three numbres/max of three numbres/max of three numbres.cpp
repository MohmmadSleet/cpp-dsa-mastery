// max of three numbres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct strnumbers {
    int number1;
    int number2;
    int number3;

};
strnumbers read3numbers() {
    strnumbers numbers;
    cout << "please enter the first number : \n";
    cin >> numbers.number1;
    cout << "pleas enter the second number : \n";
    cin >> numbers.number2;
    cout << "please enter the third number : \n";
    cin >> numbers.number3;
    return numbers;
}
int checkof3numbers(strnumbers numbers) {
    if (numbers.number1 > numbers.number2 && numbers.number1 > numbers.number3)
        return numbers.number1;
    else if (numbers.number2 > numbers.number1 && numbers.number2 > numbers.number3)
        return numbers.number2;
    else
        return numbers.number3;
}
void printMaxof3numbers(strnumbers numbers) {
    if (checkof3numbers(numbers) == numbers.number1)
        cout << numbers.number1 << "  the number is max ";
    else if (checkof3numbers(numbers) == numbers.number2)
        cout << numbers.number2 << "  the number is max ";
    else
        cout << numbers.number3 << "  the number is max";

}

int main()
{
    printMaxof3numbers(read3numbers());
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

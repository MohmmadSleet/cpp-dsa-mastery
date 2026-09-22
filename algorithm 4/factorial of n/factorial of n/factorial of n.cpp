// factorial of n.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int readnumber(string message) {
    int numbers = 0;
    cout << message << endl;
    cin >> numbers;
    return numbers;
}
int calculaterfactorial(int numbers) {
    int factorial = 1;

    for (int counter = 1; counter <= numbers;counter++) {
        factorial = factorial * counter;
    }
    return factorial;
}
void printfactorialfrom1ton(int factorial) {
    cout << "factorial from 1 to n = " << factorial << endl;

}
int main()
{
    printfactorialfrom1ton(calculaterfactorial(readnumber("please enter the number : ")));
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

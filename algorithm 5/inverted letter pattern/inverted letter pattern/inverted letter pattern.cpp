// inverted letter pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int ReadPositivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number < 0);
    return number;
}
void  printinvertednumberpattern(int number) {

    for (int i = 65 +number; i>=65; i--) {

        for (int j = 65; j <= i; j++) {
            cout <<char(i);
        }
        cout << endl;
    }

}
int main()
{
    int number = ReadPositivenumber("please enter the positive number ?");
    printinvertednumberpattern(number);
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

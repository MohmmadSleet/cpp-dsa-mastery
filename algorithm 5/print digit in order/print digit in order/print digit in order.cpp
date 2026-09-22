// print digit in order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int readpositivenumber(string message) {
    int number = 0;
    do{
    cout << message << endl;
    cin >> number;

}while (number < 0);
return number;
}
int reversedigit(int number) {
    int remainder = 0,number2 =0;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
         
        number2 = number2 * 10 + remainder;
    }
    cout << number2;
    return number2;
}
void printdigitinorder(int number) {
    int remainder = 0;
    cout << endl;
    while (number != 0) {
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}
int main()
{
    printdigitinorder(reversedigit( readpositivenumber("please enter the number ? ")));
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

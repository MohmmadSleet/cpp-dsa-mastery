// sum until enter user -99.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

 int readnumbersuntil_99(string message) {
     int sum = 0, numbers = 0;
     do {
         cout << message << endl;
         cin >> numbers;
         if (numbers != -99) {
             sum += numbers;
         }
     } while (numbers != -99);
     return sum;
}
 void printresult(int sum) {
     cout << "sum numbers without -99 = " << sum << endl;
 }
int main()
{
    printresult(readnumbersuntil_99("please enter the number : "));
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

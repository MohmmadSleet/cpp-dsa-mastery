// service fee and sales tax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
float readpositivenumber(string message) {
    float number = 0;
    do {
        cout << message << endl;
        cin >> number;


    } while (number <= 0);
    return number;
}
float calculatebillvalueafterserviceandfee(float billvalue) {
    billvalue = billvalue * 1.1;
    billvalue = billvalue * 1.16;
    return billvalue;

 }
void printbillvalueafteraddserviceandfee(float billvalue) {
    cout << "the value bill after service fee and tax = " << billvalue << endl;
}
int main()
{
    float readbillvalue = readpositivenumber("please enter the bill value : ");
    printbillvalueafteraddserviceandfee(calculatebillvalueafterserviceandfee(readbillvalue));
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

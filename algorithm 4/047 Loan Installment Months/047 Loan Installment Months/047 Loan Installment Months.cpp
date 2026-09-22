// 047 Loan Installment Months.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int readpositivenumber(string message) {
    int numbers = 0;
    do {
        cout << message << endl;
        cin >> numbers;
    } while (numbers <= 0);
    return numbers;
}
float calculatehowmanymonthsyouneed(int loanAmount, int monthlyPayment) {
    return (float)loanAmount / monthlyPayment;
}

void printcalculatehowmanymonthsyouneed(float calculate) {
    cout << "month you need to settle loan = " << calculate;
}
int main()
{
    int loanAmount = readpositivenumber("please enter the loan amount : ");
    int monthlyPayment= readpositivenumber("please enter the monthly payment : ");
    
    printcalculatehowmanymonthsyouneed(calculatehowmanymonthsyouneed(loanAmount, monthlyPayment));
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

// 048 monthly loan installement.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
float calculatehowmanymonthsyouneed(int loanAmount, int numbermonthlyPayment) {
    return (float)loanAmount / numbermonthlyPayment;
}

void printcalculatehowmanymonthsyouneed(float calculate) {
    cout << "month you must to amount = " << calculate;
}
int main()
{
    int loanAmount = readpositivenumber("please enter the loan amount : ");
    int numbermonthlyPayment = readpositivenumber("please enter the number monthly payment : ");

    printcalculatehowmanymonthsyouneed(calculatehowmanymonthsyouneed(loanAmount,numbermonthlyPayment));
}


// piggy bank calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct strcurrency {
    float Pennies, Nickels, Dimes, Quarters, Dollars;
};
strcurrency readallcurrency() {
    strcurrency currency;
    cout << "please enter the currency pennies : \n";
    cin >> currency.Pennies;
    cout << "please enter the currency nickels : \n";
    cin >> currency.Nickels;
    cout << "please enter the currency dimes : \n";
    cin >> currency.Dimes;
    cout << "please enter the currency quartees : \n";
    cin >> currency.Quarters;
    cout << "please enter the currency dollar : \n";
    cin >> currency.Dollars;
    return currency;
}
float calculatortotalpennis(strcurrency currency) {
    return ((currency.Pennies * 1) + (currency.Nickels * 5) + (currency.Dimes * 10) + (currency.Quarters * 25) + (currency.Dollars * 100));
}
void printtotalpennis(float totalpennise) {
    cout << "total pennise = " << totalpennise << endl;
}
int main()
{
    printtotalpennis(calculatortotalpennis(readallcurrency()));
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

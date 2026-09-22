// average of three mark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
enum enpassorfail { pass = 1, fail = 2 };
void readnumbers(int& number1, int& number2, int& number3) {
    cout << "please enter the number 1 : \n";
    cin >> number1;
    cout << "please enter the number 2 : \n";
    cin >> number2;
    cout << "please enter the number 3 : \n ";
    cin >> number3;
}
int sumof3mark(int number1, int number2, int number3) {
    return number1 + number2 + number3;

}
float calculateaverage(int sum) {
    return (float)sum / 3;
}
enpassorfail checkaverage(float calculateaverage) {
    if (calculateaverage >= 50)
        return enpassorfail::pass;
    else
        return enpassorfail::fail;
}
void printresult(float calculateaverage) {
    cout << "\naverage of three marks = " << calculateaverage << endl;
    if (checkaverage(calculateaverage) == enpassorfail::pass)
        cout << "pass\n";
    else
        cout << "fail\n";
}
int main()
{
    int number1, number2, number3;
    readnumbers(number1, number2, number3);
    printresult(calculateaverage(sumof3mark(number1, number2, number3)));
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

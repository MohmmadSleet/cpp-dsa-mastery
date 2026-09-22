// check even or odd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enoddoreven{odd=1,even=2};
int readnumbertype(string message) {
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}
enoddoreven checknumbertype(int number) {
    int result = 0;
    result = number % 2;
    if (result == 0)
        return enoddoreven::even;
    else
        return  enoddoreven::odd;
}
void printnumbertype(int number) {
    if (checknumbertype(number) == enoddoreven::odd)
        cout << number << " \a    is odd";
    else
        cout << number << "    not odd";
}

int main()
{
    printnumbertype(readnumbertype("please enter the number :"));
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

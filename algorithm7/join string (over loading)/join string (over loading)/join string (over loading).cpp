// join string (over loading).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(string arr1[3], short Row, string delim) {
    string S1 = " ";
    for (short i = 0; i < Row; i++) {
        S1 = S1 + arr1[i] + delim;
    }
    return S1.substr(0, S1.length() - delim.length());
}
string JoinString(vector<string> vString, string delim) {
    string S1 = " ";
    for (string& s : vString) {
        S1 = S1 + s + delim;
    }
    return S1.substr(0, S1.length() - delim.length());
}
int main()
{
   

    string arr1[4] = { "mohmmad ","sleet","ahmad","jafar" };
    vector<string>vString = { "Mohmmad","sleet","ahmad","jafar" };
    cout << "\nArray after join string : \n";
    cout << JoinString(arr1, 3, "##");
    cout << "\nvector after join string : \n";
    cout << JoinString(vString, "##");
    return 0;
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

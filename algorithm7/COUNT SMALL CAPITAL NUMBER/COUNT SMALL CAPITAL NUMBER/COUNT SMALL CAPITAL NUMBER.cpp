// COUNT SMALL CAPITAL NUMBER.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;
string ReadString() {
    string str;
    cout << "please enter the string ?\n";
    getline(cin, str);
    return str;
}
int  CountCapitalLetter(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            count++;
        }
    }
    return count;
}
int CountSmallLetter(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (islower(str[i])) {
            count++;
        }
    }
    return count;
}
int main()
{
    string str = ReadString();

    cout << "\n\nLength Sting " << str.length();
    cout<<"\nCount Capital Letter : "<< CountCapitalLetter(str);
    cout << "\nCount Small Letter : " << CountSmallLetter(str);


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

// count vowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;
string ReadString() {
    string str;
    cout << "please enter the string ? \n";
    getline(cin, str);
    return str;
}
bool IsVowel(char C1) {
    C1 = tolower(C1);
    return(C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
}
int CountVowelsInString(string str) {
    
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (IsVowel(str[i]))
            count++;
    }
    return count;
}
int main()
{
    string str = ReadString();
    cout << "Number of vowels is : " << CountVowelsInString(str);
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

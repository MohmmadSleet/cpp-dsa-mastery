// Is vowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
char ReadChar() {
    char C1;
    cout << "please enter the cahracter ?\n";
    cin >> C1;
    return C1;
}
bool IsVowel(char C1) {
    C1 = tolower(C1);
    switch (C1)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return true;
    default:
        return false;

    }
}
int main()
{
    char C1 = ReadChar();
    
    if (IsVowel(C1) == true)
        cout << "Yes Letter " << C1 << " is vowel .";
    else
        cout << "No Letter '" << C1 << "'  isn't vowel .";
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

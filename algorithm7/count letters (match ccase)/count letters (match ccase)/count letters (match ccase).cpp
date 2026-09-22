// count letters (match ccase).cpp : This file contains the 'main' function. Program execution begins and ends there.
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
char ReadChar() {
    char C1='a';
    cout << "please etner the char ?\n";
    cin >> C1;
    return C1;
}
int CountCharInString(string str, char C1) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == C1)
            count++;
    }
    return count;
}
char Inverteletter(char C1) {

    return(isupper(C1) ? tolower(C1) : toupper(C1));
}
int CountCharInString2(string str, char C1,char C2) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == C1||str[i]==C2)
            count++;
    }
    return count;
}

int main()
{
    string str = ReadString();
    char C1 = ReadChar();
    char C2 = Inverteletter(C1);
    cout << "\nLetter " << C1 << "  Count = " << CountCharInString(str, C1);
    cout << "\nLetter " << C1 << "  Or  " << C2 << "  =  " << CountCharInString2(str, C1, C2);

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

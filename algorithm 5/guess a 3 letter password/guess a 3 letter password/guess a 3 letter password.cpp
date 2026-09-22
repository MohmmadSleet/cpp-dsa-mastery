// guess a 3 letter password.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<string>
using namespace std;

string ReadPassword() {
    string password;
    cout << "please enter the password\n";
    cin >> password;
    return password;
}
bool GuessPassword(string originalpassword) {
    int counter = 0;
    string word = "";
    cout << "\n";
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                counter++;
                cout << "Trial[" << counter << "] :";
                cout<< word << endl;
                    if (word == originalpassword) {
                        cout << "password is = " << word << endl;
                        cout << "found after" << counter << endl;
                        return true;
                    }
                word = "";
            }
        }
    }
    return false;
}

int main() {
    GuessPassword(ReadPassword());
    return 0; }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

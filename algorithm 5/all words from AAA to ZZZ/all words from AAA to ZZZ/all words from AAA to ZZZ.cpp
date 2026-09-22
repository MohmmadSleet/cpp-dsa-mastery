// all words from AAA to ZZZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void PrintWordsFromAAAtoZZZ() {
    string word;

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                cout << word << endl;
                word = " ";
            }
        }
        cout << "\n---------------------------------------------\n";
    }
}
int main()
{
    PrintWordsFromAAAtoZZZ();
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

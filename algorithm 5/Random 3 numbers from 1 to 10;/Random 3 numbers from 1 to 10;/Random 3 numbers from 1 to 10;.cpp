// Random 3 numbers from 1 to 10;.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;

int RandomNumber(int From, int To) {

    int randnum = rand() % (To - From + 1)+From;
    return randnum;
}

int main()
{
    srand((unsigned)time(NULL));
    /*srand((unsigned)time(NULL));
    cout << rand()%10 << endl;
    cout << rand()%10 << endl;
    cout << rand()%10<< endl;*/

    cout << RandomNumber(20, 22) << endl;
    cout << RandomNumber(20, 50) << endl;

    cout << RandomNumber(20, 50) << endl;

    
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

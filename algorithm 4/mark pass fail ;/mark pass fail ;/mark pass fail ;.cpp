// mark pass fail ;.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enresultmark { pass = 1  ,  fail= 2 };

int ReadMark(string message) {
    int Mark=0;
    cout << message << endl;
    cin >> Mark;
    return Mark;

}
 enresultmark checkMark(int Mark) {
     if (Mark >= 50)
         return enresultmark::pass;
     else
         return enresultmark::fail;
}
void printResultMark(int Mark ) {
    if(checkMark(Mark)==enresultmark::pass )
        cout<<Mark<<"the student mark :pass";
    else
        cout<<Mark<<"the studen mark :fail";

}
int main()
{
    printResultMark(ReadMark("please enter the mark : "));
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

// fill array with random numbers from 1 to 100.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;
int Randomnumber(int from,int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;

}
void fillarray(int arr[100], int& arrlength) {
    cout << "enter the arr length\n";
    cin >> arrlength;
    for (int i = 0; i < arrlength; i++) {
        arr[i] = Randomnumber(1, 100);

    }
}

void printarr(int arr[100], int arrlength) {
    cout << "Array Element : ";
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrlength;
    fillarray(arr, arrlength);
    printarr(arr, arrlength);
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

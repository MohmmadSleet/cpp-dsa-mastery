// return number index in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int ReadPositiveNumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int RandomNumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}

void fillthearray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}
void printarray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << "  ";
    }
}
bool   arelookingnumber(int numberyoulook, int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        if (arr[i] == numberyoulook) {
            return true;
        }

    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arrlength = ReadPositiveNumber("\n How many arr length you need \n");
    int arr[100];
    cout << "\nArray 1 Elements : \n";
    fillthearray(arr, arrlength);
    printarray(arr, arrlength);
    int numberyoulook = ReadPositiveNumber("\n pleas enter the number you to serach ?\n ");

    if (arelookingnumber(numberyoulook, arr, arrlength) == true){
        cout << "\n Number you are looking for is : " << numberyoulook << endl;
    cout << "yes , the number is found (0";
}
    else {
        cout << "\n Number you are looking for is : " << numberyoulook << endl;
        cout << "No , the number it not found =(/0 ";
    }
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

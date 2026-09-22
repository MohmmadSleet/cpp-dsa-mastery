// copy array in reverse order.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int Randomnumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}

void fillthearray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arr[i] = Randomnumber(1, 100);
    }
}
void PrintReversenumber(int number) {
    int Remainde = 0, number2 = 0;
    while (number != 0) {
        Remainde = number % 10;
        number = number / 10;
        number2 = number2 * 10 + Remainde;
    }
    cout << number2<<" ";
}
void  arrayafterreverse(int arr[100],int arr2[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arr2[i] = (arr[arrlength - 1 - i]);
    }
}
void printarray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{  
    int arr[100],arr2[100], arrlength;
    arrlength = ReadPositiveNumber("pleass enter the arr length");
    fillthearray(arr, arrlength);
    cout << "\nArray 1 Elements : \n";
    printarray(arr, arrlength);
    cout << "\narray 2 elements after copy array 1 revers array :\n ";
    arrayafterreverse(arr,arr2, arrlength);
    printarray(arr2, arrlength);
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

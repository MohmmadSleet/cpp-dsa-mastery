// copy odd numbers to a new array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;
int randnumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}
void fillarraywithrandomnumber(int arr[100],int& arrlength) {
    cout << "enter array elements :\n";
    cin >> arrlength;

    for (int i = 0; i < arrlength; i++) {
        arr[i] = randnumber(1, 100);
    }
}
void addarrayelement(int number, int arr[100], int& arrlength2) {
    arrlength2++;
    arr[arrlength2 - 1] = number;
}
void copyoddnumberwitharray(int arr[100], int arr2[100], int arrlength, int& arrlength2)
{
    for (int i = 0; i < arrlength; i++) {
        if (arr[i] % 2 != 0)
            addarrayelement(arr[i], arr2, arrlength2);
    }
}

void printarray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[100],arr2[100],arrlength=0,arrlength2=0;
    
    fillarraywithrandomnumber(arr, arrlength);
    copyoddnumberwitharray(arr, arr2, arrlength, arrlength2);
    cout << "array 1 element : \n";
    printarray(arr, arrlength);
    cout << "\narray 2 element odd : \n";
    printarray(arr2, arrlength2);

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

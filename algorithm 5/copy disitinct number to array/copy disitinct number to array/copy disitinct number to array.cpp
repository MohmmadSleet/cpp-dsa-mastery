// copy disitinct number to array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fillArraay(int arr[100], int& arrlength) {
    
    arrlength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void printarray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << "  ";
    }
}
void addarrayelemnte(int number, int arr2[100], int& arrlength2) {
    arrlength2++;
    arr2[arrlength2 - 1] = number;
}
short  FindNumberPositionInArray(int number, int arr2[100], int& arrlength2) {
    for (int i = 0; i < arrlength2; i++) {
        if (arr2[i] == number)
            return i;
    }
    return -1;
}

bool IsNumberInarray(int number, int arr2[100], int& arrlength2) {
    return FindNumberPositionInArray(number, arr2, arrlength2) !=-1 ;
}
void copydistinctnumberstoarray(int arr[100], int arr2[100], int arrlength, int& arrlength2) {
    for (int i = 0; i < arrlength; i++) {
        if (!IsNumberInarray(arr[i], arr2, arrlength2)) {
            addarrayelemnte(arr[i], arr2, arrlength2);
        }
    }
}

int main()
{
    int arr[100], arr2[100], arrlength = 0, arrlength2 = 0;
    fillArraay(arr, arrlength);
    cout << "\n Array 1 Element : \n";
    printarray(arr, arrlength);
    copydistinctnumberstoarray(arr, arr2, arrlength, arrlength2);

    cout << "\nArray 2 elements after distinct :\n";
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

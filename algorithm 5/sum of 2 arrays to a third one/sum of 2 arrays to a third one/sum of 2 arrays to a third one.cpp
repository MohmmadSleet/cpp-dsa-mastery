// sum of 2 arrays to a third one.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int ReadPositienumber(string message) {
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

void  fillvaluearray(int arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arr[i] = Randomnumber(1, 100);
    }
}
void     printarrayvalue(int arr1[100], int  arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arr1[i] << " ";
    }
}
void  sumarray(int arr1[100], int arr2[100], int arrsum[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arrsum[i] = arr1[i] + arr2[i];
    }
}
void printsumarray(int arr1[100], int arr2[100], int arrsum[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << arrsum[i] << "  ";
    }
}
int main()
{
    int arr1[100], arr2[100], arrsum[100];
    int arrlength = ReadPositienumber("please enter the positive number \n");
     
    fillvaluearray(arr1, arrlength);
    fillvaluearray(arr2, arrlength);
    cout << "\nArray 1 Elements : \n";
    printarrayvalue(arr1, arrlength);
    cout << "\nArray 2 Elements : \n";
    printarrayvalue(arr2, arrlength);
    cout << "\nsum of array1 and array 2 elements : \n";
    sumarray(arr1,arr2,arrsum, arrlength);
    printsumarray( arr1, arr2, arrsum, arrlength);
    return 0;

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

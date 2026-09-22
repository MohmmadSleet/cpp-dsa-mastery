// sum of random array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;
int RandomNumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + 1;
    return randnum;

}
void Readarr(int arr[100], int& arrlength) {
    cout << "please entr the arr length ?\n";
    cin >> arrlength;
    for (int i = 0; i < arrlength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}
void printarr(int arr[100], int arrlength) {
    cout << "array value = ";
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sumofrandomarray(int arr[100], int arrlength) {
    int sum = 0;
    ;
    for (int i = 0; i < arrlength; i++) {
        sum = sum + arr[i];
    }
    cout << "the sum value : " << sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrlength;
    Readarr(arr, arrlength);
    printarr(arr, arrlength);
    sumofrandomarray(arr, arrlength);
}
// min of random array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;
int RandomNumber(int from,int to) {
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
        cout << arr[i]<<" ";
    }
    cout << endl;
}
void minofrandomarray(int arr[100],int arrlength) {
    int min = 0;
    min = arr[0];
    for (int i = 0; i < arrlength; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "the min value : " << min;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrlength;
    Readarr(arr, arrlength);
    printarr(arr, arrlength);
    minofrandomarray(arr, arrlength);
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

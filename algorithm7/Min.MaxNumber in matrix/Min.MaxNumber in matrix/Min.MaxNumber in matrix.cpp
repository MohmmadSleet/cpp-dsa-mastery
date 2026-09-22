// Min.MaxNumber in matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;

void PrintMatrices(int arr[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            cout <<setw(3)<< arr[i][j] << "      ";
        }
        cout << endl;
    }
}
void PrintMaxNumber(int arr[3][3], int Row, int Colume) {
    int numberMaxium = arr[0][0];
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            if (arr[i][j] > numberMaxium) {
                numberMaxium = arr[i][j];
            }
        }    
    }
    cout << "Max Number = " << numberMaxium << endl;
}
void PrintMinumNumber(int arr[3][3], int Row, int Colume) {
    int numberMinum = arr[0][0];
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            if (arr[i][j] < numberMinum) {
                numberMinum = arr[i][j];
            }
        }
    }
    cout << "Minum Number = " << numberMinum << endl;
}
int main()
{
    int arr[3][3]{ {1,2,3},{421,12,4},{100,40,20} };
    printf("The Matrix 1 = \n");
    PrintMatrices(arr, 3, 3);
    PrintMaxNumber(arr, 3, 3);
    PrintMinumNumber(arr, 3, 3);
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

// Palindrome Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
void PrintMatrix(int arr[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            cout << arr[i][j] << "    ";
        }
        cout << endl;
    }
}
bool IsPalindromeMatrix(int arr1[3][3], int Row, int Colume) {
    for (short i = 0; i < Row; i++) {
        for (short j = 0; j < Colume; j++) {
            if (arr1[i][j] != arr1[i][Colume - 1 - j])
                return false;
        }
    }
    return true;
}
int main()
{
    int arr1[3][3] = { {1,1,1},{4,1,4},{7,7,7} };
        
    cout << "The Matrix = " << endl;
    PrintMatrix(arr1, 3, 3);
    if (IsPalindromeMatrix(arr1, 3, 3) == true) {
        cout << "\nYes,The Matrices is palindrome .";

    }
    else {
        cout << "\nNo,The Matrice is not palindrome . ";
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

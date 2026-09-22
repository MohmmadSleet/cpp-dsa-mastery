// intersected number in matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;
void PrintMatrix(int arr1[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            cout <<setw(3)<< arr1[i][j] << "     ";
        }
        cout << endl;
    }
}
bool IsNumberintersected(short Number, int arr2[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            if (arr2[i][j] == Number)
                return true;
        }
    }
    return false;
}
void     PrintIntersetedNumber(int arr1[3][3], int arr2[3][3], int Row, int colume) {
    cout << "the Number intersected in matrices \n";
   
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colume; j++) {
            int number = arr1[i][j];
            if (IsNumberintersected(number, arr2, 3, 3) == true)
                cout << arr1[i][j] << "     ";
        }
       
    }
}

int main()
{
    int arr1[3][3]{ {12,14,32},{1,4,8},{7,5,3} };
    int arr2[3][3]{ {1,7,9}, {15,14,12},{5,3,1 } };
    cout << "Matrix 1 = \n";
    PrintMatrix(arr1, 3, 3);
    cout << "Matrix 2 = \n";
    PrintMatrix(arr2, 3, 3);
    PrintIntersetedNumber(arr1, arr2, 3, 3);

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

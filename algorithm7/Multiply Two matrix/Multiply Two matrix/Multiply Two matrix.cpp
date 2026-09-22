// Multiply Two matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;
int RAdnomNumber(int FRom, int To) {
    int RandNum = rand() % (To - FRom + 1) + FRom;
    return RandNum;
}
void FillArrayWithRandomNumber(int arr1[3][3], int arr2[3][3], short Row, short colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            arr1[i][j] = RAdnomNumber(1, 10);
            arr2[i][j] = RAdnomNumber(1, 10);
        }
    }

}
void PrintArrayWithRandomNumber(int arr[3][3], int Row, int Colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colum; j++) {
            cout << setw(3) << arr[i][j] << "         ";
        }
        cout << endl;
    }
}
void DivideMatrix1And2(int arr1[3][3], int arr2[3][3],int arrDivideMatrix[3][3], int Row, int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            arrDivideMatrix[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}
void     PrintDivideMatrix1And2(int arrDivideMatrix[3][3], int Row, int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << setw(3) << arrDivideMatrix[i][j] << "         ";

            
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3],arrDivideMatrix[3][3];
    FillArrayWithRandomNumber(arr1, arr2, 3, 3);
    cout << " Matrix 1 : " << endl;
    PrintArrayWithRandomNumber(arr1, 3, 3);
    cout << " Matrix 2 : " << endl;
    PrintArrayWithRandomNumber(arr2, 3, 3);

    DivideMatrix1And2(arr1, arr2,arrDivideMatrix ,3, 3);
    cout << "Result = " << endl;
    PrintDivideMatrix1And2(arrDivideMatrix, 3, 3);
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

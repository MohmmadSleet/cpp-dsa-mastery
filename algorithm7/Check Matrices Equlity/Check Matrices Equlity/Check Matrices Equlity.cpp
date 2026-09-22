// Check Matrices Equlity.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillarrayWithRandomNumber(int arr1[3][3], int arr2[3][3], int Row, int Colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colum; j++) {
            arr1[i][j] = RandomNumber(1,3);
            arr2[i][j] = RandomNumber(1, 3);
        }
    }
}
void PrintMatrix1(int arr1[3][3], int Row, int Cloume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Cloume; j++) {
            printf("   %0*d     ", 2, arr1[i][j]);
           
        }
        cout << endl;
    }
}
int SumArray1(int arr1[3][3], int Row, int colume) {
    int sum = 0;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colume; j++) {
            sum += arr1[i][j];
        }
    }
    cout << "Sum Matrix 1 = " << sum<<endl;

    return sum;
}
int SumArray2(int arr2[3][3], int Row, int colume) {
    int sum = 0;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colume; j++) {
            sum += arr2[i][j];
        }
    }
    cout << "Sum Matrix 2 = " << sum<<endl;
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3];
    FillarrayWithRandomNumber(arr1, arr2, 3, 3);
    printf("   Matrix 1   :  \n");
    PrintMatrix1(arr1, 3, 3);
    printf("\n   Matrix 2   :  \n");
    PrintMatrix1(arr2, 3, 3);

    
    if (SumArray1(arr1,3,3) == SumArray2(arr2,3,3)) 
        cout << "\nYes , Matrices is equal .\n";
    else 
        cout << "\nNo ,Matrices is Not Equal  .\n";
    
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

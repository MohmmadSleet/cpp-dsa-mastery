// Sum Each Colum in matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;
int RAndomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillarraywithRandomNumber(int arr[3][3],int Row,int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            arr[i][j] = RAndomNumber(1, 100);
        }
    }
}
void PrintArrayWithRandomNumber(int arr[3][3], int Row, int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            cout <<setw(3)<< arr[i][j] << "      ";
        }
        cout << endl;
    }
}
int SumColums(int arr[3][3], int Row, int NumberColums) {
    int sum = 0;
    for (int j = 0; j <= Row - 1; j++) {
        sum += arr[j][NumberColums];
    }
    return sum;
}
void PrintSumColums(int arr[3][3], int Row, int colum) {
    for (int i = 0; i < colum; i++) {
        
            cout << "The Sum colum " << i + 1 << "  =  " << SumColums(arr, Row, i) << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];
    FillarraywithRandomNumber(arr, 3, 3);
    cout << "The array 3*3 Matrix = \n";
    PrintArrayWithRandomNumber(arr, 3, 3);
    PrintSumColums(arr, 3, 3);

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

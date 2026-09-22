// Sum Each Colum in matrix in another array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillArrayWithRandomNumber(int arr[3][3],int Row,int colums) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colums; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintArrayWithRandomNumber(int arr[3][3], int Row, int colums) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colums; j++) {
            cout <<setw(3)<< arr[i][j] << "        ";
        }
        cout << endl;
    }
}
int SumColums(int arr[3][3], int Row, int Numbercolums) {
    int sum = 0;
    for (int i = 0; i <= Row - 1; i++) {
        sum += arr[i][Numbercolums];
    }
    return sum;
}
void StorgeSumColumNumberInAraay(int arr[3][3], int arrSum[3], int Row, int Colums) {
    for (int i = 0; i < Colums; i++) {
        arrSum[i] = SumColums(arr, Row, i);
    }
}
void PrintSumRandomNumber(int arrSum[3], int Colum) {
    for (int i = 0; i < Colum; i++) {
        cout << "The Sum Colum " << i + 1 << " = " << arrSum[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];
    FillArrayWithRandomNumber(arr, 3, 3);
    cout << "The Matrix 3*3 = \n";
    PrintArrayWithRandomNumber(arr, 3, 3);
    StorgeSumColumNumberInAraay(arr, arrSum, 3, 3);
    PrintSumRandomNumber(arrSum, 3);
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

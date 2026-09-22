// PrintMiddle Row and colum of matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void  fillarraywithRandomNumber(int arr1[3][3], int Row, int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            arr1[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintTheValue(int arr1[3][3], int Row, int colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            printf("     %0*d    ", 2, arr1[i][j]);
        }
        printf("\n");
    }
}
void   PrintMiddleRowOfMatrix(int arr1[3][3], int Row, int Columes) {
    short MiddleRow = Row / 2;
        for (int j = 0; j < Columes; j++) {
            printf("     %0*d    ", 2, arr1[MiddleRow][j]);
        }
}
void   PrintMiddlecolumeOfMatrix(int arr1[3][3], int Row, int Columes) {
    short MiddleColum = Columes / 2;
    for (int i = 0;i<Row;i++) {
        
            printf("     %0*d    ", 2, arr1[i][MiddleColum]);
            
        }
        
    }



int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];
    fillarraywithRandomNumber(arr1, 3, 3);
    printf("The Matrix 3*3 = \n");
    PrintTheValue(arr1, 3, 3);
    printf(" Print Middle Row Of Matrix : \n");
    PrintMiddleRowOfMatrix(arr1, 3, 3);
    printf("\n Print Middle colume Of Matrix : \n");
    PrintMiddlecolumeOfMatrix(arr1, 3, 3);

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

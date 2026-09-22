// sum each row in matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<String>
#include<cstdlib>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillArrWithRandomNumber(int arr[3][3],short Row,short colum){
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            arr[i][j] = RandomNumber(0, 100);
        }
    }

}
void PrintArrMatrix(int arr[3][3], short Row, short colum) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3],short i,short colum) {
    int sum = 0;
    for (int j = 0; j < colum; j++) {
        sum += arr[i][j];

    }
    return sum;

}
void PrintTheSumOfEachMatrix(int arr[3][3], short Row, short colum) {
    for (int i = 0; i < Row; i++) {
         
        cout << "Row   " << i + 1<< "    Sum = " << RowSum(arr, i, colum) << endl;
        
    }
}
int main()
{

    srand((unsigned)time(NULL));
    int arr[3][3];

    FillArrWithRandomNumber(arr, 3, 3);
    cout << "The Follwing MAtrix 3*3 : \n";
    PrintArrMatrix(arr, 3, 3);
    cout << "\nThe Sum of each row in the matrix : \n";
    PrintTheSumOfEachMatrix(arr,3,3);
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

// Count Number in matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int arr[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}
void  PrintArrayWithRandomNumber(int arr[3][3], int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            printf("    %0*d    ", 2, arr[i][j]);
        }
        cout << endl;
    }
}
short     ReadTheNumberToCountTheNumberInMatrix(string Text) {
    int number = 0;
    do {
        cout << Text << endl;
        cin >> number;
    } while (number > 10 || number < 1);
    return number;
}
 void checkTheNumberHowManyCount(short Number, int arr[3][3], int Row, int Colume) {
    short count = 0;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            if (Number == arr[i][j])
                count++;
        }
    }
    cout << "Number " << Number << "  Count in matrix : " << count << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillArrayWithRandomNumber(arr, 3, 3);
    cout << "the Matrices 1 = \n ";
    PrintArrayWithRandomNumber(arr, 3, 3);
   short Number = ReadTheNumberToCountTheNumberInMatrix("Enter The Number To Count in Matrix ? ");
   checkTheNumberHowManyCount(Number, arr, 3, 3);
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

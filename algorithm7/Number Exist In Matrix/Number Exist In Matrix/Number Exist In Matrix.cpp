// Number Exist In Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;
int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillArrayWithRandomNumber(int arr[3][3], int Row, int Colume)
{
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintTheMatrix(int arr[3][3], int Row, int Colume) {

    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            printf("   %d  ", arr[i][j]);
        }
        cout << endl;
    }
}
bool ISNumberInMatrix(int arr[3][3], int Number, int Row, int Colume) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Colume; j++) {
            if (arr[i][j] == Number)
                return true;
        }
    }
    return false;
}
 int main()
{
        srand((unsigned)time(NULL));
    int arr[3][3];
    FillArrayWithRandomNumber(arr, 3, 3);
    cout << "The MAtrix = \n";
    PrintTheMatrix(arr, 3, 3);
    int Number = 0;
    cout << "Please enetre the number to check ? \n";
    cin >> Number;
    if (ISNumberInMatrix(arr, Number, 3, 3)) {
        cout << "\n Yes, it is there.";
    }
    else
        cout << "\nNo, it isn't there .";
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

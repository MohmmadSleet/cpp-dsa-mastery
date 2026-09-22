// Check Sparse Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void PrintMatrix(int arr[3][3],int Row,int Colume) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colume; j++) {
			printf("  %0*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}

}
 int CheckHowManyValue0InMatrix(int arr[3][3], int Row, int Colume) {
	 short count = 0;
	 for (int i = 0; i < Row; i++) {
		 for (int j = 0; j < Colume; j++) {
			 if (arr[i][j] == 0)
				 count++;
		 }
	 }
	 cout << "\n Value 0 In Matrix = " << count;
	 return count;
}
 int HowManyValueWithout0InMatrix(int arr[3][3], int Row, int Colume) {
	 short count = 0;
	 for (int i = 0; i < Row; i++) {
		 for (int j = 0; j < Colume; j++) {
			 if (arr[i][j] != 0)
				 count++;
		 }
	 }
	 cout << "\n Value Not 0 In Matrix = " << count;

	 return count;
 }

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3]{ {1,0,0},{0,1,0},{0,0,1} };
	cout << "The MAtrices 1 = \n";
	PrintMatrix(arr, 3, 3);
	short ZerosinArray = CheckHowManyValue0InMatrix(arr, 3, 3);
	short NumberWithoutZeros= HowManyValueWithout0InMatrix(arr, 3, 3);
	if (ZerosinArray > NumberWithoutZeros)
		cout << "\nYes, Its sparse";
	else
		cout << "\nNo, Its Not sparse";

	return 0;
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

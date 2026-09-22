// check typical matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillArrayWithRandomNumber(int arr1[3][3],int arr2[3][3], int Row, int Colum) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colum; j++) {
			arr1[i][j] = RandomNumber(1, 10);
			arr2[i][j] = RandomNumber(1, 10);

		}
	}
}
void PrintArrayWithRandomNumber(int arr1[3][3], int Row, int Colum) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colum; j++) {
			printf("  %0*d   ", 2, arr1[i][j]);

		}
		cout << endl;
	}
}
bool CheckArrayIsTypical(int arr1[3][3], int arr2[3][3], int Row, int colum) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colum; j++) {
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
	
}
int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3],arr2[3][3];
	FillArrayWithRandomNumber(arr1,arr2, 3, 3);
	printf("The Matrices 1 = \n");
	PrintArrayWithRandomNumber(arr1, 3, 3);
	printf("The Matrices 2 = \n");
	PrintArrayWithRandomNumber(arr2, 3, 3);
	
	if (CheckArrayIsTypical(arr1,arr2,3,3) == true) {
		printf("\n Yes , Matrices is Typical  \n");

	}
	else {
		printf("\n no , Matrices is not Typical  \n");

	}


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

// check scalar matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintArrayMatrix(int arr[3][3], int Row, int colume) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colume; j++) {
			printf("   %0*d  ", 2, arr[i][j]);
		}
		cout << endl;
	}

}
bool CheckScalarMatrix(int arr[3][3], int Row, int colume) {
	int FirsDiagonl = arr[0][0];
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colume; j++) {
			if (i == j && arr[i][j] != FirsDiagonl) {
				return false;

	}
	else if(i!=j && arr[i][j]!=0)
	{
		return false;
	}
		}
	}
	return true;
}
int main()
{
	int arr[3][3]{ {1,0,0},{0,2,0},{0,0,1} };
	
	printf("The MAtrix 1 = \n");
	PrintArrayMatrix(arr, 3, 3);
	if (CheckScalarMatrix(arr, 3, 3) == true) {
		printf("yes , the matrix is Scalar");

	}
	else
		printf("NO,The Matrix is not scalar");

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

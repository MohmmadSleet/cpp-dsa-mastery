// Check Identity Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;

void PrintMatrix(int Matrix[3][3], int Row, int Colume) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colume; j++) {
			printf("     %d       ", Matrix[i][j]);
		}
		cout << endl;
	}
}
bool CheckIdentityMatrice(int Matrix[3][3], int Row, int colume) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colume; j++) {
			if (i == j && Matrix[i][j] != 1) {
				return false;
			}
			else if(i!=j  && Matrix[i][j] != 0) {
						return false;
				}
				}
			}
	return true;
		}
	
	

int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3]{ {1,5,7},{0,1,0}, {0,0,1} };
	cout << "The Matrix = \n";
	PrintMatrix(Matrix, 3, 3);
	if (CheckIdentityMatrice(Matrix, 3, 3) == true)
		cout << "Yes, matrice is identity\n";
	else
		cout << "\nNo,matrices is not identity\n";
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

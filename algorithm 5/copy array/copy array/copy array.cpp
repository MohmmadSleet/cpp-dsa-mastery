// copy array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;
int RandomNumber(int from, int to) {
	int Randnum = rand() % (to - from + 1) + from;
	return Randnum;
}
void FillReadArray(int arr[100], int& arrlength) {
	cout << "enter the number element\n";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++) {
		arr[i] = RandomNumber(1, 100);
	}

}

void printArray(int arr[100], int arrlength) {
	cout << "array 1 elements = ";
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
}
void copyarray(int arr[100],int arr2[100], int arrlength) {
	cout << "array 2 elements = ";
	for (int i = 0; i < arrlength; i++) {
		arr2[i] = arr[i];
	}
	for (int i = 0; i < arrlength; i++) {
		cout << arr2[i] << "  ";
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	FillReadArray(arr, arrlength);
	printArray(arr, arrlength);
	int arr2[100];
	copyarray(arr,arr2, arrlength);
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

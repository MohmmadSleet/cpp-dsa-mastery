// shuffle ordered array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int ReadPositiveNumber(string message) {
	int numbers = 0;
	do {
		cout << message << endl;
		cin >> numbers;
	} while (numbers <= 0);
	return numbers;
}
void swap(int& A, int& B)
{
	int Temp;
	Temp = A;
	A = B;
	B = Temp;
}
int RandomNumbers(int from, int to) {
	int Randnum = rand() % (to - from + 1) + from;
	return Randnum;
}
void fillthearray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		arr[i] = i+1;
	}

}
void shuffleArray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		swap(arr[RandomNumbers(1, arrlength) - 1], arr[RandomNumbers(1, arrlength) - 1]);
	}

}
void printarray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	arrlength = ReadPositiveNumber("please enter arr length");
	fillthearray(arr, arrlength);
	cout << "Array Elements befoe shhuffle :\n";
	printarray(arr, arrlength);
	shuffleArray(arr, arrlength);
	cout << "\nArray Elements after shhuffle :\n";
	printarray(arr, arrlength);
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

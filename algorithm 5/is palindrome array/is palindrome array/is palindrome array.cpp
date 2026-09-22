// is palindrome array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<iostream>

using namespace std;
void fillarray(int arr[100], int& arrlength) {
	arrlength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;

}
void printarray(int arr[100], int arrlengtth) {
	for (int i = 0; i < arrlengtth; i++)
		cout << arr[i] << "  ";
}

bool ispalindromenumber(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		if (arr[i] != arr[arrlength - i - 1])
			return false;
		
	}
	return true;
	
}
int main() {
	int arr[100], arrlength;
	fillarray(arr, arrlength);
	cout << "\nArray element  : \n";
	printarray(arr, arrlength);
	if (ispalindromenumber(arr, arrlength))
		cout << "\nyes it is palidrome \n";
	else
		cout << "\nno it isn't palindrome\n";
	return 0;
}
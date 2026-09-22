// ٌrevision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
using namespace std;
void fillarray(int arr[100], int& arrlength) {
	cout << "please ente the length array ?";
	cin >> arrlength;
	cout << "please enter array element : \n";
	for (int i = 0; i < arrlength; i++) {
		
		cin >> arr[i];
	}
}

void printarray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << "  ";
	}
}
bool ispalindrome(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		if (arr[i] != arr[arrlength - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	
	int arr[100], arrlength;
	fillarray(arr, arrlength);

	cout << "Array 1 element :\n";
	printarray(arr, arrlength);

	if (ispalindrome(arr,arrlength) == true)
	{
		cout << "yes ,the array is palindrome";
	}
	else {
		cout << "no the array isn't palindrome";
	}
	return 0;
}
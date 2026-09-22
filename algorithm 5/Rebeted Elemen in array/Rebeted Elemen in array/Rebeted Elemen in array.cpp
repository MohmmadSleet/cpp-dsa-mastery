// Rebeted Elemen in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}
void ReadArr(int arr[100], int& arrlength) {
	cout << "\nEnter number elements ?\n";
	cin >> arrlength;
	cout << "enter value array ?"<<endl;
	for (int i = 0; i < arrlength; i++) {
		cout << "Element[" << i + 1 << "] : ";
		cin >> arr[i];
	}

}
void printArr(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int TimeRepeter(int number, int arr[100], int arrlength) {
	int count = 0;
	for (int i = 0; i < arrlength; i++) {
		if (number == arr[i])
			count++;
	}
	return count;
}
int main() {
	int arr[100], arrlength, numbertocheck;
	ReadArr(arr, arrlength);
	numbertocheck = ReadPositiveNumber("please enter the number you need to check : ");

	cout << "\nOriginal array = ";
     printArr(arr, arrlength);
	 cout << numbertocheck << " is Repeted ";
	 cout<<TimeRepeter(numbertocheck, arr, arrlength);


	return 0;
}
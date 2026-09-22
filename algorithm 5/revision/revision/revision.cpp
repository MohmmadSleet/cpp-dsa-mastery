// revision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int RandomNumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillarraywithrandomnumber(int arr[100], int & arrlength) {
	cout << "\nenter number array element\n :";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++) {
		arr[i] = RandomNumber(1, 100);
	}
}
void printarray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";
	}
}
int sumnumber(int arr[100], int arrlength) {
	int sum = 0;
	;
	for (int i = 0; i < arrlength; i++) {
		sum = sum + arr[i];
	}
	cout << "\nsum = \n" << sum;
	return sum;
}
void printaverage(int sum, int arrlength) {
	cout << "\naverage = " << (sum / arrlength) << endl;
}
void copyarray(int arr[100], int arr2[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		arr2[i] = arr[i];
	}
}
int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrlength;
	fillarraywithrandomnumber(arr, arrlength);
	cout << "array 1 elements :\n";
	printarray(arr, arrlength);
	int arr2[100];
	copyarray(arr, arr2, arrlength);
	cout << "\narray 2 elements agter copy :\n";
	printarray(arr2, arrlength);

	return 0;
}
// resolve proble 28,2 copy array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
int randomnumber(int from,int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillarraywithrandomnumber(int arr[100], int & arrlength) {
	cout << "\nenter the number element\n";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++) {
		arr[i] = randomnumber(1, 100);
	}

	
}
void printarray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";
	}
}
void addarrayelement(int number, int arr2[100], int& arrlength2) {
	arrlength2++;
	arr2[arrlength2 - 1] = number;
}
void 	copyarrayusingaddarrayelement(int arr[100], int arr2[100], int arrlength, int& arrlength2)
{
	for (int i = 0; i < arrlength; i++) {
		addarrayelement(arr[i], arr2, arrlength2);
	   }
}
int main() {
	int arr[100], arr2[100], arrlength = 0, arrlength2 = 0;

	fillarraywithrandomnumber(arr, arrlength);
	
	copyarrayusingaddarrayelement(arr, arr2, arrlength, arrlength2);
	cout << "array 1 element :\n";
	printarray(arr, arrlength);
	cout << "\narray 2 element after copy : \n";
	printarray(arr, arrlength);
	return 0;
}
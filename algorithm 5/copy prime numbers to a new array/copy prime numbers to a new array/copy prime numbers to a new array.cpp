#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
enum enprimenotprime{prime=1,notprime=2};
enprimenotprime checkprime(int number) {
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return enprimenotprime::notprime;
	}
	return enprimenotprime::prime;
}
int randomnumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillarraywithrandomnumber(int arr[100], int& arrlength) {
	cout << "enter the array elements : \n";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++) {
		arr[i] = randomnumber(1, 100);
	}
}
void addarrayelement(int number,int arr2[100],int& arrlength2) {
	arrlength2++;
	arr2[arrlength2 - 1] = number;

}
void copyprimenumber(int arr[100], int arr2[100], int arrlength, int& arrlength2) {
	for (int i = 0; i < arrlength; i++) {
		if (enprimenotprime::prime == checkprime(arr[i]))
			addarrayelement(arr[i], arr2, arrlength2);
	}
}
void printarray(int arr[100], int arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << "  ";
	}
}
int main() {
	int arr[100], arr2[100], arrlength = 0, arrlength2 = 0;
	fillarraywithrandomnumber(arr, arrlength);
	copyprimenumber(arr, arr2, arrlength, arrlength2);

	cout << "array 1 element :\n";
	printarray(arr, arrlength);
	cout << "\narray 2 element prime : \n";
	printarray(arr2, arrlength2);
 	return 0;
}
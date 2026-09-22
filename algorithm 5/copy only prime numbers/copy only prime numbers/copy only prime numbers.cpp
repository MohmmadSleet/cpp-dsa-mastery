


#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

enum enprimenotprime{prime=1,notprime=2};
enprimenotprime checkprime(int number) {
	
	for (int counter = 2; counter < number; counter++) {
		if (number % counter == 0)
			return enprimenotprime::notprime;
	}
	return enprimenotprime::prime;
}
int Randomnumber(int from,int to){
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillvaluearray(int arr[100], int& arrlength)
{
	cout << "enter the value arrlength\n";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++) {
		arr[i] = Randomnumber(1, 100);
	}
}
void copyonlyprimenumber(int arr[100], int arr2[100], int  arrlength, int& arrlength2) {
	int counter = 0;
	for (int i = 0; i < arrlength; i++) {
		if (checkprime(arr[i]) == enprimenotprime::prime)
		{
			arr2[counter] = arr[i];
			counter++;
		}
	}
	arrlength2 = --counter;
}

void printarray(int arr[100],int& arrlength) {
	for (int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";
	}

}

int main() {

	srand((unsigned)time(NULL));
	int arr[100], arrlength=0;
	fillvaluearray(arr,arrlength);
	cout << "\nArray 1 Elements : \n";
	printarray(arr, arrlength);
	int arr2[100], arrlength2;
	copyonlyprimenumber(arr, arr2, arrlength, arrlength2);
	cout << "\nArray 2 Elements prime : \n";
	printarray(arr2, arrlength2);
	return 0;
}


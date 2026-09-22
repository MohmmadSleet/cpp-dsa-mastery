

#include<iostream>
#include<string>
using namespace std;
int Readnumber() {
	int number = 0;
	cout << "please enter the number ?";
	cin >> number;
	return number;
}
void Addarrayelement(int number, int arr[100], int& arrlength) {
	arrlength++;
	arr[arrlength - 1] = number;
}
void inputarrayinelement(int arr[100], int& arrlength) {
	bool addmore = true;
	do {
		Addarrayelement(Readnumber(), arr, arrlength);
		cout << "do you need add array ? no[0],yes[1] ?";
		cin >> addmore;
	} while (addmore);
}

void 	printarrayelemnt(int arr[100], int arrlength) {
	for(int i = 0; i < arrlength; i++) {
		cout << arr[i] << " ";

	}
}

int main() {
	int arr[100], arrlength = 0;
	inputarrayinelement(arr, arrlength);
	cout << "\narry length = " << arrlength << endl;
	cout << "array element = \n";
	printarrayelemnt(arr, arrlength);

	return 0;
}
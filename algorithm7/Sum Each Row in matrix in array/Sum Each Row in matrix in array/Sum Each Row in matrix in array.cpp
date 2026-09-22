#include<iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From,int To){
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
void FillArrayWithRandomNumber(int arr[3][3],int Row,int Colums ) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colums; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}

}
void PrintArraywithRandomNumber(int arr[3][3], int Row, int colums) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colums; j++) {
			cout << arr[i][j] << "       ";

		}
		cout << endl;
	}
}
int SumRow(int arr[3][3], int Row, int cloum) {
	int sum = 0;
	for (int i = 0; i <= cloum - 1; i++) {
		sum += arr[Row][i];
	}
	return sum;
}
void StorgeSumRowinarray(int arr[3][3], int arrSum[3], int Row, int Colums) {
	for (int i = 0; i < Row; i++) {
		arrSum[i] = SumRow(arr, i, Colums);
	}
}
void PrintSumEachRow(int arrSum[3], int Row) {
	for (int i = 0; i < Row; i++) {
		cout << "The Row " << i + 1 << " sum =" << arrSum[i] << endl;
	}
}
int maim() {
	srand((unsigned)time(NULL));

	int arr[3][3], arrSum[3];

	FillArrayWithRandomNumber(arr, 3, 3);
	cout << "the array matrix 3*3 = \n";
	PrintArraywithRandomNumber(arr, 3, 3);
	StorgeSumRowinarray(arr, arrSum, 3, 3);
	PrintSumEachRow(arrSum, 3);

	return 0;
}
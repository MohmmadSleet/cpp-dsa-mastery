#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std ;
int RAndomNumber(int FRom,int To) {
	int RandNum = rand() % (To - FRom + 1) + FRom;
	return RandNum;

}
void FillArrWithRandomNumber(int arr[3][3], short Row, short Colum) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colum; j++) {
			arr[i][j] = RAndomNumber(0, 1000);
		}
	}
	

}
void PrintArrWithRandomNumber(int arr[3][3],short Row,short colum) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < colum; j++) {
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	FillArrWithRandomNumber(arr, 3, 3);
	cout << "The Following is 3*3 \n";
	PrintArrWithRandomNumber(arr, 3, 3);


	return 0;
}

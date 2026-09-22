#include<iostream>

using namespace std;

int ReadPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;

	} while (number < 0);
	return number;
}

int countdigitfrequency(int i, int number) {
	int remainder = 0, frequency = 0;
	while (number != 0) {
		remainder = number % 10;
		number = number / 10;
		if (i == remainder)
			frequency++;
	}
	return frequency;
}

void printalldigitnumber(int number) {
	cout << endl;
	for (int i = 1; i < 10; i++) {
		short digitfrequency = countdigitfrequency(i, number);
			cout << "digits = " << i << "frequency is = " << digitfrequency << endl;
	}

}

int main() {

	int number = ReadPositiveNumber("please enter the positive number ?");
	printalldigitnumber(number);
}
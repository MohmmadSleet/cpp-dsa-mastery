// print all prime number from 1 to n.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

enum enprimenotprime{ prime=1 , notprime=2};

int ReadPoitiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number < 0);
	return number;
}

enprimenotprime checkprime(int counter) {
	for (int i = 2; i < counter; i++) {
		if (counter % i == 0)
			return enprimenotprime::notprime;
	}
	return enprimenotprime::prime;
}
void printallnumbersFrom1toN(int number) {
	
	for (int counter = 1; counter <= number; counter++) {
		if (checkprime(counter) == enprimenotprime::prime)
			cout << counter << "\t";
	}

}
int main()
{
	printallnumbersFrom1toN(ReadPoitiveNumber("please enter the positive number ? "));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

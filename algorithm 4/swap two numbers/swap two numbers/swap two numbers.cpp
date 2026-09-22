// swap two numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
void readnumbers(int& number1, int& number2) {
	cout << "please enter the number 1 : ";
	cin >> number1;
	cout << "please enter the number 2 : ";
	cin >> number2;

}

void swapnumbers(int& number1, int& number2) {
	int temp = number1;
	number1 = number2;
	number2 = temp;
}
void printvalue(int number1, int number2) {
	cout << "number1 = " << number1 << endl;

	cout << " number2 = " << number2 << endl;
}

int main()
{
	int number1, number2;
	readnumbers(number1, number2);
	printvalue(number1, number2);
	swapnumbers(number1, number2);
	printvalue(number1, number2);

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

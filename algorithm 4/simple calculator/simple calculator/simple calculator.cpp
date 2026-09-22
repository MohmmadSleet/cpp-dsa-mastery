// simple calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//work a simple calculator
#include <iostream>
#include<string>
#include<math.h>

using namespace std;
void readnumbers(float &number1, float &number2 ,char &op) {
	cout << "please enter the number 1 :";
	cin >> number1;
	cout << "please enter the op :";
	cin >> op;
	cout << "please enter the number 2 :";
	cin >> number2;
 }
float calculatorresult(float number1, float number2, char op) {
	switch (op) {
	case '+':
		return number1 + number2;
	case '-':
		return number1 - number2;
	case  '*':
		return number1 * number2;
	case '/':
		return number1 / number2;
	default:
		return number1;
	}
}
	
int main(){
	float number1, number2;
	char op;
	readnumbers(number1, number2,op);
	float calculator = calculatorresult(number1, number2, op);
	
	cout << "calculator = " << calculator << endl;
	return 0;
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

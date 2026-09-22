// #03-2perfect number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

enum enperfectornot { perfect = 1, notperfect = 2 };

int ReadPoitiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;
		cin >> number;
	} while (number < 0);
	return number;
}

enperfectornot checkperfect(int number) {
	int sum = 0;
	for (int i = 1; i < number; i++) {
		if (number % i == 0)
			sum = sum + i;
	}

	if (sum == number)
		return enperfectornot::perfect;
	else
		return enperfectornot::notperfect;
}
void printperfectornot(int number) {

	
	if (checkperfect(number) == enperfectornot::perfect)
		cout << number << "\a  the number is perfect ";
	else
		cout << number << "  the  number is not perfect";
	

}
int main()
{
	printperfectornot(ReadPoitiveNumber("please enter the positive number until perfect or not ? "));
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

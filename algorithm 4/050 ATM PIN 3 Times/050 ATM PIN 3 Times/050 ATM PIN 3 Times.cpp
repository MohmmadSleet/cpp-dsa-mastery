// 050 ATM PIN 3 Times.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool readatmpin() {
	string atm;
	int counter = 4;
	do {
		cout << "please enter the atm pin : \n";
		cin >> atm;
		if (atm != "1234") {
			cout << "wrong atm \n";
		}
		else {
			return 1;
		}
		counter--;
	} while (atm != "1234" && counter!=0);
	return 0;
}
int main()
{
	if (readatmpin() == 1)
		cout << "your balance = 2700 \n";
	else
	
	cout << "card is locked!";
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

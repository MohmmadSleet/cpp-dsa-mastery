// pay remmainder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<String>
using namespace std;

int readpositivenumber(string message) {
	int numbers;
	do {
		cout << message << endl;
		cin >> numbers;
	} while (numbers <= 0);
	return numbers;
}
int calculateremainder(int totalbill, int cashpaid) {
	return (cashpaid - totalbill);
}

void printremainder(int remainder) {
	cout << "rmeainder = " << remainder << endl;
}
int main()
{
	int totalbill = readpositivenumber("please enter the total bill : ");
	int cashpaid = readpositivenumber("please enter the cash bill : ");

	printremainder(calculateremainder(totalbill,cashpaid));


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

// hire a driver case 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stinfo {
	int age;
	bool hasdriverlicense;
};
stinfo readinfo() {
	stinfo info;
	cout << "please enter the age : \n";
	cin >> info.age;
	cout << "please enter has driver license : \n";
	cin >> info.hasdriverlicense;
	return info;
}
bool checkinfo(stinfo info) {
	
	return (info.age >= 21 && info.hasdriverlicense);
 }
void printresult(bool checkinfo) {
	if (checkinfo == 1)
		cout << " hired ";
	else
		cout << " rejected ";

}
int main()
{
	printresult(checkinfo(readinfo()));
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

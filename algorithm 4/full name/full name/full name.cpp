// full name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
struct stinfo {
	string firstname;
	string lastname;
};
stinfo Readfullname() {
	stinfo info;
	cout << "please enter the first  name : \n";
	getline(cin, info.firstname);
	cout << "please enter the last name : \n";
	getline(cin, info.lastname);
	return info;
}

string getfullname(stinfo info) {
	string fullname;
	fullname=info.firstname + "  " + info.lastname;
	return fullname;
}
void printfullname(string fullname) {
	cout << "my name is : " << fullname;
}
int main() {
	printfullname(getfullname(Readfullname()));
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

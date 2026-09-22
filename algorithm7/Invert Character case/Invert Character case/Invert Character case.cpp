// Invert Character case.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

char ReadCharacter() {
	char C1;
	cout << "please enter the char ? \n";
	cin >> C1;
	return C1;
}
char InvertLetterCase(char c1) {
	
	return (islower(c1) ? toupper(c1) : tolower(c1));
}

int main()
{
	char c1 = ReadCharacter();
	cout << "\nChar after inverting case:\n";
	c1 = InvertLetterCase(c1);
	cout << c1 << endl; 
	system("pause>0");

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

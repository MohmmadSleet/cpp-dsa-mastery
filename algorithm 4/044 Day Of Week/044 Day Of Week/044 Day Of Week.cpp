// 044 Day Of Week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum ennumberofday { sun = 1, mon = 2, tue = 3, wed = 4, thu = 5, fri = 6, sat = 7 };

int readthenumberday(string message) {
	int numberday = 0;
	do {
		cout << message << endl;
		cin >> numberday;
	} while (!(numberday >= 1 && numberday <= 7));
	return numberday;
}
ennumberofday checkday(int numberday) {

	return (ennumberofday)numberday;
}



string printday(ennumberofday numberofday)
{
	switch (numberofday) {
	case ennumberofday::sun:
		return" sunday ";
	case ennumberofday::mon:
		return" monday ";
	case ennumberofday::tue:
		return" tuesday ";
	case ennumberofday::wed:
		return" wedensday ";
	case ennumberofday::thu:
		return" thursday ";
	case ennumberofday::fri:
		return" friday ";
	case ennumberofday::sat:
		return" satrday ";
	default:
		return" erorr enter ";
	}
}
int main()
{
	cout << printday(checkday(readthenumberday("please enter the number day : "))) << endl;
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

// 45 Month Of Year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum ennumberofday { jan=1,feb=2,march=3,april=4,may=5,jun=6,july=7,aug=8,sep=9,oct=10,nov=11,dec=12};

int readthenumberday(string message) {
	int numberday = 0;
	do {
		cout << message << endl;
		cin >> numberday;
	} while (!(numberday >= 1 && numberday <= 12));
	return numberday;
}
ennumberofday checkmonth(int numbermonth) {

	return (ennumberofday)numbermonth;
}



string printmonth(ennumberofday numberofmonth)
{
	switch (numberofmonth) {
	case ennumberofday::jan:
		return" january ";
	case ennumberofday::feb:
		return" febroury ";
	case ennumberofday::march:
		return" march ";
	case ennumberofday::april:
		return" april ";
	case ennumberofday::may:
		return" may ";
	case ennumberofday::jun:
		return" jun ";
	case ennumberofday::july:
		return" july ";
	case ennumberofday::aug:
		return" auguset ";
	case ennumberofday::oct:
		return" october ";
	case ennumberofday::nov:
		return" november ";
	case ennumberofday::dec:
		return" december ";
	default:
		return" erorr enter ";
	}
}
int main()
{
	cout << printmonth(checkmonth(readthenumberday("please enter the number month : "))) << endl;
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

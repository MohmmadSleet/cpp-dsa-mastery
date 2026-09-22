// Read Print Date String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct sDate {
	int Days;
	int Month;
	int Year;
};
vector<string>SplitString(string DateInString,string Delium) {
	short Pos = 0;
	string sWord;
	vector <string>vSplit;
	while ((Pos = DateInString.find(Delium)) != std::string::npos) {
		sWord = DateInString.substr(0, Pos);
		if (sWord != "") {
			vSplit.push_back(sWord);
		}
		DateInString.erase(0, Pos + Delium.length());
	}

	if (DateInString != "") {
		vSplit.push_back(DateInString);
	}
	return vSplit;


}

string ReadDateString(string Message) {
	string Date;
	cout << Message << endl;
	getline(cin >> ws, Date);
	return Date;
}
sDate StringToDate(string ReadDate) {
	sDate Date;
	vector<string>vSplit = SplitString(ReadDate, "/");
	Date.Days = stoi(vSplit[0]);
	Date.Month = stoi(vSplit[1]);
	Date.Year = stoi(vSplit[2]);
	return Date;
}
string  DateToString(sDate Date) {

	return to_string(Date.Days) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
int main()
{
	string DateInString=ReadDateString("Please enter the Date dd/mm/yyyy ?");

	sDate Date=StringToDate(DateInString);
	cout << "\nDays = " << Date.Days;
	cout << "\nMonth = " << Date.Month;
	cout << "\nYear = " << Date.Year;

	cout << "\n\nYou Entered : " << DateToString(Date) << endl;
	system("pause>0");
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

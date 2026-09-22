// Format Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;
struct sDate {
    short Day;
    short Month;
    short Year;
};
string ReadDateString(string message) {
    string Date;
    cout << message << endl;
    getline(cin >> ws, Date);
    return Date;
}
vector<string>SplitString(string S1, string Delium) {
    short pos = 0;
    string sWord;
    vector<string>vSplit;
    while ((pos = S1.find(Delium)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vSplit.push_back(sWord);
        }
        S1.erase(0, pos + Delium.length());
    }
    if (S1 != "") {
        vSplit.push_back(S1);
    }
    return vSplit;
}
sDate StringToDate(string DateString) {
    sDate Date;
    vector<string>vSplit = SplitString(DateString, "/");
    Date.Day = stoi(vSplit[0]);
    Date.Month = stoi(vSplit[1]);
    Date.Year = stoi(vSplit[2]);
    return Date;
}

string ReplaceWordInString(string S1, string stringToReplace, string ReplaceTo) {
    short pos = S1.find(stringToReplace);
    while (pos != std::string::npos) {
        S1 = S1.replace(pos, stringToReplace.length(), ReplaceTo);
        pos = S1.find(stringToReplace);
    }
    return S1;
}
string FormatDate(sDate Date,string DateFromat="dd/mm/yyyy") {

    string FormatDateString = "";
    FormatDateString = ReplaceWordInString(DateFromat, "dd", to_string(Date.Day));
    FormatDateString = ReplaceWordInString(FormatDateString, "mm", to_string(Date.Month));
    FormatDateString = ReplaceWordInString(FormatDateString, "yyyy", to_string(Date.Year));

    return FormatDateString;
}
int main()
{
    string DateString = ReadDateString("Please enter the string ?");
    sDate Date = StringToDate(DateString);
    cout << "\n" << FormatDate(Date) << endl;
    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << endl;
    cout << "\n" << FormatDate(Date,"mm/dd/yyyy") << endl;
    cout << "\n" << FormatDate(Date,"mm-dd-yyyy") << endl;
    cout << "\n" << FormatDate(Date,"dd-mm-yyyy") << endl;
    cout << "\n" << FormatDate(Date,"Day:dd, Month : mm, Year:yyyy") << endl;
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

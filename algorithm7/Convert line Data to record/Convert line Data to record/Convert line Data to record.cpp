 // Convert line Data to record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;
struct stClinet {
    string AccountNumber;
    string PinCode;
    string Name;
    string phone;
    string AccountBalance;
};
vector <string> SpiltString(string str, string sperater) {
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = str.find(sperater)) != std::string::npos) {
        sWord = str.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        str.erase(0, pos + sperater.length());
    }
    if (str != "")
        vString.push_back(str);
    return vString;
}
stClinet RecordTheClinet(string str, string sperater = "#//#") {
    stClinet Clinet;
    vector<string>vString = SpiltString(str, sperater);
    Clinet.AccountNumber = vString[0];
    Clinet.PinCode = vString[1];
    Clinet.Name = vString[2];
    Clinet.phone = vString[3];
    Clinet.AccountBalance = vString[4];
    return Clinet;
}
void PrinetClinetRecod(stClinet Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;

}
int main(){
    string str = { "A150#//#1234#//#Mohmmad jameel#//#0595107619#//#3000" };
    stClinet Clinet = RecordTheClinet(str);
    cout << str << endl;

    PrinetClinetRecod(Clinet);

}

/*void PrinetClinetRecod(stClinet Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;

}*/

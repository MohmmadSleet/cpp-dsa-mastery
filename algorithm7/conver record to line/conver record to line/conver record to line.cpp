
#include<string>
#include<iostream>

using namespace std;
struct stClinet {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
stClinet ReadData() {
	stClinet Clinet;
	cout << "\nEnter Account Number ? ";
	getline(cin, Clinet.AccountNumber);
	cout << "\nEnter PinCode ? ";
	getline(cin, Clinet.PinCode);
	cout << "\n Enter Name?";
	getline(cin, Clinet.Name);
	cout << "\nEnter  phone ? ";
	getline(cin, Clinet.Phone);
	cout << "\nEnter Account Balance?";
	getline(cin, Clinet.AccountBalance);
	return Clinet;
}

string ClinetRecorsForSaving(stClinet Clinet,string sperater) {
	string S2 = " ";

	S2 += Clinet.AccountNumber + sperater;
	S2 += Clinet.PinCode + sperater;
	S2 += Clinet.Name + sperater;
	S2 += Clinet.Phone + sperater;
	S2 += Clinet.AccountBalance;
	return S2;
}
int main() {
	cout << "Please enter client data :\n\n";
	stClinet Clinet;
		Clinet = ReadData();
		cout << "\n\nClinet Records For Saving : \n";
		cout << ClinetRecorsForSaving(Clinet,"#//#") << endl;

	return 0;
}
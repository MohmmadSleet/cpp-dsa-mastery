
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const string MyFileName = "Sultan.txt";
struct stClient {
	string AccountNumber;
	string AccountBalance;
	string Phone;
	string Name;
	string PinCode;
};
stClient ReadNewClient() {

	stClient Client;
	cout << "Enter Account Number? "; 
	// Usage of std::ws will extract allthe whitespace character
	    getline(cin >> ws, Client.AccountNumber); 
		cout << "Enter PinCode? ";
		getline(cin, Client.PinCode);  
		cout << "Enter Name? ";
		getline(cin, Client.Name);
		cout << "Enter Phone? "; 
		getline(cin, Client.Phone);
		cout << "Enter AccountBalance? "; 
		cin >> Client.AccountBalance; 
		return Client;
} 
string ConvertClientToLine(stClient Client, string Seperator = "#//#") {
	string stClientRecord = ""; 
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;  
	stClientRecord += Client.Phone + Seperator;  
	stClientRecord += (Client.AccountBalance); 
	return stClientRecord;
}
void AddLineToFile(string FilName, string Line) {
	fstream MyFile;
	MyFile.open(FilName, ios::app | ios::out);
	if (MyFile.is_open()) {
		MyFile << Line << endl;
		MyFile.close();
	}
}
void AddNewClient() {
	stClient Client;
	Client = ReadNewClient();
	AddLineToFile(MyFileName, ConvertClientToLine(Client));
}
void AddClients() {
	char AddMore = 'Y';
	do {
		cout << "Adding clients\n\n";
		AddNewClient();

		cout << "add more successful ,Do you want to add more ?";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
int main() {

	AddClients();

	return 0;
}
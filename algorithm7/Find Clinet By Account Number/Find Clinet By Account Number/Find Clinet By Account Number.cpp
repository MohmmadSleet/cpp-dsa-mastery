#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
const string ConvertFileName = "Clients.txt";
struct stClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
vector<string>SpiltString(string str, string sperater) {
	vector<string>vString;
	short pos = 0;
	string Sword;
	while ((pos = str.find(sperater)) != std::string::npos) {
		Sword = str.substr(0, pos);
		if (Sword != "") {
			vString.push_back(Sword);
		}
		str.erase(0, pos + sperater.length());
	}
	if (str != "") {
		vString.push_back(str);

	}
	return vString;
}
stClients ConvertLineToRecord(string line) {
	vector<string>vSpilt = SpiltString(line, "#//#");
	stClients clients;
	clients.AccountNumber = vSpilt[0];
	clients.PinCode = vSpilt[1];
	clients.Name = vSpilt[2];
	clients.Phone = vSpilt[3];
	clients.AccountBalance = vSpilt[4];
	return clients;
}
string ReadAccountNumber() {
	string AccountNumber;
	cout << "Enter the Account Number ? ";
	getline(cin, AccountNumber);
	return AccountNumber;

}
vector<stClients>LoadDataFromFile(string FileName) {
	vector<stClients>vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string line;
		stClients Clients;
		while (getline(MyFile, line)) {
			Clients = ConvertLineToRecord(line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;


}

bool FindAccountNumberISFind(string AccountNumber, stClients& Clients) {
	vector<stClients>vClients = LoadDataFromFile(ConvertFileName);
	for (stClients& c : vClients) {
		if (c.AccountNumber == AccountNumber) {
			Clients = c;
			return true;
		}
	}
	return false;

}
void PrintInformationCard(stClients Clients) {
	cout << "\n\n Account Number : " << Clients.AccountNumber << endl;
	cout << "Account PinCode : " << Clients.PinCode << endl;
	cout << "\n\n Account Name : " << Clients.Name << endl;
	cout << "Account phone : " << Clients.Phone << endl;
	cout << "\n\n Account balance : " << Clients.AccountBalance << endl;

}
int main() {
	stClients Clients;

	vector<stClients>vClinets;
	string AccountNumber = ReadAccountNumber();
	if (FindAccountNumberISFind(AccountNumber, Clients)) {
		PrintInformationCard(Clients);

	}
	else {
		cout << "\nClient with Account Number(" << AccountNumber << ") is Not Found!";
	}
	return 0;

}
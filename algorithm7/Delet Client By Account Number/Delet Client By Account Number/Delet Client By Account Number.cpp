/*#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct stClients {
	string AccountNumber;
	string AccountPinCod;
	string Name;
	string Phone;
	string AccountBalnace;
};
const string ClientsFileName = "Clients.txt";
stClients ReadInformationClients() {
	stClients Clients;
	cout << "Enter the Account Number ?\n";
	getline(cin >> ws, Clients.AccountNumber);
	cout << "Enter the Account PinCode ? \n";
	getline(cin, Clients.AccountPinCod);
	cout << "Enter the Account Name ? \n";
	getline(cin, Clients.Name);
	cout << "Enter the Account phone ? \n";
	getline(cin, Clients.Phone);
	cout << "Enter the Account Account Balance ? \n";
	getline(cin, Clients.AccountBalnace);
	return Clients;
}

string ConvertRecordToLine(stClients Clients) {
	string S1;
	string delium = "#//#";
	S1 += Clients.AccountNumber + delium;
	S1 += Clients.AccountPinCod + delium;
	S1 += Clients.Name + delium;
	S1 += Clients.Phone + delium;
	S1 += Clients.AccountBalnace;
	return S1;
}
void AddDataFromToFile(string FileName, string Line) {
	fstream MyFile;
	
	MyFile.open(FileName, ios::app | ios::out);
	if (MyFile.is_open()) {
		
		MyFile << Line << endl;
		MyFile.close();
	}

}
void AddNewClients() {
	cout << "Adding New Client: \n\n\n";
	stClients Clients = ReadInformationClients();
	AddDataFromToFile(ClientsFileName, ConvertRecordToLine(Clients));
}
void AddClients(){
	char AddMore = 'Y';
	
	do {
		system("cls");
		AddNewClients();
		cout << "Clients Add Successful, Do you want add more ?\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}
int main() {
	
	AddClients();

	return 0;
}*/


/*#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
const string ClietnsFileName = "Clients.txt";
struct stClients {
	string AccountNumber;
	string AccountPinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
string ReadAccountNumber() {
	string AccountNumber;
	cout << "pleas enter the Account Number ? \n";
	getline(cin, AccountNumber);
	return AccountNumber;
}
void PrintClientInformation(stClients Clients) {
	cout << "The Followin are the clients details : \n\n";

	cout << "---------------------------------------------\n";

	cout << "Account Number = " << Clients.AccountNumber << endl;
	cout << "Account pincode = " << Clients.AccountPinCode << endl;

	cout << "Account Name = " << Clients.Name << endl;

	cout << "Account Phone = " << Clients.Phone << endl;

	cout << "Account balance = " << Clients.AccountBalance << endl;

	cout << "---------------------------------------------\n";
}
vector<string>SplitString(string line, string delium) {
	vector<string>vSplit;
	short pos = 0;
	string Sword;
	while ((pos = line.find(delium)) != std::string::npos) {
		Sword = line.substr(0, pos);
		if (Sword != "") {
			vSplit.push_back(Sword);
		}
		line.erase(0, pos + delium.length());

	}
	if (line != "") {
		vSplit.push_back(line);
	}
	return vSplit;
}
stClients ConvertLineToRecord(string line) {
	vector<string>vSplit = SplitString(line, "#//#");
	stClients Clients;
	Clients.AccountNumber = vSplit[0];
	Clients.AccountPinCode = vSplit[1];
	Clients.Name = vSplit[2];
	Clients.Phone = vSplit[3];
	Clients.AccountBalance = vSplit[4];
	return Clients;
}
vector<stClients> LoadClientDataFromFile(string FileName) {
	vector<stClients>vClients;
	stClients Clients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string line;
	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {
			Clients = ConvertLineToRecord(line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;

}
bool FiendAccountNumberInFile(string FileName, string AccountNumber,stClients& Clients) {
	
	vector<stClients>vClients = LoadClientDataFromFile(FileName);
	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Clients = C;
			return true;
		}
	}
	return false;
}
int main() {
	string AccountNumber = ReadAccountNumber();
	stClients Clients;
	
	if (FiendAccountNumberInFile(ClietnsFileName, AccountNumber,Clients)) {
		PrintClientInformation(Clients);
	}
	else {
		cout << "Client With Found Number (" << AccountNumber << ") Not Found .";
	}
	return 0;
}

*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
const string ClientFileName = "Clients.txt";
struct stClients {
	string AccountNumber;
	string AccountPinCode;
	string Name;
	string Phone;
	string AccountBalance;
	bool MarkForDelet = false;
};
vector<string>SplitString(string line, string delium) {
	vector<string>vSplit;
	short pos = 0;
	string Sword;
	while ((pos = line.find(delium)) != std::string::npos) {
		Sword = line.substr(0, pos);
		if (Sword != "") {
			vSplit.push_back(Sword);
		}
		line.erase(0, pos + delium.length());

	}
	if (line != "") {
		vSplit.push_back(line);
	}
	return vSplit;
}
stClients ConvertLineToRecord(string line) {
	vector<string>vSplit = SplitString(line, "#//#");
	stClients Clients;
	Clients.AccountNumber = vSplit[0];
	Clients.AccountPinCode = vSplit[1];
	Clients.Name = vSplit[2];
	Clients.Phone = vSplit[3];
	Clients.AccountBalance = vSplit[4];
	return Clients;
}
vector<stClients> LoadClientDataFromFile(string FileName) {
	fstream MyFile;
	vector<stClients>vClients;
	stClients Clients;
	MyFile.open(FileName, ios::in);
	string line;
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {
			Clients = ConvertLineToRecord(line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;
}
string ReadAccountNumber() {
	string AccountNumber;
	cout << "pleas enter the Account Number ? \n";
	getline(cin, AccountNumber);
	return AccountNumber;
}void PrintClientInformation(stClients Clients) {
	cout << "The Followin are the clients details : \n\n";

	cout << "---------------------------------------------\n";

	cout << "Account Number = " << Clients.AccountNumber << endl;
	cout << "Account pincode = " << Clients.AccountPinCode << endl;

	cout << "Account Name = " << Clients.Name << endl;

	cout << "Account Phone = " << Clients.Phone << endl;

	cout << "Account balance = " << Clients.AccountBalance << endl;

	cout << "---------------------------------------------\n";
}
bool FindAccountNumber(string AccountNumber,vector<stClients>& vClients,stClients& Clients) {

	for (stClients& C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			Clients = C;
			return true;
		}
	}
	return false;
}
bool MarkClientByAccountNumber(string AccountNumber,vector<stClients> &vClients, stClients Clients) {

	for (stClients& C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			C.MarkForDelet = true;
			return true;
		}
	}
	return false;
}
string ConvertRecordToline(stClients Clients) {
	string S1;
	string delium = "#//#";
	S1 += Clients.AccountNumber + delium;
	S1 += Clients.AccountNumber + delium;
	S1 += Clients.Name + delium;
	S1 += Clients.Phone + delium;
	S1 += Clients.AccountBalance;
	return S1;
}
vector<stClients>	SaveDataFromFile(string FileName, vector<stClients>& vClients) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string line;
	stClients Clients;
	if (MyFile.is_open()) {
		for (stClients C : vClients) {
			if (C.MarkForDelet == false){
				line = ConvertRecordToline(C);
			MyFile << line << endl;
		}
	}
		MyFile.close();
	}
	return vClients;
}

bool 	DeletClientByAccountNumber(string AccountNumber,vector<stClients> &vClients) {
	stClients Clients;
	char Answer = 'n';
	if (FindAccountNumber(AccountNumber, vClients, Clients)) {
		PrintClientInformation(Clients);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";  
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientByAccountNumber(AccountNumber,vClients,Clients);
			SaveDataFromFile(ClientFileName, vClients);
			vClients = LoadClientDataFromFile(ClientFileName);

				cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "Client With Found Number (" << AccountNumber << ") Not Found .";
		return false;
	}
}

int main() {
	vector<stClients>vClients = LoadClientDataFromFile(ClientFileName);
	string AccountNumber = ReadAccountNumber();
	DeletClientByAccountNumber(AccountNumber, vClients);
	return 0;
}



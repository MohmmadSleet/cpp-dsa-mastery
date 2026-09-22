/*
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

const string ClientsFileNmae = "Clients.txt";
struct stClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
vector<string>SplitString(string Line, string delium) {
	vector<string>vString;
	string sWord;
	short pos = 0;
	while ((pos = Line.find(delium)) != std::string::npos) {
		sWord = Line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, pos + delium.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}
stClients ConvertLineToRecord(string line,string delium="#//#") {
	vector<string>vString = SplitString(line,delium);
	stClients Clients;
	Clients.AccountNumber = vString[0];
	Clients.PinCode = vString[1];
	Clients.Name = vString[2];
	Clients.Phone= vString[3];
	Clients.AccountBalance = vString[4];
	return Clients;

}
vector<stClients> LoadClientDataFromFile(string FileName) {
	vector<stClients>vClients;
	string line;
	stClients Clietns;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {
			Clietns = ConvertLineToRecord(line);
			vClients.push_back(Clietns);
		}
		MyFile.close();
	}
	return vClients;
}
void PrintClientRecord(stClients Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;  
	cout << "| " << setw(10) << left << Client.PinCode; 
	cout << "| " << setw(40) << left << Client.Name;  
	cout << "| " << setw(12) << left << Client.Phone;   
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientData(vector <stClients> vClients) {
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl;  
	cout << "| " << left << setw(15) << "Accout Number";  
	cout << "| " << left << setw(10) << "Pin Code";  
	cout << "| " << left << setw(40) << "Client Name"; 
	cout << "| " << left << setw(12) << "Phone";  
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";   
	cout << "_________________________________________\n" << endl; 
	for (stClients &Client : vClients) { 
		PrintClientRecord(Client);     
		cout << endl; 
	}  
	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl; 
}
*/
/*#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

const string ClientsFileNmae = "Clients.txt";
struct stClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
string ReadAccountNumber() {
	string str;
	cout << "Please enter the AccountNumber ? ";
	getline(cin, str);
	return str;

}
void PrintClientRecord(stClients Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber<<endl;
	cout << "| " << setw(10) << left << Client.PinCode << endl;
	cout << "| " << setw(40) << left << Client.Name << endl;
	cout << "| " << setw(12) << left << Client.Phone << endl;
	cout << "| " << setw(12) << left << Client.AccountBalance << endl;
}
vector<string>SplitString(string Line, string delium) {
	vector<string>vString;
	string sWord;
	short pos = 0;
	while ((pos = Line.find(delium)) != std::string::npos) {
		sWord = Line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, pos + delium.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}
stClients ConvertLineToRecord(string line, string delium = "#//#") {
	vector<string>vString = SplitString(line, delium);
	stClients Clients;
	Clients.AccountNumber = vString[0];
	Clients.PinCode = vString[1];
	Clients.Name = vString[2];
	Clients.Phone = vString[3];
	Clients.AccountBalance = vString[4];
	return Clients;

}

vector<stClients>LoadClientDataFromFile(string FileName) {
	vector<stClients>vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string line;
	stClients Clients;
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {
			Clients = ConvertLineToRecord(line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;

}
bool FindAccountNumber(string AccountNumber, stClients& Clients) {
	vector<stClients>vClients = LoadClientDataFromFile(ClientsFileNmae);
	for (stClients& C : vClients) {

		if (AccountNumber == C.AccountNumber) {
			Clients = C;
			return true;
		}
	}
	return false;
}

int main() {
	stClients Client;
	string AccountNumber = ReadAccountNumber();
	if (FindAccountNumber(AccountNumber, Client)) {
		PrintClientRecord(Client);
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}

	return 0;
}*/


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;

const string ClientsFileNmae = "Clients.txt";
struct stClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
	bool MarkToDelet;
};
string ReadAccountNumber() {
	string str;
	cout << "Please enter the AccountNumber ? ";
	getline(cin, str);
	return str;

}
vector<string>SplitString(string Line, string delium) {
	vector<string>vString;
	string sWord;
	short pos = 0;
	while ((pos = Line.find(delium)) != std::string::npos) {
		sWord = Line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, pos + delium.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}
stClients ConvertLineToRecord(string line, string delium = "#//#") {
	vector<string>vString = SplitString(line, delium);
	stClients Clients;
	Clients.AccountNumber = vString[0];
	Clients.PinCode = vString[1];
	Clients.Name = vString[2];
	Clients.Phone = vString[3];
	Clients.AccountBalance = vString[4];
	return Clients;

}

vector<stClients>LoadClientDataFromFile(string FileName) {
	vector<stClients>vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string line;
	stClients Clients;
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {
			Clients = ConvertLineToRecord(line);
			vClients.push_back(Clients);
		}
		MyFile.close();
	}
	return vClients;

}
bool FindAccountNumber(string AccountNumber, vector<stClients> vClients, stClients& Clients) {

	for (stClients& C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			Clients = C;
			return true;
		}
	}
	return false;
}
void PrintClientCard(stClients Client) {
	cout << "Account Number =  " << setw(15) << left << Client.AccountNumber << endl;
	cout << "PinCode =  " << setw(10) << left << Client.PinCode << endl;
	cout << "Name " << setw(40) << left << Client.Name << endl;
	cout << "Phone" << setw(12) << left << Client.Phone << endl;
	cout << "Account Name = " << setw(12) << left << Client.AccountBalance << endl;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClients> vClients) {
	 
		for (stClients& C : vClients) {
			if (C.AccountNumber == AccountNumber) {
				C.MarkToDelet = true;
				return true;
			}
		}

		return false; 
}
string ConvertRecordToLine(stClients Clients) {
	string S1 = "";
	string Delium = "#//#";
	S1 += Clients.AccountNumber + Delium;
	S1 += Clients.PinCode + Delium;
	S1 += Clients.Name + Delium;
	S1 += Clients.Phone + Delium;

	S1 += Clients.AccountBalance;
	return S1;

}
vector<stClients> SaveCleintsDataToFile(string FileName, vector<stClients> vClients) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	string line;
	if (MyFile.is_open()) {

		for (stClients& C : vClients) {
			if (C.MarkToDelet == true) {
				line = ConvertRecordToLine(C);
				MyFile << line << endl;
			}
		}
		MyFile.close();

	}
	return vClients;
}


bool DeletClientDataFromFileByAccountNumber(string AccountNumber, vector<stClients> vClients) {
	stClients Clients;
	char Answer = 'Y';
	if (FindAccountNumber(AccountNumber, vClients, Clients)) {
		PrintClientCard(Clients);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') {
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileNmae, vClients);
			vClients = LoadClientDataFromFile(ClientsFileNmae);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
		else {
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
			return false;
		}
	}



int main() {
	stClients Client;
	string AccountNumber = ReadAccountNumber();
	vector<stClients>vClients= LoadClientDataFromFile(ClientsFileNmae);
	
	DeletClientDataFromFileByAccountNumber(AccountNumber, vClients);
	return 0;
}
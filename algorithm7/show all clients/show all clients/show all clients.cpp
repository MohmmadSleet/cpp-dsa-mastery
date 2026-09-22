#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
const string ConvertFileName = "Clients.txt";
struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
vector<string> SpiltString(string str, string Sperater) {
	vector<string>vClients;
	string sWord = "";
	short pos = 0;
	while((pos = str.find(Sperater)) != std::string::npos) {
		
		sWord = str.substr(0, pos);
		if (sWord != "") {
			vClients.push_back(sWord);
		}
		str.erase(0, pos + Sperater.length());
	}
	if (str != "") {
		vClients.push_back(str);
	}
	return vClients;

}
stClient ConvertLineToRecord(string str,string Sperater="//") {
	stClient Clinet;
	vector<string>vClients = SpiltString(str, Sperater);
	Clinet.AccountNumber = vClients[0];
	Clinet.PinCode = vClients[1];
	Clinet.Name = vClients[2];
	Clinet.Phone = vClients[3];
	Clinet.AccountBalance = vClients[4];

	return Clinet;
}

vector<stClient> LoadDataFromFile(string FileName) {
	fstream MyFile;
	vector<stClient>vClient;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string line;
		stClient Client;
		while (getline(MyFile, line)) {
			Client = ConvertLineToRecord(line);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;

}
void PrintClientRecord(stClient Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;   
	cout << "| " << setw(10) << left << Client.PinCode; 
	cout << "| " << setw(40) << left << Client.Name;   
	cout << "| " << setw(12) << left << Client.Phone;  
	cout << "| " << setw(12) << left << Client.AccountBalance; 
}
void PrintAllClinetData(vector<stClient> vClients) {
	stClient Client;
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
	for (stClient Client : vClients) { 
		PrintClientRecord(Client);       
		cout << endl;
	}   
	cout << "\n_______________________________________________________";  
	cout << "_________________________________________\n" << endl;
}


int main() {
	vector<stClient>vClients = LoadDataFromFile(ConvertFileName);
	PrintAllClinetData(vClients);

	return 0;
}
// PRO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;
const string ClientsFileName = "Clients.txt";
void ShowMainMenue();
void ShowTransactionMainMenue();

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool Mark = false;
};
enum enOperation { ShowClient = 1, AddNewClient = 2, DeletClient = 3, UpdateClient = 4, FindClient = 5,Transaction=6 ,Exit = 7 };
int ReadOperation()
{
    int Op = 0;
    cout << "Choose what do you want to do? [ 1 to 7 ]?";
    cin >> Op;
    return Op;
          }
void GoBackToMainMenue() {
    cout << "Press any Key To go MAin Menue .....\n";
    system("pause>0");
    ShowMainMenue();

}
vector<string>SplitString(string Line,string Delium) {
    short pos = 0;
    string sWord;
    vector<string>vSplit;
    while ((pos = Line.find(Delium)) != std::string::npos) {
        sWord = Line.substr(0, pos);
        if (sWord != "") {
            vSplit.push_back(sWord);
        }
        Line.erase(0, pos + Delium.length());
    }
    if (Line != "") {
        vSplit.push_back(Line);
    }
    return vSplit;
}
sClient ConvertLinetoRecord(string line,string delium="#//#") {
    vector<string>vSplit = SplitString(line, delium);
    sClient Clients;
    Clients.AccountNumber = vSplit[0];
    Clients.PinCode= vSplit[1];
    Clients.Name = vSplit[2];
    Clients.Phone = vSplit[3];
    Clients.AccountBalance = stod(vSplit[4]);

    return Clients;
    
}
vector<sClient>LoadClientDataFromFile(string FileName) {
    fstream MyFile;
    vector<sClient>vClients;
    MyFile.open(FileName, ios::in);
    string line;
    sClient Clients;
    if (MyFile.is_open()) {
        while (getline(MyFile, line)) {
            Clients = ConvertLinetoRecord(line);
            vClients.push_back(Clients);
        }
        MyFile.close();
    }
    return vClients;

}
void PrintClientRecordLine(sClient Client) {
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowClientsTable() {
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
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
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else for (sClient Client : vClients) {
        PrintClientRecordLine(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    //read Mode
    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }       
        MyFile.close();
    }
    return false;
}
sClient ReadClient() {
    sClient Client;
    cout << "==========================\n";
    cout << "Enter the Account Number ?";
    getline(cin>>ws, Client.AccountNumber);
    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter the PinCode ?";
    getline(cin, Client.PinCode);
    cout << "Enter the Name ?";
    getline(cin, Client.Name);
    cout << "Enter the Phone ?";
    getline(cin, Client.Phone);
    cout << "Enter the Account balance ?";
    cin >> Client.AccountBalance;
    return Client;
}
string  ConvertRecordToLine(sClient Client) {
    string S1 = "";
    string delium = "#//#";
    S1 += Client.AccountNumber + delium;
    S1 += Client.PinCode + delium;
    S1 += Client.Name + delium;
    S1 += Client.Phone + delium;
    S1 += to_string(Client.AccountBalance);
    return S1;
}
void AddDataToFile(string FileName, string line) {
    fstream MyFile;
    MyFile.open(FileName, ios::app | ios::out);
    if (MyFile.is_open()) {
        MyFile << line << endl;
        MyFile.close();
    }
}
void AddClient() {
    sClient Client=ReadClient();
    AddDataToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddNewClients() {
    char AddMore = 'Y';
    cout << "\n===================================\n";
    cout << "\t Added Clients \n";
    cout << "=====================================\n";
    do {

        AddClient();
        cout << "Added New Succssful , Do you want to add more ? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
string ReadAccountNumber() {
    string AccountNumber;
    cout << "please enter the Account Number ?";
    getline(cin>>ws, AccountNumber);
    return AccountNumber;
}
bool FindAccountNumber(string  AccountNumber,vector<sClient> vClients,sClient& Client) {

    for (sClient& C: vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}
void PrintClientCard(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}
bool  MarkForDeletClientByAccounNumber(string AccountNumber, vector<sClient> &vClients) {

    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.Mark = true;
            return true;
        }
    }
    return false;
}
vector<sClient> SaveDataToFileByAccountNumber(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    sClient Client;
    string line;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (C.Mark==false) {
                line = ConvertRecordToLine(C);
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeletClientByAccountNumber(string AccountNumber, vector<sClient>vClients) {
    char Answer = 'Y';
    sClient Client;
    if (FindAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "Are you sure do you want to delet Client ?";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            MarkForDeletClientByAccounNumber(AccountNumber, vClients);
            SaveDataToFileByAccountNumber(ClientsFileName, vClients);
            vClients = LoadClientDataFromFile(ClientsFileName);
            cout << "\ndeleted Successful.";
            return true;
        }

    }
    else
    {
        cout << "They don't Found [" << AccountNumber << "] Account Number ";
        return false;
    }

}
sClient ChangeClientInformation(string AccountNumber) {
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "Enter the PinCode ?";
    getline(cin>>ws, Client.PinCode);
    cout << "Enter the Name ?";
    getline(cin, Client.Name);
    cout << "Enter the Phone ?";
    getline(cin, Client.Phone);
    cout << "Enter the Account balance ?";
    cin >> Client.AccountBalance;
    return Client;

}
bool UpdatedClientByAccountNumber(string AccountNumber, vector<sClient>vClients) {
    char Answer = 'Y';
    sClient Client;
    if (FindAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "Are you sure do you want to Update Client ?";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            for (sClient& C: vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientInformation(AccountNumber);
                    break;
                }
            }

            SaveDataToFileByAccountNumber(ClientsFileName, vClients);
            
            cout << "\nUpdated Successful.";
            return true;
        }

    }
    else
    {
        cout << "They don't Found [" << AccountNumber << "] Account Number ";
        return false;
    }

}
void DeletClients() {
    cout << "\n===================================\n";
    cout << "\t Deleted Clients \n";
    cout << "=====================================\n";
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    DeletClientByAccountNumber(AccountNumber, vClients);
}
void  UpdatedClients() {
    cout << "\n===================================\n";
    cout << "\t Updated Clients \n";
    cout << "=====================================\n";
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    UpdatedClientByAccountNumber(AccountNumber, vClients);
}
void FindClients() {
    sClient Client;
    cout << "\n===================================\n";
    cout << "\t Find Clients \n";
    cout << "=====================================\n";
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    if (FindAccountNumber(AccountNumber, vClients,Client)) {
        PrintClientCard(Client);
    }
    else {
        cout << "They don't Found [" << AccountNumber << "] Account Number ";
    }

}
void Finish() {
    cout << "\n===================================\n";
    cout << "\t Finsh programms \n";
    cout << "=====================================\n";
}
enum enTrans { Deposit = 1, WithDraw = 2, TotalBalance = 3, MainMenuScreen = 4 };
int ReadTrans() {
    int Op = 0;
    cout << "\nChoose what do you want to do? [ 1 to 4 ]?";
    cin >> Op;
    return Op;
}
void GoBackToMainMenue2() {
    cout << "\nPress any Key To go  Trans Main Menue .....\n";
    system("pause>0");
    ShowTransactionMainMenue();

}
void DepositAmount() {
    cout << "----------------------\n";
    cout << "\t Deposit Screen\n";
    cout << "----------------------\n";
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
    sClient client;
    string AccountNumber = ReadAccountNumber();

    while (!FindAccountNumber(AccountNumber, vClients,client)) {
        cout << "Client With " << AccountNumber << " does Not Exist\n";
        AccountNumber = ReadAccountNumber();
    }
    
    PrintClientCard(client);
    int Amount = 0;
    cout << "Please enter Amount Deposit ?";
    cin >> Amount;
    char Answer = 'n';
    cout << "Are you sure Transaction Deposit? Y/N";
    cin >> Answer;

    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.AccountBalance += Amount;
            cout << "\n\n Done Successful Deposit.New balance is : " << C.AccountBalance;
            break;
        }
    }
    SaveDataToFileByAccountNumber(ClientsFileName, vClients);

}
void WithDrawAmount() {
    cout << "----------------------\n";
    cout << "\t WithDraw Screen\n";
    cout << "----------------------\n";
    vector<sClient>vClients = LoadClientDataFromFile(ClientsFileName);
    sClient client;
    string AccountNumber = ReadAccountNumber();

    while (!FindAccountNumber(AccountNumber, vClients, client)) {
        cout << "Client With " << AccountNumber << " does Not Exist\n";
        AccountNumber = ReadAccountNumber();
    }
    PrintClientCard(client);
    int Amount = 0;
    cout << "Please enter Amount WithDraw ?";
    cin >> Amount;
    while(Amount>client.AccountBalance){
        cout << "\n Amount Exceeds the balance,you can withdraw up to : " << client.AccountBalance << endl;
        cout << "\nPlease enter WithDraw Amount ?";
        cin >> Amount;
            
        }
    char Answer = 'n';
    cout << "Are you sure Transaction WithDraw? Y/N";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y') {
        client.AccountBalance -= Amount;
        cout << "\n\n Done Successful WithDraw.New balance is : " << client.AccountBalance;
        SaveDataToFileByAccountNumber(ClientsFileName, vClients);
    }
}
void TotalBalances() {

    sClient Client;
    vector <sClient> vClients = LoadClientDataFromFile(ClientsFileName);
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
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else for (sClient Client : vClients) {
        PrintClientRecordLine(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    int Total = 0;
    for (sClient& C : vClients) {
        Total += C.AccountBalance;
    }
    cout << "\n\n\n\t\t\t\t Total Balance = " << Total << endl;

}
void StartOperation2(enTrans Trans) {
    switch (Trans)
    {
    case Deposit:
        DepositAmount();
        GoBackToMainMenue2();
        break;
    case WithDraw:
        WithDrawAmount();
        GoBackToMainMenue2();
        break;
    case TotalBalance:
        TotalBalances();
        GoBackToMainMenue2();
        break;
    case MainMenuScreen:
        ShowMainMenue();
        break;
    }
}
void ShowTransactionMainMenue() {
    system("Cls");
    cout << "===============================\n";
    cout << "\tTransaction Nain Menue\n";
    cout << "===============================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] WithDraw\n";
    cout << "\t[3]Total Balance.\n";
    cout << "\t[4] Show Main Menue\n";
    cout << "================================";
    StartOperation2(enTrans(ReadTrans()));

}
void StartOperation(enOperation Op) {
    switch (Op)
    {
    case enOperation::ShowClient:
        ShowClientsTable();
        GoBackToMainMenue();
    break;

    case enOperation::AddNewClient:
        AddNewClients();
        GoBackToMainMenue();

        break;
    case enOperation::DeletClient:
        DeletClients();
        GoBackToMainMenue();
        break;
    case enOperation::UpdateClient:
        UpdatedClients();
        GoBackToMainMenue();
        break;
    case enOperation::FindClient:
        FindClients();
        GoBackToMainMenue();
    case enOperation::Transaction:
        ShowTransactionMainMenue();
        break;
    case enOperation::Exit:
        Finish();

        break;

    }

}
    void ShowMainMenue() {
    system("cls");
    cout << "========================================\n";
    cout << "\t Main Menue Screen \n";
    cout << "========================================\n";
    cout << "\t [1] Show Client List.\n";
    cout << "\t [2] Add New Client.\n";
    cout << "\t [3] Delet Client.\n ";
    cout << "\t [4] Update Client.\n ";
    cout << "\t [5] Find Client.\n ";
    cout << "\t [6] Transaction \n ";
    cout << "\t [7] Exit \n ";
    cout << "========================================\n";

    StartOperation(enOperation(ReadOperation()));

}
int main()
{
    ShowMainMenue();
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

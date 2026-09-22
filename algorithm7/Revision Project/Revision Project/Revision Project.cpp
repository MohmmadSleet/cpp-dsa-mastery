

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>

using namespace std;
const string ClientsFileName = "Clients.txt";
void ShowMainMenue();
struct stClients {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBanace;
    bool Mark=false;
};
enum enChoice{ShowCient=1,AddClient=2,DeletClient=3,UpdateClient=4,FindClient=5,Transactions=6,Exit=7};

enChoice ReadChoice() {
    short choice=0;
    cout << "Choose what do you want to do ? [1 to 7] ? \n";
    cin >> choice;
    return enChoice(choice);
}
void GoBackToMainMenue() {
    cout << "\n\nPress any Key to go back main menue....\n";
    system("pause>0");
    ShowMainMenue();
}
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;
    // define a string variable  // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        // store the word
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
        /* erase() until positon and move to next word. */
    }
    if (S1 != "")
    {
        vString.push_back(S1);
        // it adds last word of the string.  
    }
    return vString;
}
stClients  ConvertLineToRecord(string line) {
    vector<string>vSplit = SplitString(line, "#//#");
    stClients Clients;
    Clients.AccountNumber = vSplit[0];
    Clients.PinCode = vSplit[1];
    Clients.Name = vSplit[2];
    Clients.Phone = vSplit[3];
    Clients.AccountBanace = vSplit[4];

    return Clients;
}

vector<stClients>LoadClientsDataFromFile(string FileName) {
    vector<stClients>vClieents;
    stClients Clients;
    string line;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        while ( getline(MyFile, line)) {
            Clients = ConvertLineToRecord(line);
            vClieents.push_back(Clients);

        }
        MyFile.close();
    }
    return vClieents;

}
void PrintClientRecordLine(stClients Client) {
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBanace;
}

void ShowClientsList() {
    stClients Clietns;
    vector<stClients>vClients = LoadClientsDataFromFile(ClientsFileName);
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

    for (stClients& Client : vClients) {
        PrintClientRecordLine(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}
stClients ReadNewClient(vector<stClients>vClients) {

    stClients Clients;
    cout << "Enter the Account Number ? ";
    getline(cin >> ws, Clients.AccountNumber);
    for (stClients& C : vClients) {
        while (C.AccountNumber == Clients.AccountNumber) {
            cout << "Enter the Account Number ? ";
            getline(cin >> ws, Clients.AccountNumber);
        }
    }
    cout << "Enter the PinCode ? ";
    getline(cin, Clients.PinCode);
    cout << "Enter the Name ? ";
    getline(cin, Clients.Name);
    cout << "Enter the Phone ? ";
    getline(cin, Clients.Phone);
    cout << "Enter the Account Balance ? ";
    getline(cin, Clients.AccountBanace);
    return Clients;
}
string ConvertRecordToLine(stClients Clients) {
    string S1 = "";
    string Delium = "#//#";
    S1 += Clients.AccountNumber + Delium;
    S1 += Clients.PinCode + Delium;
    S1 += Clients.Name + Delium;
    S1 += Clients.Phone + Delium;
    S1 += Clients.AccountBanace;
    
    return S1;
}
void AddClientDataToFile(string FileName, string line) {
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << line << endl;
        MyFile.close();
    }


}
void addClient() {
    vector<stClients>vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n=======================\n";
    cout << "\t Add New Client \n";
    cout << "=========================\n";
    stClients Clients = ReadNewClient(vClients);
    AddClientDataToFile(ClientsFileName, ConvertRecordToLine(Clients));
}
void AddNewClients(){
    char AddMore = 'y';
    do {
        cout << "Adding New Client:\n\n";
        addClient();

        cout << "Added client Successful, Do you want to add more ? Y/N ? \n";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}
string ReadAccountNumber() {
    string AccountNumber;
    cout << "Please enter the Accoun Number ? ";
    getline(cin >> ws, AccountNumber);
    
    return AccountNumber;

}
bool FindAccountNumber(string AccountNumber, vector<stClients>vClients, stClients& Clients) {

    for (stClients& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Clients = C;
            return true;
        }
    }
    return false;
}
void PrintClientRecord(stClients Clients) {

    cout << "\n\tAccount Number = " << Clients.AccountNumber;
    cout << "\n\tAccount PinCode = " << Clients.PinCode;
    cout << "\n\tAccount Name = " << Clients.Name;
    cout << "\n\tAccount Phone = " << Clients.Phone;
    cout << "\n\tAccount balance = " << Clients.AccountBanace;
}
bool  MarKClientByAccountNumber(string AccountNumber, vector<stClients>& vClients, stClients Clients) {
    for (stClients& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.Mark = true;
            return true;
        }
    }
    return false;


}
vector<stClients>SaveClientDataByAccountNumber(string FileName, vector<stClients>& vClients, stClients Clients) {
    fstream MyFile;

    MyFile.open(FileName, ios::out);
    string line;
    if (MyFile.is_open()) {
        for (stClients& C : vClients) {
            if (C.Mark == false) {
                line = ConvertRecordToLine(C);
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
bool DeletClientByAccountNumber(string AccountNumber,vector<stClients> vClients) {
    stClients Clients;
    char Answer = 'n';
    if (FindAccountNumber(AccountNumber, vClients, Clients)) {
        PrintClientRecord(Clients);
        cout << "\n\nAre you sure you want Deleted Client ? Y/N";
        cin >> Answer;
            if (Answer == 'Y' || Answer == 'y') {
                MarKClientByAccountNumber(AccountNumber, vClients, Clients);
                SaveClientDataByAccountNumber(ClientsFileName, vClients, Clients);
                vClients = LoadClientsDataFromFile(ClientsFileName);
                cout << "Deleted Cliented succssful . \n";
                return true;
            }
    }
    else {
        cout << "The Account Number(" << AccountNumber << ") is Not Found . \n";
        return false;
    }


}
void DeletClients() {
    cout << "\n=======================\n";
    cout << "\t Delet Client \n";
    cout << "=========================\n";

    vector<stClients>vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();

    DeletClientByAccountNumber(AccountNumber, vClients);

}
stClients ChangeClientRecord(string AccountNumber) {
    stClients Clients;
    Clients.AccountNumber = AccountNumber;
    cout << "Enter the PinCode ? ";
    getline(cin>>ws, Clients.PinCode);
    cout << "Enter the Name ? ";
    getline(cin, Clients.Name);
    cout << "Enter the Phone ? ";
    getline(cin, Clients.Phone);
    cout << "Enter the Account Balance ? ";
    getline(cin, Clients.AccountBanace);
    return Clients;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<stClients> vClients) {
    stClients Clients;
    char Answer = 'n';
    if (FindAccountNumber(AccountNumber, vClients, Clients)) {
        PrintClientRecord(Clients);
        cout << "\n\nAre you sure you want Update Client ? Y/N";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            for (stClients& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
            }
            }

            SaveClientDataByAccountNumber(ClientsFileName, vClients, Clients);
            cout << "Updated Cliented succssful . \n";
            return true;
        }
    }
    else {
        cout << "The Account Number(" << AccountNumber << ") is Not Found . \n";
        return false;
    }

}
void UpdateClients() {
    cout << "\n=======================\n";
    cout << "\t Updated Client \n";
    cout << "=========================\n";

    vector<stClients>vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);
}
void FindClients() {
    vector<stClients>vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    stClients Clients;
    if (FindAccountNumber(AccountNumber, vClients, Clients)) {
        PrintClientRecord(Clients);
        }
    else {
        cout << "The Account Number(" << AccountNumber << ") is Not Found . \n";
    }

}
void ExitFinal() {
    cout << "\n=======================\n";
    cout << "\t Programmms Ends \n";
    cout << "=========================\n";
}


void StartOperating(enChoice Choice) {
    switch (Choice)
    {
    case ShowCient:
        ShowClientsList();
        GoBackToMainMenue();
        break;
    case AddClient:
        AddNewClients();
        GoBackToMainMenue();
        break;
    case DeletClient:
        DeletClients();
        GoBackToMainMenue();
        break;
    case UpdateClient:
        UpdateClients();
        GoBackToMainMenue();
        break;
    case FindClient:
        FindClients();
        GoBackToMainMenue();
        break;
    case Exit:
        ExitFinal();
        break;
    default:
        cout << "Enter erorr";
        break;
    }

}
void ShowMainMenue() {
    system("cls");
    cout << "================================\n";
    cout << "\t\t Main Menue Screen \n";
    cout << "================================\n";
    cout << "\t [1] Show Client List .\n";
    cout << "\t [2] Add New Client .\n";
    cout << "\t [3] Delet Client .\n";
    cout << "\t [4] Update CLient Info .\n";
    cout << "\t [5] Find Client .\n";
    cout << "\t [6] Transactions .\n";
    cout << "\t [7] Exit . \n";
    cout << "===============================\n";
    enChoice Choice = ReadChoice();
    StartOperating(Choice);
}

int main() {
    ShowMainMenue();
    system("pause>0");

    return 0;
}
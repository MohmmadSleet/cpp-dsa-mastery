#pragma once
class clsDeletClientScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void ShowDeletClientScreen() {
        _DrawScreenHeader("\t  Delet Client Screen");
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
            return;
        }

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\n Are you sure you want to delete Client ? Y,N ?";
        char Answer = 'Y';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Deleted()) {
                cout << "\n Client Deleted Successful -)";
                _PrintClient(Client);
            }
            else {
                cout << "\n Error Delete";
            }
        }
	}
};


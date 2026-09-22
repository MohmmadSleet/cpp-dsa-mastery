#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsDepositScreen:protected clsScreen
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
	static string _ReadAccountNumber() {
		cout << "\n\n please enter the account number ? ";
		string Accountnumber = "";
		cin >> Accountnumber;
		return Accountnumber;
	}
public:

	static void ShowDepositScreen() {
		_DrawScreenHeader("\t\  Deposit Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client With ["<<AccountNumber<<"] was not exist ,enter anothe account Number  : ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\n Please enter Deposit Amount ?";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\n\n Are you sure you want to perform transaction ?Y/N?";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Client.Deposit(Amount);
			cout << "\n Amount Deposit Successful";
			cout << "\n New balance is = " << Client.AccountBalance;
		}
		else {
			cout << "\n Operation was Cancelled";
		}
	}

};


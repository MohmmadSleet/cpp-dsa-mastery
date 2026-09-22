#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {

		cout << "\nClient Card :";
		cout << "\n__________________";
		cout << "\n Full Name  : " << Client.FullName();
		cout << "\n Acc.Number : " << Client.AccountNumber();
		cout << "\n Balance : " << Client.AccountBalance;
		cout << "\n__________________\n";

	}
	static string _ReadAccountNumber() {
		cout << "\nPlease enter account Number to transfer From?";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account Number is not found,enter another account Number ?";
			AccountNumber = clsInputValidate::ReadString();

		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}
public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\t Transfer Screen");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}
};


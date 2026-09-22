#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"

class clsLoginScreen:protected clsScreen 
{
private:
	static bool _Login() {
		bool LoginFaild = false;
		string UserName, Password;
		short FaildLoginCount = 0;
		do {
				if (LoginFaild) {
					FaildLoginCount++;
					cout << "\n Invalid User Name/Password!\n\n";
					cout << "\n You have [" << (3 - FaildLoginCount) << "]Trials to Login .\n\n";
				}
				if (FaildLoginCount == 3) {
					cout << "\n You are Locked after 3 failed trials \n\n";
					return false;
				}
			cout << "Enter Username?";
			cin >> UserName;
			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild && FaildLoginCount<3);
		
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		return _Login();

	}

};

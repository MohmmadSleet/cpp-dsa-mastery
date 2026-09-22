#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsManageUsersScreen : protected clsScreen
{
private:
	enum enMangeUsersMenueOptions {

		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static short ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will Be Here.\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeletUserScreen();

	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will Be Here.\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowMangeUsersMenue();
	}


	static void _PerformMangeUsersMenueOption(enMangeUsersMenueOptions Options) {
		switch (Options)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eMainMenue:
		   
			break;
		default:
			break;
		}
	}
public:
	static void ShowMangeUsersMenue() {
		system("cls");
		_DrawScreenHeader("Mange Users Screen");
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Mange Users Menue.\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delet User.\n";
		cout << setw(37) << left << "" << "\t[4] Update Users.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue. \n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMangeUsersMenueOption((enMangeUsersMenueOptions)ReadManageUsersMenueOption());

	}
};


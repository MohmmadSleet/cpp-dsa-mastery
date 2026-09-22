#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public:
    static void ShowDeletUserScreen() {
        _DrawScreenHeader("\t  Delet User Screen");

        string UserName = "";

        cout << "\nPlease Enter Account Number: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n Are you sure you want to delete Client ? Y,N ?";
        char Answer = 'Y';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete()) {
                cout << "\n Client Deleted Successful -)";
                _PrintUser(User);
            }
            else {
                cout << "\n Error Delete";
            }
        }
    }
};


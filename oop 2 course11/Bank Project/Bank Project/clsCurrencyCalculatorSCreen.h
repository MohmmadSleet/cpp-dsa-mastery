#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorSCreen:protected clsScreen
{
private:
    static float _ReadAmount()
    {
        cout << "\nEnter New Amount: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }
    static void _PrintCurrencyCard(clsCurrency Currency, string Title)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static clsCurrency _GetCurrency(string message) {
        string CurrencyCode;
        cout << message;
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            cout << "\n Currency Code is not found ,enter another Cureency code : ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }
    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency
        (Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }


public:
	static void ShowCurrencyCalculatorScreen() {
        char Answer = 'Y';
        while (Answer == 'y' || Answer == 'Y') {
            system("cls");
            _DrawScreenHeader("Currency Calculator Screen");
            clsCurrency CurrencyForm = _GetCurrency("\nPlease enter Currency 1 Code : ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease enter Currency 2 Code : ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyForm, CurrencyTo);

            cout << "\n Do you want to perform another calculator ? y/n ?";
            cin >> Answer;
        }

	}
};


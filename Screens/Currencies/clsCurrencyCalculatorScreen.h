#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"
using namespace std;
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:") {
		cout << Title;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}
	static float _ReadAmount() {
		cout << "Enter Amount to Exchange\n";
		float Amount;
		Amount = clsInputValidate<float>::ReadNumber();
		return Amount;
	}
	static clsCurrency _GetCurrency(string Message) {
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "This Currency Code isn't available try another one:\n";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}
	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1,"Convert from");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);
		cout << Amount << " " << Currency1.CurrencyCode()<< " = " << AmountInUSD << " USD\n";
		if (Currency1.CurrencyCode() == "USD") {
			return;
		}
		cout << "Convert from USD To another";
		float AmountInCurrency = Currency2.ConvertToOtherCurrency(Amount,Currency1);
		cout << Amount << " " << Currency2.CurrencyCode() << " = " << AmountInCurrency << " USD\n";
		_PrintCurrencyCard(Currency2);
	}
public:
	static void ShowCurrencyCalculatorScreen() {
		_DrawScreenHeader("Currency Calculator Screen");
		char Continue = 'Y';
		while (Continue == 'y' || Continue == 'Y') {
			system("cls");
			_DrawScreenHeader("\tUpdate Currency Screen");
			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();
			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}
	}
};


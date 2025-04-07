#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"
using namespace std;
class clsUpdateCurrencyScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}
	static float _ReadRate() {
		cout << "Enter new rate:\n";
		float NewRate = 0;
		NewRate = clsInputValidate<float>::ReadNumber();
		return NewRate;
	}
public:
	static void ShowUpdateCurrencyScreen() {
		string Title = "\tUpdate Currency screen";
		_DrawScreenHeader(Title);
		cout << "Please Enter Currency Code:";
		string CurrencyCode = clsString::UpperAllString(clsInputValidate<string>::ReadString());
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "Currency is not not found,choose another one\n";
			CurrencyCode = clsString::UpperAllString(clsInputValidate<string>::ReadString());
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		char answer = 'n';
		cout << "Are you sure want to update rate of this currency y/n";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			cout << "\n\nUpdate currency rate:";
			cout << "\n_____________________\n";
			Currency.UpdateRate(_ReadRate());
			cout << "Currency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
};


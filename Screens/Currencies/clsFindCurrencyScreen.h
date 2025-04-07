#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<iomanip>
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:
	enum eFindCurrencyOption { eFindByCode = 1, eFindByCountry = 2 };
	static void _PrintCurrency(clsCurrency Currency){
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}
	static void _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)";
			_PrintCurrency(Currency);
		}
		else {
			cout << "This currency code isn't available ";
		}
	}
public:
	static void ShowFindCurrencyScreen() {
		string Title = "\tFind Currency screen";
		_DrawScreenHeader(Title);
		cout << "Choose Find By [1] Code or [2] Country\n";
		short answer = 1;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter Currency Code:\n";
			string CurrencyCode;
			CurrencyCode = clsString::UpperAllString(clsInputValidate<string>::ReadString());
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else {
			cout << "Enter Country:\n";
			string Country;
			Country = clsString::UpperAllString(clsInputValidate<string>::ReadString());
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
		
	}
};


#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<iomanip>
using namespace std;
class clsListCurrenciesScreen:protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\t| " << left << setw(25) <<  Currency.Country();
        cout << "\t| " << left << setw(10) << Currency.CurrencyCode();
        cout << "\t| " << left << setw(45) << Currency.CurrencyName();
        cout << "\t| " << left << setw(10) << Currency.Rate();
    }

public:
    static void ShowListCurrencies() {

        vector<clsCurrency>vCurrencies = clsCurrency::GetListCurrencies();
        string Title = "\t Currencies list screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\t___________________________________________________________________________________________________________________\n";
        cout << "\t| " << left << setw(25) << "Country";
        cout << "\t| " << left << setw(10) << "Code";
        cout << "\t| " << left << setw(45) << "Name";
        cout << "\t| " << left << setw(10) << "Rate(1$)";
        cout << "\n\t_______________________________________________________";
        cout << "____________________________________________________________\n";
        if (vCurrencies.size() == 0) {
            cout << "\t\t\t\tNo currencies available in the system";
        }
        else {
            for (clsCurrency Currency : vCurrencies) {
                _PrintCurrency(Currency);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }
            
    }
};


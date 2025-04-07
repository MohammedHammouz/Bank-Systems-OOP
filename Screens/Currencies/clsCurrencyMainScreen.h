#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
#include<iomanip>
using namespace std;
class clsCurrencyMainScreen:protected clsScreen
{
private:
	enum eCurrenciesMainMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };
    static void _ShowListCurrenciesScreen() {
        /*cout << "List Currencies Screen will be here";*/
        clsListCurrenciesScreen::ShowListCurrencies();
    }
    static void _ShowFindCurrencyScreen() {
        /*cout << "Find Currency Screen will be here";*/
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen() {
        /*cout << "Update Rate Screen will be here";*/
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }
    static void _ShowCurrencyCalculatorScreen() {
        /*cout << "Currency Calculator Screen will be here";*/
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    static void _ShowMainMenueScreen() {
        cout << "List Currecies Screen will be here";
    }
    static void _GoBackToMaiMenue() {
        /*cout << "\n\n Press Any Key to go back to MainMenue...";*/
        /*system("pause>0");*/
        /*ShowCurrencyMenue();*/
    }
    static void _ChoosingOperation(eCurrenciesMainMenueOptions  CurrenciesExchange) {
        

        switch (CurrenciesExchange) {
        case eCurrenciesMainMenueOptions::eListCurrencies:
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToMaiMenue();
                break;
        case eCurrenciesMainMenueOptions::eFindCurrency:
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToMaiMenue();
                break;
        case eCurrenciesMainMenueOptions::eUpdateRate:
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToMaiMenue();
                break;
        case eCurrenciesMainMenueOptions::eCurrencyCalculator:
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToMaiMenue();
                break;
        case eCurrenciesMainMenueOptions::eMainMenue:
                system("cls");
                _ShowMainMenueScreen();
                _GoBackToMaiMenue();
                break;
        
        }

    }
    static short _ReadCurrenciesMainMenueOptions() {
        short Choice;
        cout << setw(37) << left << "" << "Choose what do you want to do?[" << eCurrenciesMainMenueOptions::eListCurrencies << " to " << eCurrenciesMainMenueOptions::eMainMenue << "]";
        Choice = clsInputValidate<int>::ReadNumberBetween(1, 5);
        return (Choice);
    }
public:
    static void ShowCurrencyMenue() {
        system("cls");

        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue Screen" << endl;
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[" << eCurrenciesMainMenueOptions::eListCurrencies << "] List Currencies." << endl;
        cout << setw(37) << left << "" << "\t[" << eCurrenciesMainMenueOptions::eFindCurrency << "] Find Currency." << endl;
        cout << setw(37) << left << "" << "\t[" << eCurrenciesMainMenueOptions::eUpdateRate << "] Update Rate." << endl;
        cout << setw(37) << left << "" << "\t[" << eCurrenciesMainMenueOptions::eCurrencyCalculator << "] Currency Calculator." << endl;
        cout << setw(37) << left << "" << "\t[" << eCurrenciesMainMenueOptions::eMainMenue << "] Main Menue." << endl;
        cout << setw(37) << left << "" << "============================================\n";

        _ChoosingOperation((eCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueOptions());

    }
};


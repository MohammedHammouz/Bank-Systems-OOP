#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include <iomanip>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowTransfer = 4, eTranferLog = 5, eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<int>::ReadNumberBetween(1, 6, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        /*cout << "\n Deposit Screen will be here.\n";*/
        
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        /*cout << "\n Withdraw Screen will be here.\n";*/
        clsWithdrawScreen::ShowWithdawScreen();
    }
    static void _ShowTransferScreen() {
		/*cout << "\n Transfer Screen will be here.\n";*/
		clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen() {
        /*cout << "\n Transfer log Screen will be here.\n";*/
        clsTransferLogScreen::ShowLogScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        /*cout << "\n Balances Screen will be here.\n";*/
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        clsBankClient Client1 = clsBankClient::Find("");
        
        

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTransfer:{
			system("cls");
			_ShowTransferScreen(); 
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenueOptions::eTranferLog: {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            system("cls");
            ShowTransactionsMenue();
            _GoBackToTransactionsMenue();
            break;
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {


        system("cls");
       
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pTranactions)) {
            return;
        }
        
        string Title;
        string SubTitle;
        _DrawScreenHeader(Title= "\t  Transactions Screen", SubTitle = "");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};


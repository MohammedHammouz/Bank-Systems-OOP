
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientsScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include"clsPermissions.h"
#include "clsRegisterLoginScreen.h"
#include"clsCurrencyMainScreen.h"
#include"Global.h"
#include<iomanip>
using namespace std;
class clsMainScreen :protected clsScreen
{

private:
    enum enMainMenue {
        ShowClientLists = 1,
        NewClient = 2,
        DeleteClient = 3,
        UpdateClientInfo = 4,
        FindClient = 5,
        Transaction = 6,
        ManageUser = 7,
		LoginRegister = 8,
        CurrencyExchange=9,
        Logout = 10
    };
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate<string>::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate<float>::ReadNumber();
    }
    static void _GoBackToMaiMenue() {
        cout << "\n\n Press Any Key to go back to MainMenue...";
        system("pause>0");
        ShowMainMenue();
    }
    static void _ShowAddNewClientsScreen() {
        /*cout << "Add new client screen will be here...\n";*/
        clsAddNewClients::AddNewClientsScreen();

    }

    static void _ShowDeleteClientScreen() {
        /*cout << "Delete client screen will be here...\n";*/
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }
    static void _ShowUpdateClientScreen() {
        /*cout << "Update client screen will be here...\n";*/
        clsUpdateClientsScreen::ShowUpdateClientScreen();
    }
    static void _ShowAllClientsScreen() {
        /*cout << "Find client screen will be here...\n";*/
        clsClientListScreen::ShowClientsList();

    }
    static void _ShowFindClientScreen() {
        /*cout << "Find client screen will be here...\n";*/
        clsFindClientScreen::ShowFindClientScreen();
        
    }
    static void _ShowTransactionScreen() {

        /*cout << "Transaction screen will be here...\n";*/
        clsTransactionsScreen::ShowTransactionsMenue();

    }
    static void _ShowManageUserScreen() {

        /*cout << "Manage user screen will be here...\n";*/
        clsManageUsersScreen ManageUsersScreen;
        ManageUsersScreen.ShowManageUserScreen();
    }
    static void _ShowLoginRegisterScreen() {
		clsRegisterLoginScreen::ShowLoginList();
    }
    static void _ShowCurrencyMainScreen() {
        /*cout << "Currency Main screen will be here...\n";*/
        clsCurrencyMainScreen::ShowCurrencyMenue();
    }
    static void _Logout() {

        /*cout << "Logout screen will be here...\n";*/
        CurrentUser = clsUser::Find("", "");
        
    }
    
    static void _ChoosingOperation(enMainMenue  Menue) {
        vector <clsBankClient> vClientRecords;

        switch (Menue) {
        case enMainMenue::ShowClientLists:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::NewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::DeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::UpdateClientInfo:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::FindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::Transaction:
            system("cls");
            _ShowTransactionScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::ManageUser:
            system("cls");
            _ShowManageUserScreen();
            _GoBackToMaiMenue();
            break;
		case enMainMenue::LoginRegister:
			system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMaiMenue();
			break;
        case enMainMenue::CurrencyExchange:
            system("cls");
            _ShowCurrencyMainScreen();
            _GoBackToMaiMenue();
            break;
        case enMainMenue::Logout:
            system("cls");
            _Logout(); 
            break;
        }

    }
    static short _EnterOperationNumber() {
        short number;
        cout << setw(37) << left << "" << "Choose what do you want to do?[" << enMainMenue::ShowClientLists << " to " << enMainMenue::Logout << "]";
        number = clsInputValidate<int>::ReadNumberBetween(1, 9);
        return (number);
    }
    static void _GoBackToMainMenue() {
        clsMainScreen::ShowMainMenue();
    }
public:
   
    static void ShowMainMenue() {
        system("cls");
        
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue Screen" << endl;
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[" << enMainMenue::ShowClientLists << "] Show Client List." << endl;
       cout << setw(37) << left << "" << "\t[" << enMainMenue::NewClient << "] Add New Client." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::DeleteClient << "] Delete Client." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::UpdateClientInfo << "] Update Client Information." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::FindClient << "] Find Client." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::Transaction << "] Transactions." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::ManageUser << "] Managing Users." << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::LoginRegister << "] Login Register" << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::CurrencyExchange << "] Currency Exchange" << endl;
        cout << setw(37) << left << "" << "\t[" << enMainMenue::Logout << "] Logout." << endl;
        cout << setw(37) << left << "" << "============================================\n";

        _ChoosingOperation((enMainMenue)_EnterOperationNumber());

    }

};



#pragma once
using namespace std;
#include"clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPermissions.h"
#include"Global.h"
#include <iostream>
class clsDeleteClientScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteClientScreen() {
        _DrawScreenHeader("\t Delete screen");
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pDeleteClient)) {
            return;
        }
        string AccountNumber = "";
        
        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate<string>::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }



    }
};


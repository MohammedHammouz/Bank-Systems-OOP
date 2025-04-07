#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include"clsClientListScreen.h"
#include "clsAddNewClients.h"
#include"clsDeleteClientScreen.h"
#include"clsPermissions.h"
class clsFindClientScreen
    :protected clsScreen
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
    static void ShowFindClientScreen() {
        _DrawScreenHeader("Find Client Screen");
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pFindClient)) {
            return;
        }
        
        string AccountNumber = "";
        cout << "Enter account number of client\n";
        AccountNumber = clsInputValidate<string>::ReadString();
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
    }
};


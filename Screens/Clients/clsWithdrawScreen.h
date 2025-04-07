#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsString.h"
using namespace std;
class clsWithdrawScreen :protected clsScreen
{
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "_____________________Client Card___________________________\n";
        cout << "|AccountNumber: " << setw(15) << left << Client.AccountNumber();
        cout << "\n|FullName: " << setw(20) << left << Client.FullName();
        cout << "\n|Phone: " << setw(12) << left << Client.Phone;
        cout << "\n|Email: " << setw(20) << left << Client.Email;
        cout << "\n|PinCode: " << setw(10) << left << Client.PinCode;
        cout << "\n|AccountBalance: " << setw(12) << left << Client.AccountBalance;
        cout << "\n_______________________________________________________________\n";

    }
public:
    static void ShowWithdawScreen()
    {
        _DrawScreenHeader("\tWithdraw Screen");
        cout << "Please Enter new client Account Number: " << endl;
        string AccountNumber = clsInputValidate<string>::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate<double>::ReadNumber();
        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};


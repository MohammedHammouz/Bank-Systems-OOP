#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsString.h"
using namespace std;
class clsDepositScreen :protected clsScreen
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
        cout << "_______________________________________________________________\n";

    }
public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate<double>::ReadNumber();
        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
            
        }
    }
};


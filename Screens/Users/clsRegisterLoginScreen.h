#pragma once
using namespace std;
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include <iomanip>
#include"Global.h"
#include<vector>
class clsRegisterLoginScreen:protected clsScreen
{
private:
    static void _PrintLoginRecordLine(clsUser::stLoginRegisterRecord LoginRecord)
    {

        cout << "\t| " << setw(15) << left <<LoginRecord.DateTime;
        cout << "\t| " << setw(20) << left << LoginRecord.UserName;
		cout << "\t| " << setw(20) << left << LoginRecord.Permissions;

    }
public:
    static void ShowLoginList() {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pShowLogInRegister)) {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRegesterRecord = clsUser::GetLoginRegisterList();


        _DrawScreenHeader("\t Login list screen", "\t    (" + to_string(vLoginRegesterRecord.size()) + ") Login(s)");
        

        cout << "\t___________________________________________________________________________________________________________________\n";
        cout << "\t| " << left << setw(15) << "Date time";
        cout << "\t| " << left << setw(20) << "Username";
        cout << "\t| " << left << setw(20) << "Permissions";
        
        cout << "\n\t_______________________________________________________";
        cout << "____________________________________________________________\n";
        if (vLoginRegesterRecord.size() == 0)
            cout << "\t\t\t\tNo Login Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord LoginRegisterRecord : vLoginRegesterRecord)
            {

                _PrintLoginRecordLine(LoginRegisterRecord);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "____________________________________________________________\n";
    }
};


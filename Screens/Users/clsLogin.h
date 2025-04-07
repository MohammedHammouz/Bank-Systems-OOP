#pragma once

#include <iostream>
#include "clsScreen.h"
#include"clsMainScreen.h"
#include <iomanip>
#include"clsUser.h"
#include"Global.h"
#include<fstream>
using namespace std;
class clsLogin :protected clsScreen {
private:
    static  bool _Login() {
        bool LoginFaild = false;
		short FailedLoginCount = 0;
        string Username, Password;
        do {
            if (LoginFaild ) {
                    FailedLoginCount++;
					cout << "\nInvlaid Username/Password!\n\n";
                    cout << "\nYou have " << 3 - FailedLoginCount << " Trails\n\n";
            }
            if (FailedLoginCount == 3) {
                cout << "\nInvlaid Username/Password!\n\n";
                
                cout << "You are locked the account\n";
                return false;
            }
            cout << "Enter Username? ";
            cin >> Username;
            cout << "Enter Password? ";
            cin >> Password;
            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();
          
        } while (LoginFaild );
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }
public:
    static bool ShowLoginScreen() {
		system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return  _Login();
    }
};


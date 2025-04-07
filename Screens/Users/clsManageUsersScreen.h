#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsListUsers.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUser.h"

using namespace std;
class clsManageUsersScreen :protected clsScreen
{
private:
    enum eUserOperations {
        Listusers = 1,
        AddUsers,
        DeleteUser,
        UpdateUser,
        FindUser,
        GoBack
    };
    static void _ListUsers() {
       /* cout << "List users screen will be here ...";*/
        clsListUsers::ShowListUsers();
    }
    static void _AddNewUserScreen() {
        /*cout << "Add New User Screen will be here ...";*/
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _DeleteUserScreen() {
        /*cout << "Delete User Screen will be here ...";*/
        clsDeleteUserScreen::DeleteUser();
    }
    static void _UpdateUserScreen() {
        /*cout << "Update User Screen will be here ...";*/
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _FindUserScreen() {
        /*cout << "Find User Screen will be here ...";*/
        clsFindUserScreen::ShowFindUserScreen();
    }
    
    static void _GoBackToMainMenue() {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUserScreen();

    }

   
public:
    static void ShowManageUserScreen() {
        _DrawScreenHeader("Manage User Screen");
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pManageUsers)) {
            return;
        }
        
        cout << setw(37) << left << "" << "" <<  "============================================\n";
        cout << setw(37) << left << "" << "\t\t\tManage User Screen" << endl;
        cout << setw(37) << left << "" << "" << "============================================\n";
        cout << setw(37) << left << "" << "" << "\t[1] List Users." << endl;
        cout << setw(37) << left << "" << "" << "\t[2] Add New User." << endl;
        cout << setw(37) << left << "" << "" << "\t[3] Delete User." << endl;
        cout << setw(37) << left << "" << "" << "\t[4] Update User." << endl;
        cout << setw(37) << left << "" << "" << "\t[5] Find User." << endl;
        cout << setw(37) << left << "" << "" << "\t[6] Main Menue." << endl;
        cout << setw(37) << left << "" << "============================================\n";
        ChoosingUserScreenOperation((eUserOperations)clsInputValidate<int>::ReadNumberBetween(1, 6));
    }
    static void ChoosingUserScreenOperation(eUserOperations  Permessions) {
        
        switch (Permessions) {
        case eUserOperations::Listusers:
            system("cls");
            _ListUsers();
            _GoBackToMainMenue();
            break;
        case eUserOperations::AddUsers:
            system("cls");
            _AddNewUserScreen();
            _GoBackToMainMenue();
            break;
        case eUserOperations::DeleteUser:
            system("cls");
            _DeleteUserScreen();
            _GoBackToMainMenue();
            break;
        case eUserOperations::UpdateUser:
            system("cls");
            _UpdateUserScreen();
            _GoBackToMainMenue();
            break;
        case eUserOperations::FindUser:
            system("cls");
            _FindUserScreen();
            _GoBackToMainMenue();
            break;
        case eUserOperations::GoBack:
            
            break;
        }
    }
};


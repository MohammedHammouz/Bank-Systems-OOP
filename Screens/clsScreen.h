#pragma once
using namespace std;
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include "clsDate.h"
#include <fstream>
#include "clsInputValidate.h";
#include "clsString.h";
#include<vector>
class clsScreen{
protected:
    
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
	
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
		
		cout<<"\t\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t\tDate:" << clsDate::DateToString(clsDate()) << endl;
    }
   static bool CheckAccessRights(clsUser::enMainMenuePermissions Permissons) {
	        
        if (!CurrentUser.CheckAccessPermission(Permissons)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\t\t\t\t\tThis page is denied access\n";
            cout << "\t\t\t\t\t______________________________________";
            return false;
        }
        else {
            return true;
        }

    }

};
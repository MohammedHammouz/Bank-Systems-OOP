#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindUserScreen:protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}
public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("Find User screen");
		cout << "Enter username\n";
		string UserName = clsInputValidate<string>::ReadString();
		clsUser User = clsUser::Find(UserName);
		
		_PrintUser(User);
	}
};


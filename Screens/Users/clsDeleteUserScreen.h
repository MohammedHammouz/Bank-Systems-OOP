#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsPerson.h"
#include"Global.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
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
	static void DeleteUser() {
		
		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate<string>::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		cout << "\nAre you sure you want to delete this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}
	}


};


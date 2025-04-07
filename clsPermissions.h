#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsUser.h"
using namespace std;

class clsPermissions
{
    
    struct sUsers {
        string user;
        string password;
        int permesion = -1;
        bool MarkUserDelete = false;
    };
    sUsers CurrentUser;
    enum enMainMenuePermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient
        = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32,
        pManageUsers = 64
    };
public:
    
    bool CheckAccessPermission(clsUser::enMainMenuePermissions Permission)
    {

        if (CurrentUser.permesion == enMainMenuePermissions::eAll)
            return true;
        if ((Permission & CurrentUser.permesion) == Permission)
            return true;
        else
            return false;
    }
};


#pragma once
#include <iostream>
#include <string>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
extern clsUser CurrentUser;
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }


    cout << "\n\t\t\t\t\t__________________________\n";

    cout << "\n\t\t\t\t User: " << CurrentUser.UserName << "\n";
    cout << "\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n";
    
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }


    static bool CheckAccessRights(clsUser::enPermissions Permission) {
        if (!CurrentUser.CheckAccessPermission(Permission)) {
            cout << "\t\t\t\t____________________________________\n";
            cout << "\n\n\t\t\t  Access Denied !Contact Your Admin\n";
            cout << "\n\t\t\t\t____________________________________\n";
            return false;
        }
        else {
            return true;
        }


    }

};

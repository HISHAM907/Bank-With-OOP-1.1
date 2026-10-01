/*#pragma once

#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsDate.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
extern clsUser CurrentUser;
using namespace std; 
//class clsMainScreen;
class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()//it was void 
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;
        string Username, Password;
        do
        {
            if (LoginFaild) {
                FaildLoginCount++;

                cout << "\nInvalid Username/Password!";
                cout << "You Have" << (3 - FaildLoginCount) << " Trials to login.\n\n";

            }
            if (FaildLoginCount == 3) {
                cout << "\n Your Are Locked after Faild trails \n\n";
                return false;
            }
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
            }    
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        //return true;
    }   
   
public:


    static bool ShowLoginScreen()//was void ,we redifined it from void to countfaild login
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};*/

#pragma once
#include<iostream>
#include<string>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
#include<iomanip>
extern clsUser CurrentUser;
using namespace std;
class clsLoginScreen :protected clsScreen
{

    static void _LogInScreen()
    {
        bool LogInFalid = false;
        //clsUser LogIn;
        string Password, UserName;
        do {
            
            
            cout << "Enter Username?";
            cin >> UserName;
            cout << "Enter Password?";
            cin >> Password;
           // clsUser CurrentUser = clsUser::Find(UserName, Password);
            //LogInFalid = CurrentUser.IsEmpty();
            

             CurrentUser = clsUser::Find(UserName, Password);
             LogInFalid = CurrentUser.IsEmpty();
            
             if (LogInFalid)
            {
                cout << "Invalid Password/UserName\n";
            }

        } while (LogInFalid);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        //return true;
    }

public:

    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\tLog In Screen");
        _LogInScreen();

    }



};
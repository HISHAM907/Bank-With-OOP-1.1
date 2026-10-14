
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "validation.h"
using namespace std;
class clsWithdrawScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Withdraw = clsBankClient::Find(AccountNumber);
        _PrintClient(Withdraw);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Withdraw.WithDraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Withdraw.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Withdraw.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};/*
#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "validation.h"
#include "clsDepsitScreen.h"
#include "clsWithdrawScreen.h"
#include <iomanip>
using namespace std;
class clsWithdrawScreen :protected clsScreen
{
static void PrintClientInfo(clsBankClient Client)
{
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << Client.FirstName;
    cout << "\nLastName    : " << Client.LastName;
    cout << "\nFull Name   : " << Client.FullName();
    cout << "\nEmail       : " << Client.Email;
    cout << "\nPhone       : " << Client.Phone;
    cout << "\nAcc. Number : " << Client.AccountNumber();
    cout << "\nPassword    : " << Client.PinCode;
    cout << "\nBalance     : " << Client.AccountBalance;
    cout << "\n___________________\n";

}

static string _ReadAccountNumber()
{

    cout << "Please Enter your Account Number\n";
    string AccountNumber ;
    cin >> AccountNumber;
    return AccountNumber;
}



public:


static void ShowWithdrawScreen()
{
    _DrawScreenHeader("\tWithDraw Screen");
    string AccountNumber = _ReadAccountNumber();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "InValid Account Number , Please Enter Anthor AcountNumber: \n";
        AccountNumber = _ReadAccountNumber();
    }

   
    clsBankClient WithDrawClient = clsBankClient::Find(AccountNumber);
    PrintClientInfo(WithDrawClient);
    int Amount = clsInputValidate::ReadIntNumber("Please Enter Amount:\n");
    char Answer = 'n';
    cout << "Are You sure You Want To Perform This Transaction:\n";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y') {
        if (WithDrawClient.WithDraw(Amount))
        {
            cout << "Amount WithDraw Succefully...\n ";
            cout << "New Balanced is " << WithDrawClient.AccountBalance;
        }
        else {
            cout << "\nCannot withdraw, Insuffecient Balance!\n";
            cout << "\nAmout to withdraw is: " << Amount;
            cout << "\nYour Balance is: " << WithDrawClient.AccountBalance;

        }
    }
        else {

            cout << "The Operation was Canced Succefully.\n";

        }



}


};

 */
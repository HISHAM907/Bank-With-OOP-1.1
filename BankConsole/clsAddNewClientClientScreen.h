#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "Global.h"
#include "validation.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewClientClientScreen: protected clsScreen
{
    
static void _PrintClientRecordLine(clsBankClient Client) {

    cout << "|" << setw(18) << left << Client.AccountNumber();
    cout << "|" << setw(24) << left << Client.FullName();
  
    cout << "|" << setw(15) << left << Client.AccountBalance;
     cout << "|  " << setw(12) << left << Client.Phone;
    cout << "|  " << setw(20) << left << Client.Email;
    cout << "|  " << setw(10) << left << Client.PinCode;
   
}
static void _FindClientInfo(clsBankClient& Client)
{
    cout << "\n Enter FirestName: ";
    Client.FirstName = clsInputValidate::ReadString();


    cout << "\n Enter lastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\n Enter email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\n Enter phone: ";
    Client.Phone = clsInputValidate::ReadString();
    cout << "\n Enter pincode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\n Enter AccountBalance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();


}
public:
   
static void AddNewClient()
{
    if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
        return;
    }
   _DrawScreenHeader("Add New Client Info");

    string AccountNumber = "";
    cout << "please enter accountnumber to add new client:";
     AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "this account number is excit ,please enter anther account Number:\n";
        AccountNumber= clsInputValidate::ReadString();
    }
    clsBankClient Newclient = clsBankClient::GetAddNewClientObject(AccountNumber);
   // client3.AccountNumber = clsInputValidate::ReadString();

    _FindClientInfo(Newclient);
   
    
    clsBankClient::enSaveResults  svaeresult;
    svaeresult = Newclient.Save();
    switch (svaeresult) {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "the new client info saved succefully:";
        _PrintClientRecordLine(Newclient);
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "the new client doest saved succefully:";
        break;
    }
    case clsBankClient::enSaveResults::svFailAccountNumberExists:
    {
        cout << "Error Account Was not Saved becouse account number:";
        break;
    }



    }

}


};/*
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "Validation.h"
#include <iomanip>
using namespace std;
class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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

public:

    static void ShowAddNewClientScreen()
    {

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFailAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};*/



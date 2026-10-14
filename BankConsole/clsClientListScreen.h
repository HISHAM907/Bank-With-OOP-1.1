#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
#include "Global.h"
#include "clsScreen.h"
#include "validation.h"
using namespace std;
class clsClientListScreen:protected clsScreen
{
static void _FindClientInfo(clsBankClient & Client)
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
static void _PrintClientRecordLine(clsBankClient Client) {
    cout << "|" << setw(18) << left << Client.AccountNumber();
    cout << "|" << setw(24) << left << Client.FullName();
    cout << "|" << setw(12) << left << Client.AccountBalance;
    cout << "|" << setw(15) << left << Client.Phone;
    cout << "|" << setw(15) << left << Client.Email;
    cout << "|" << setw(15) << left << Client.PinCode;
}
public:

static void ShowClientList()
{
    if (!CheckAccessRights(clsUser::enPermissions::pListClients)) {
        return;
    }
    double balances = 0;
    vector<clsBankClient>vclient = clsBankClient::GetClientslist();
    string Title = "\t  Client List Screen  ";
    string SubTitle = "\t ("  +  to_string(vclient.size())+") client(s)";
    _DrawScreenHeader(Title, SubTitle);

        cout << "                                   Client list () client("<<vclient.size()<<").                                      \n ";
        cout << "________________________________________________________________________________________________________________________\n";
        cout << "|   " << left << setw(15) << "Account number";
        cout << "|   " << left << setw(21) << "Client Name";
        cout << "|   " << left << setw(12) << "Balance ";
        cout << "|  " << left << setw(15) << "Phone ";
        cout << "|  " << left << setw(15) << "Email ";
        cout << "|  " << left << setw(15) << "Pin Code";
      
        cout << endl;
        if (vclient.size() == 0)
            cout << "\t\t\t\t No Clients Available In the System!";
        else
            for (clsBankClient client : vclient)
            {
                _PrintClientRecordLine(client);
                
                cout << endl;
            }
double totalbalance = clsBankClient::GetTotalBalances();
        cout << "                               The Total balance is:("<< totalbalance<<")                               \n";
  cout << "_______________________________________________________________________________________________________________________________\n_";
}

};





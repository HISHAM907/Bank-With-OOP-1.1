#include <iostream>
#include "clsLoginScreen.h"
#include "validation.h"
#include "clsMainScreen.h"
using namespace std;  
int main()
{
   
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    system("pause>0");
    return 0;
}
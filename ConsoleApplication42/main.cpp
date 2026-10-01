#include <iostream>
#include "clsLoginScreen.h"
#include "validation.h"
#include "clsMainScreen.h"
using namespace std;  
int ReadNumber(string Message) {
    cout << Message;
    int Num1=clsInputValidate::ReadIntNumber();
    return Num1;
}

int ReverseNumber(int Num1)
{
    int Count,CountNum=0;
    do 
    {
        Count = Num1 % 10;
        Num1 = Num1 / 10;
        CountNum = CountNum*10 + Count;
    } while (Num1 > 0);
    return CountNum;

}
bool IsPlandromeNumber(int Num1)
{

    return Num1 == ReverseNumber(Num1);

}
int main()
{
    int Num1 = ReadNumber("please enter a number?");
    cout << IsPlandromeNumber(Num1);



   // reflectIntNumber(ReverseNumber(ReadNumber("Please enter A number:")));
    system("pause>0");
    return 0;
}
// Code by Dr.Byun, modified by William Svea-Lochert
// A driver program for the Account class.

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main( )
{
    Account tomAccount;
    Account johnAccount;
    
    tomAccount.setAccount("Tom Smith", 1234, 1, 1000.00);
    johnAccount.setAccount("John Doe", 2000, 1, 2000.00);
    
    tomAccount.deposit(500.0);
    tomAccount.withdrawal(2500.0);
    
    johnAccount.deposit(500.0);
    johnAccount.withdrawal(1500.0);
    
    tomAccount.displayAccountInfo();
    johnAccount.displayAccountInfo();
    
    return 0;
}
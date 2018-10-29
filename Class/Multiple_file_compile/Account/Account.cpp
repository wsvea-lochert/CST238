// Code by Dr.Byun, modified by William Svea-Lochert
// Implementation file for the Account class.

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

bool Account::setAccount(string newName, int newNumber, int newType, double newBalance)
{
    name = newName;
    number = newNumber;
    if (newType == 1 || newType == 2)
    {
        type = newType;
    }
    else
    {
        cout << "Error: Incorrect account type." << endl;
        return false;
    }
    if (newBalance < 0.0)
    {
        cout << "Error: Negative balance is not acceptable." << endl;
        return false;
    }
    else
    {
        balance = newBalance;
    }
    
    return true;
}


bool Account::deposit(double amount)
{
    if (amount < 0.0) 
    {
        cout << "Error: No negative amount to deposit." << endl;
        return false;
    }
    else
    {
        balance += amount;
        return true;
    }
}


bool Account::withdrawal(double amount)
{
    if (amount > balance) 
    {
        cout << "Error: insufficient balance to withdraw." << endl;
        return false;
    }
    else 
    {
        balance -= amount;
        return true;
    }
}


void Account::displayAccountInfo( )
{
    cout << "\n======================================" << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Number: " << number << endl;
    cout << "Account Type: " << type << endl;
    cout << "Current Balance: " << balance << endl;
}

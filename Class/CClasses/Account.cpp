// A sample bank account to explain the Class concept in C++.
// A bank account is composed of the account holder's name, 
// account number, account type (= checking (1) or saving (2)), 
// and current balance.

#include <iostream>
#include <string>
using namespace std;

class Account
{
public:

    bool setAccount(string newName, int newNumber, int newType, double newBalance);
    bool deposit(double amount);
    bool withdrawal(double amount);
    void displayAccountInfo( );
    bool hasMonthlyFee();

private:
    string name;     // account holder's name
    int number;      // account number
    int type;        // account type: 1 - checking, 2 - saving
    double balance;  // current balance of the account
    
};

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
    
    tomAccount.hasMonthlyFee();
    
    return 0;
}

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

bool Account::hasMonthlyFee()
{
    if(balance < 1500)
    {
        cout << "client has monthly fee" << endl;
        return true;
    }
    else{
        cout << "client does not have monthly fee" << endl;
        return false
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
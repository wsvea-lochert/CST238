/*
 * Title: Customer.cpp / Project 2
 * Abstract: This program is a bank simulation program using a array of pointer to hold customers
             and a struct to create the accounts of type checking and savings. There is several 
             functions to utalize in this program to trasfere money, find customers, read customer
             data from a file and create the correct type of account corresponding to what is in the file.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 27/11/2018
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include<limits>
#include "Customer.h"
using namespace std;

Customer::Customer(string newFirstName, string newLastName, int newSSN): firstName(newFirstName), lastName(newLastName), ssn(newSSN)
{}

bool Customer::setSavingsAccount(string newFirstName, string newLastName, int newSSN, int accountType, int newAccountNumber, double newBalance)
{
    if(savingsAccount != nullptr)
    {
        // Account Creation Failed – Tom Smith cannot have two savings accounts.
        cerr << "Account Creation Failed – " << newFirstName << " " << newLastName << " can't have two savings accounts." << endl;
        return false;
    }
    
    else if(savingsAccount == nullptr)
    {
        //cerr << "kommer jeg hit da?"<<endl;
        savingsAccount = new acc_ptr;
        savingsAccount->accType = accountType;
        savingsAccount->balance = newBalance;
        savingsAccount->accountNumber = newAccountNumber;
        savingsAccount->accountSSN = newSSN;
        
        return true;
    }
    return false;
}

bool Customer::setCheckingAccount(string newFirstName, string newLastName, int newSSN, int accountType, int newAccountNumber, double newBalance)
{
    if(checkingAccount != nullptr)
    {
        // Account Creation Failed – Tom Smith cannot have two checking accounts.
        cerr << "Account Creation Failed – " << newFirstName << " " << newLastName << " can't have two checking accounts." << endl;
        return false;
    }
    else
    {
        checkingAccount = new acc_ptr;
        checkingAccount->accType = accountType;
        checkingAccount->balance = newBalance;
        checkingAccount->accountNumber = newAccountNumber;
        checkingAccount->accountSSN = newSSN;
        
        return true;
    }
}

bool accountValidation(Customer *customer_arr[], string tempFirstName, string tempLastName, int tempSSN, int tempAccountNumber)
{
    bool controll = true;
    
    for(int k = 0; k < CUSTOMER_CAPASITY; k++)
    {
        if(customer_arr[k] != nullptr)
        {
            if(customer_arr[k]->checkingAccount != nullptr && customer_arr[k]->checkingAccount->accountNumber == tempAccountNumber)
            {
                controll = false;
            }
            else if(customer_arr[k]->savingsAccount != nullptr && customer_arr[k]->savingsAccount->accountNumber == tempAccountNumber)
            {
                controll = false;
            }
        }
        
    }
    //cerr << " accNumCheck result: " << controll << endl;
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            //cerr << controll << endl;
            if(controll == false)
            {
                cerr << "Account Creation Failed – Account number " << tempAccountNumber << " already exists." << endl;
                return false;
            }
            else if(customer_arr[i]->ssn == tempSSN && customer_arr[i]->firstName != tempFirstName && customer_arr[i]->lastName != tempLastName)
            {
                // cerr << "kommer jg hit?" << endl;
                cout << "Account Creation Failed – A customer with SSN " <<  tempSSN  << " already exists." << endl;
                return false;
            }
        }
    }
    return true;
}

int exsistingCustomer(Customer *customer_arr[], string tempFirstName, string tempLastName, int tempSSN)
{
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->firstName == tempFirstName && customer_arr[i]->lastName == tempLastName && customer_arr[i]->ssn == tempSSN)
            {
                return i;
            }
        }
        
    }
    //cerr << "hit?"<<endl;
    return -1;
}

void readFile(Customer *customer_arr[])
{
    // Variables to assign to the new customer.
    string filename;
    string tempFirstName;
    string tempLastName;
    int tempSSN;
    int tempAccountNumber;
    int tempAccountType;
    double tempBalance;
    int size;
   
    cout << "Enter filename: ";
    cin >> filename;
    cout << "Read data..." << endl;
    
    ifstream myfile (filename);
    
    
    if(myfile.fail())//if file fails to open
    {
        //TODO : PROMPT READFILE AGIEN;
        cerr << "Error: file not found, exiting program" << endl;
        exit(1);
    }
    
    myfile >> size; //read size of the file.
    
    for (int i = 0; i < size; i++)  //loop through file and assing temp variables then using constructor to create a new customer.
    {
        myfile >> tempSSN;
        myfile >> tempFirstName;
        myfile >> tempLastName;
        myfile >> tempAccountNumber;
        myfile >> tempAccountType;
        myfile >> tempBalance;
        
        //cout << tempSSN << " " << tempFirstName << " " << tempLastName << " " << tempAccountNumber << " " << tempAccountType << " " << tempBalance << endl;

        int exsistingCustomerIndex = exsistingCustomer(customer_arr, tempFirstName, tempLastName, tempSSN);
        
        if(accountValidation(customer_arr, tempFirstName, tempLastName, tempSSN, tempAccountNumber))
        {
            if(exsistingCustomerIndex != -1 && tempAccountType == 2) // if customer is in the system, and wants a savings account
            {
               // cout << tempFirstName << " is in the system, setting new savingsAccount" << endl;
                customer_arr[exsistingCustomerIndex]->setSavingsAccount(tempFirstName, tempLastName, tempSSN, tempAccountType, tempAccountNumber, tempBalance);
            }
            else if(exsistingCustomerIndex != -1 && tempAccountType == 1) // if customer is in the system and wants a checking account
            {
               // cout << tempFirstName << " is in the system, setting new checkingAccount" << endl;
                customer_arr[exsistingCustomerIndex]->setCheckingAccount(tempFirstName, tempLastName, tempSSN, tempAccountType, tempAccountNumber, tempBalance);
            }
            else
            {
                int index = findOpenSpot(customer_arr);
                
                if(index != -1)
                {
                    customer_arr[index] = new Customer(tempFirstName, tempLastName, tempSSN);
                }
                
                if(tempAccountType == 1)
                {
                    customer_arr[index]->setCheckingAccount(tempFirstName, tempLastName, tempSSN, tempAccountType, tempAccountNumber, tempBalance);
                   // cout << tempFirstName << " " << tempLastName << " now has a checking account" <<  endl;
                }
                else if(tempAccountType == 2)
                {
                    customer_arr[index]->setSavingsAccount(tempFirstName, tempLastName, tempSSN, tempAccountType, tempAccountNumber, tempBalance);
                    //cout << tempFirstName << " " << tempLastName << " now has a savings account" <<  endl;
                }
                else
                {
                    cerr << "Account could not be created " << tempAccountType << " is not a valid account type." << endl;
                }
            }
        }
        //cerr << "reading next customer!" << endl;
    }
    cout << "done."<<endl;
}

int findOpenSpot(Customer *customer_arr[])
{
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] == nullptr)
        {
            return i;
        }
    }
    cerr << "Account could not be created, not enough space in bank" << endl;
    return -1;
}

bool findAccount(Customer *customer_arr[], int newAccountNumber)
{
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                if(customer_arr[i]->checkingAccount->accountNumber == newAccountNumber)
                {
                    return true;
                }
            }
            else if(customer_arr[i]->savingsAccount != nullptr)
            {
                if(customer_arr[i]->savingsAccount-> accountNumber == newAccountNumber)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool closeAccount(Customer *customer_arr[])
{
    
    int closingAccountNumber;
    int closingSSN;
    
    cout << "Enter Account Number: ";
    cin >> closingAccountNumber;
    
    //check if the account number exsists in the system.
    bool accountNumberCheck = findAccount(customer_arr, closingAccountNumber);
    
    if(!accountNumberCheck)
    {
        cout << "Incorrect account number." << endl;
        return false;
    }
    
    cout << "Enter Customer SSN: ";
    cin >> closingSSN;
    cout << "\n";
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                if(customer_arr[i]->checkingAccount->accountNumber == closingAccountNumber)
                {
                    if(customer_arr[i]->ssn == closingSSN)
                    {
                        double printBalance = customer_arr[i]->checkingAccount->balance;
                        
                        cout << "Account closed." << endl;
                        cout << "    Name: " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << "\n" 
                             << "    Account Number: " << customer_arr[i]->checkingAccount->accountNumber << "\n"
                             << "    Account Type: Checking\n" << "    Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                        
                        delete customer_arr[i]->checkingAccount;
                        customer_arr[i]->checkingAccount = nullptr;
                        accountNumberCheck = true;
                    }
                    
                    else
                    {
                        cerr << "Incorrect SSN" << endl;
                        return false;
                    }
                }
            }
            if(customer_arr[i]->savingsAccount != nullptr)
            {
                if(customer_arr[i]->savingsAccount->accountNumber == closingAccountNumber)
                {
                    if(customer_arr[i]->ssn == closingSSN)
                    {
                        double printBalance = customer_arr[i]->savingsAccount->balance;
                        
                        cout << "Account closed." << endl;
                        cout << "   Name: " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << "\n" 
                             << "   Account Number: " << customer_arr[i]->savingsAccount->accountNumber << "\n"
                             << "   Account Type: Savings\n" << "   Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                        
                        delete customer_arr[i]->savingsAccount;
                        customer_arr[i]->savingsAccount = nullptr;
                        accountNumberCheck = true;
                    }
                    //if the ssn is incorect
                    else
                    {
                        cerr << "Incorrect SSN" << endl;
                        return false;
                    }
                    
                }  
            }
            
            // if the customer has no accounts left, he or she will be deleted.
            if(customer_arr[i]->savingsAccount == nullptr && customer_arr[i]->checkingAccount == nullptr)
            {
                cout << "Customer " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << " is also deleted" << endl;
                delete customer_arr[i];
                customer_arr[i] = nullptr;
                break;
            }
        }
    }
    return true;
}

string Customer::doublePrinter(double value) 
{
    stringstream stream;
    stream << fixed << setprecision(2) << value;
    return stream.str();
}

void findCustomerViaSSN(Customer *customer_arr[])
{
    int ssnToFind;
    bool found = false;
    cout << "Enter SSN: ";
    cin >> ssnToFind;
    cout << endl;
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->ssn == ssnToFind)
            {
                cout << "   Name: " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << endl;
                
                if(customer_arr[i]->checkingAccount != nullptr)
                {
                    double printBalance = customer_arr[i]->checkingAccount->balance;
                    
                    cout << "   Account Number: " << customer_arr[i]->checkingAccount->accountNumber << endl
                         << "   Account Type: Checking\n" << "   Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                    
                    found = true;
                }
                
                cout << endl;
                
                if(customer_arr[i]->savingsAccount != nullptr)
                {
                    double printBalance = customer_arr[i]->savingsAccount->balance;
                    
                    cout << "   Account Number: " << customer_arr[i]->savingsAccount->accountNumber << endl
                         << "   Account Type: Savings\n" << "   Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                    
                    found = true;
                }
            }
        }
    }
    if(!found)
    {
        cerr << "No customer with the SSN." << endl;
    }
}

void findCustomerViaLastName(Customer *customer_arr[])
{
    string lastNameToFind;
    bool found = false;
    cout << "Enter lastname: ";
    cin >> lastNameToFind;
    
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->lastName == lastNameToFind)
            {
            //cout << endl;
            cout << "   Name: " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << endl;
                
                if(customer_arr[i]->checkingAccount != nullptr)
                {
                    double printBalance = customer_arr[i]->checkingAccount->balance;
                    
                    cout << "   Account Number: " << customer_arr[i]->checkingAccount->accountNumber << endl
                         << "   Account Type: Checking\n" << "  Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                    cout << endl;
                    found = true;
                }
                
                //cout << endl;
                
                if(customer_arr[i]->savingsAccount != nullptr)
                {
                    double printBalance = customer_arr[i]->savingsAccount->balance;
                    
                    cout << "   Account Number: " << customer_arr[i]->savingsAccount->accountNumber << endl
                         << "   Account Type: Savings\n" << "  Balance: $" << customer_arr[i]->doublePrinter(printBalance) << endl;
                    cout << endl;
                    found = true;
                } 
            }
        }
    }
    if(!found)
    {
        cerr << "There is no customer with this lastname." << endl;
    }
}

void findCustomerViaAccountNumber(Customer *customer_arr[])
{
    bool found = false;
    int index;
    int accountNumberToFind;
    cout << "Enter an account number: ";
    cin >> accountNumberToFind;
    cout << endl;
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                if(customer_arr[i]->checkingAccount->accountNumber == accountNumberToFind)
                {
                    index = i;
                    found = true;
                }
            }
            if(customer_arr[i]->savingsAccount != nullptr)
            {
                if(customer_arr[i]->savingsAccount->accountNumber == accountNumberToFind)
                {
                    index = i;
                    found = true;
                }
            }
        }
    }
    
    if(found)
    {
        cout << "   Name: " << customer_arr[index]->firstName << " " << customer_arr[index]->lastName << endl;
        
        if(customer_arr[index]->checkingAccount != nullptr)
        {
            double printBalance = customer_arr[index]->checkingAccount->balance;
                    
            cout << "   Account Number: " << customer_arr[index]->checkingAccount->accountNumber << endl
                 << "   Account Type: Checking\n" << "   Balance: $" << customer_arr[index]->doublePrinter(printBalance) << endl;
        }
        
        cout << endl;
        
        if(customer_arr[index]->savingsAccount != nullptr)
        {
            double printBalance = customer_arr[index]->savingsAccount->balance;
                    
            cout << "   Account Number: " << customer_arr[index]->savingsAccount->accountNumber << endl
                 << "   Account Type: Savings\n" << "   Balance: $" << customer_arr[index]->doublePrinter(printBalance) << endl;
        }
    }
    else
    {
        cerr << "There is not accounts with the account number " << accountNumberToFind << endl;
    }
}

void customerInformation(Customer *customer_arr[])
{
    int option;
    cout << "SSN(1)/Last Name(2)/Account Number(3): ";
    cin >> option;
    switch(option){
        case 1:
            findCustomerViaSSN(customer_arr);
            break;
        case 2:
            findCustomerViaLastName(customer_arr);
            break;
        case 3:
            findCustomerViaAccountNumber(customer_arr);
            break;
        default:
            cerr << "Invalid input" << endl;
            customerInformation(customer_arr);
    }
}

void sortOnSSN(Customer *tempArr[])
{
   for(int i = 0; i < CUSTOMER_CAPASITY-1; i++)
   {
       for(int j = 0; j < CUSTOMER_CAPASITY-i-1; j++)
       {
           if(tempArr[j] != nullptr && tempArr[j+1] != nullptr){
            if(tempArr[j]->ssn > tempArr[j+1]->ssn)
                {
                    Customer * temp = tempArr[j];
                    tempArr[j] = tempArr[j+1];
                    tempArr[j+1] = temp;
                }
           }
           
       }
   }
}

void bankInfo(Customer *customer_arr[])
{
    bool found = false;
    int accounts = 0;
    int customers = 0;
    double totalBalance = 0;
    
    for(int k = 0; k < CUSTOMER_CAPASITY; k++){
        if(customer_arr[k] != nullptr){
            customers++;
            if(customer_arr[k]->checkingAccount != nullptr){
                accounts++;
            }
            
            if(customer_arr[k]->savingsAccount != nullptr){
                accounts++;
            }
        }
    }
    
    if(accounts > 0)
        cout << "Number of accounts: " << accounts << endl;
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                double balancePrint = customer_arr[i]->checkingAccount->balance;
                
                cout << "   " << customer_arr[i]->checkingAccount->accountNumber << ": $" << customer_arr[i]->doublePrinter(balancePrint) << " (Checking)"<< endl;
                found = true;
            }
        }
    }
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->savingsAccount != nullptr)
            {
                double balancePrint = customer_arr[i]->savingsAccount->balance;
                
                cout << "   " << customer_arr[i]->savingsAccount->accountNumber << ": $" << customer_arr[i]->doublePrinter(balancePrint) << " (Saving)"<< endl;
                found = true;
            }
        }
    }
    
    if(customers > 0)
        cout << "\nNumber of customers: " << customers << endl;
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            cout << "   " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << ": " << customer_arr[i]->ssn << " - ";
            
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                double balancePrint = customer_arr[i]->checkingAccount->balance;
                
                cout << customer_arr[i]->checkingAccount->accountNumber << "($" << customer_arr[i]->doublePrinter(balancePrint) << ")";
                found = true;
            }
            
            if(customer_arr[i]->checkingAccount != nullptr && customer_arr[i]->savingsAccount != nullptr){
                cout << ", ";
            }
            
            if(customer_arr[i]->savingsAccount != nullptr)
            {
                double balancePrint = customer_arr[i]->savingsAccount->balance;
                
                cout << customer_arr[i]->savingsAccount->accountNumber << "($" << customer_arr[i]->doublePrinter(balancePrint) << ") " << endl;
                found = true;
            }
            else if(customer_arr[i]->savingsAccount == nullptr){
                cout << endl;
            }
        }
    }
    
    if(!found){
        cerr << "Bank has no customers with accounts.." << endl;
    }
    else{
        for(int k = 0; k < CUSTOMER_CAPASITY; k++){
            if(customer_arr[k] != nullptr){
                if(customer_arr[k]->checkingAccount != nullptr)
                {
                    totalBalance = totalBalance + customer_arr[k]->checkingAccount->balance;
                }
                if(customer_arr[k]->savingsAccount != nullptr)
                {
                    totalBalance = totalBalance + customer_arr[k]->savingsAccount->balance;
                }
            }
        }
        cout << "\nTotal balance: $" << customer_arr[CUSTOMER_CAPASITY]->doublePrinter(totalBalance) << endl;
    }
}

bool transfereMoney(Customer *customer_arr[])
{
    int sourceAccount;
    int destinationAccount;
    int sourceIndex = -1;
    int destinationIndex = -1;
    double amount;
    
    cout << "Source Account: ";
    cin >> sourceAccount;
    cout << "Destination Account: ";
    cin >> destinationAccount;
    cout << "Enter money amount: ";
    cin >> amount;
    
    if(sourceAccount == destinationAccount)
    {
        cerr << "\nCan't trasfer money to the same account." << endl;
        return false;
    }
    else if(amount < 0){
        cerr << "\nCan't transfer a negative sum.." << endl;
        return false;
    }
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            if(customer_arr[i]->checkingAccount != nullptr)
            {
                if(customer_arr[i]->checkingAccount->accountNumber == sourceAccount)
                {
                    sourceIndex = i;
                }
                else if(customer_arr[i]->checkingAccount->accountNumber == destinationAccount)
                {
                    destinationIndex = i;
                }
            }
            if(customer_arr[i]->savingsAccount != nullptr)
            {
                if(customer_arr[i]->savingsAccount->accountNumber == sourceAccount)
                {
                    sourceIndex = i;
                }
                else if(customer_arr[i]->savingsAccount->accountNumber == destinationAccount)
                {
                    destinationIndex = i;
                }
            }
        }
    }
    
    if(sourceIndex == -1 || destinationIndex == -1)
    {
        cerr << "Transfer Fail – Incorrect account number" << endl;
        return false;
    }
    
    else if(sourceIndex != -1 || destinationIndex != -1)
    {
        if(customer_arr[sourceIndex]->ssn == customer_arr[destinationIndex]->ssn) // internal transfer between just one customer
        {
            if(customer_arr[sourceIndex]->checkingAccount->accountNumber == sourceAccount)
            {
                if(customer_arr[sourceIndex]->checkingAccount->balance >= amount)
                {
                    customer_arr[sourceIndex]->checkingAccount->balance -= amount;
                    customer_arr[destinationIndex]->savingsAccount->balance += amount;
                    
                    double sourceBalancePrinter = customer_arr[sourceIndex]->checkingAccount->balance;
                    double destinationBalancePrinter = customer_arr[destinationIndex]->savingsAccount->balance;
                    
                    cout << "Transfer Succeed." << endl;
                    cout << "New Balance" << endl;
                    cout << "   " << customer_arr[sourceIndex]->checkingAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                    cout << "   " << customer_arr[destinationIndex]->savingsAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                }
                else
                {
                    cerr << "Transfer Fail – Insufficient amount." << endl;
                    return false;
                }
            }
            else if(customer_arr[sourceIndex]->savingsAccount->accountNumber == sourceAccount)
            {
               if(customer_arr[sourceIndex]->savingsAccount->balance >= amount)
                {
                    customer_arr[sourceIndex]->savingsAccount->balance -= amount;
                    customer_arr[destinationIndex]->checkingAccount->balance += amount;
                    
                    double sourceBalancePrinter = customer_arr[sourceIndex]->savingsAccount->balance;
                    double destinationBalancePrinter = customer_arr[sourceIndex]->checkingAccount->balance;
                    
                    cout << "Transfer Succeed." << endl;
                    cout << "New Balance" << endl;
                    cout << "   " << customer_arr[sourceIndex]->savingsAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                    cout << "   " << customer_arr[destinationIndex]->checkingAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                }
                else
                {
                    cerr << "Transfer Fail – Insufficient amount." << endl;
                    return false;
                } 
            }
        }
        else
        {
            if(customer_arr[sourceIndex]->checkingAccount != nullptr && customer_arr[destinationIndex]->checkingAccount != nullptr)
            {
                if(customer_arr[sourceIndex]->checkingAccount->accountNumber == sourceAccount && customer_arr[destinationIndex]->checkingAccount->accountNumber == destinationAccount)
                {
                    if(customer_arr[sourceIndex]->checkingAccount->balance >= amount+5)
                    {
                        amount += 5;
                        customer_arr[sourceIndex]->checkingAccount->balance -= amount;
                        amount -= 5;
                        customer_arr[destinationIndex]->checkingAccount->balance += amount;
                        
                        double sourceBalancePrinter = customer_arr[sourceIndex]->checkingAccount->balance;
                        double destinationBalancePrinter = customer_arr[destinationIndex]->checkingAccount->balance;
                        
                        cout << "Transfer Succeed." << endl;
                        cout << "New Balance" << endl;
                        cout << "   " << customer_arr[sourceIndex]->checkingAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                        cout << "   " << customer_arr[destinationIndex]->checkingAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                    }
                    else
                    {
                        cerr << "Transfer Fail – Insufficient amount." << endl;
                        return false;
                    }
                }
            }
            else if(customer_arr[sourceIndex]->savingsAccount != nullptr && customer_arr[destinationIndex]->savingsAccount != nullptr)
            {
                if(customer_arr[sourceIndex]->savingsAccount->accountNumber == sourceAccount && customer_arr[destinationIndex]->savingsAccount->accountNumber == destinationAccount)
                {
                    if(customer_arr[sourceIndex]->savingsAccount->balance >= amount+5)
                    {
                        amount += 5;
                        customer_arr[sourceIndex]->savingsAccount->balance -= amount;
                        amount -= 5;
                        customer_arr[destinationIndex]->savingsAccount->balance += amount;
                     
                        double sourceBalancePrinter = customer_arr[sourceIndex]->savingsAccount->balance;
                        double destinationBalancePrinter = customer_arr[destinationIndex]->savingsAccount->balance;
                        
                        cout << "Transfer Succeed." << endl;
                        cout << "New Balance" << endl;
                        cout << "   " << customer_arr[sourceIndex]->savingsAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                        cout << "   " << customer_arr[destinationIndex]->savingsAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                    }
                    else
                    {
                        cerr << "Transfer Fail – Insufficient amount." << endl;
                        return false;
                    }
                }
            }
            else if(customer_arr[sourceIndex]->savingsAccount != nullptr && customer_arr[destinationIndex]->checkingAccount != nullptr)
            {
                if(customer_arr[sourceIndex]->savingsAccount->accountNumber == sourceAccount && customer_arr[destinationIndex]->checkingAccount->accountNumber == destinationAccount)
                {
                    if(customer_arr[sourceIndex]->savingsAccount->balance >= amount+5)
                    {
                        amount += 5;
                        customer_arr[sourceIndex]->savingsAccount->balance -= amount;
                        amount -= 5;
                        customer_arr[destinationIndex]->checkingAccount->balance += amount;
                        
                        double sourceBalancePrinter = customer_arr[sourceIndex]->savingsAccount->balance;
                        double destinationBalancePrinter = customer_arr[destinationIndex]->checkingAccount->balance;
                        
                        cout << "Transfer Succeed." << endl;
                        cout << "New Balance" << endl;
                        cout << "   " << customer_arr[sourceIndex]->savingsAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                        cout << "   " << customer_arr[destinationIndex]->checkingAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                    }
                    else
                    {
                        cerr << "Transfer Fail – Insufficient amount." << endl;
                        return false;
                    }
                }
            }
            else if(customer_arr[sourceIndex]->checkingAccount != nullptr && customer_arr[destinationIndex]->savingsAccount != nullptr)
            {
                if(customer_arr[sourceIndex]->checkingAccount->accountNumber == sourceAccount && customer_arr[destinationIndex]->savingsAccount->accountNumber == destinationAccount)
                {
                    if(customer_arr[sourceIndex]->checkingAccount->balance >= amount+5)
                    {
                        amount += 5;
                        customer_arr[sourceIndex]->checkingAccount->balance -= amount;
                        amount -= 5;
                        customer_arr[destinationIndex]->savingsAccount->balance += amount;
                        
                        double sourceBalancePrinter = customer_arr[sourceIndex]->checkingAccount->balance;
                        double destinationBalancePrinter = customer_arr[destinationIndex]->savingsAccount->balance;
                        
                        cout << "Transfer Succeed." << endl;
                        cout << "New Balance" << endl;
                        cout << "   " << customer_arr[sourceIndex]->checkingAccount->accountNumber << ": $" << customer_arr[sourceIndex]->doublePrinter(sourceBalancePrinter) << endl;
                        cout << "   " << customer_arr[destinationIndex]->savingsAccount->accountNumber << ": $" << customer_arr[destinationIndex]->doublePrinter(destinationBalancePrinter) << endl;
                    }
                    else
                    {
                        cerr << "Transfer Fail – Insufficient amount." << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// the function to run in driver.cpp;
void chooseOption(Customer *customer_arr[])
{
    int option;
    
    cout << "Select your choice: \n" 
         << "   1. Read customer data file \n"
         << "   2. Close an account \n"
         << "   3. Customer Info\n" 
         << "   4. Bank Info\n"
         << "   5. Transfere Money\n"
         << "   6. Customer List\n"
         << "   7. Exit\n" << endl;
         
    cout << "Enter your option: ";
    cin >> option;
    
    //the next two lines will clear the cin buffer so if the input is worng the program wont be stuck.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n";
    
    switch (option){
        case 1:
            readFile(customer_arr);
            sortOnSSN(customer_arr);
           // createAccount(acc_ptr);
            break;
        case 2:
            closeAccount(customer_arr);
            break;
        case 3:
            customerInformation(customer_arr);
            break;
        case 4:
            bankInfo(customer_arr);
            break;
        case 5:
            transfereMoney(customer_arr);
            break;
        case 6:
            display(customer_arr);
            break;
        case 7:
            cout << "Bye!" << endl;
            for(int j = 0; j < CUSTOMER_CAPASITY; j++)
            {
                if(customer_arr[j] != nullptr)
                {
                    delete customer_arr[j];
                    customer_arr[j] = nullptr;   
                }
            }
            exit(2);
            break;
        default:
            cout << "invalid input, try agien\n ";
            
            chooseOption(customer_arr);
        
    }
    cout << endl;
        
        chooseOption(customer_arr);
    }
    
void display(Customer *customer_arr[])
{
    bool emptyList = true;
    cout << "========== Customer List ==========" << endl;
    
    for(int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        if(customer_arr[i] != nullptr)
        {
            cout << "SSN: " << customer_arr[i]->ssn << endl;
            cout << "Name: " << customer_arr[i]->firstName << " " << customer_arr[i]->lastName << endl;
            cout << endl;
            emptyList = false;
        }
    }
    if(emptyList){
        cerr << "list is empty" << endl;
    }
    
    cout << "===================================" << endl;
    
}

/*
 * Title: Customer.h / Project 2
 * Abstract: This program is a bank simulation program using a array of pointer to hold customers
             and a struct to create the accounts of type checking and savings. There is several 
             functions to utalize in this program to trasfere money, find customers, read customer
             data from a file and create the correct type of account corresponding to what is in the file.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 27/11/2018
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

const int CUSTOMER_CAPASITY = 20;

class Customer
{
public:
    struct acc_ptr
    {
        int accType;
        double balance;
        int accountNumber;
        int accountSSN;
    };
    
    Customer(string newFirstName, string newLastName, int newSSN);
    friend void chooseOption(Customer *acc_ptr[]);
    friend void readFile(Customer *customer_arr[]);
    friend void display(Customer *customer_arr[]);
    friend int findOpenSpot(Customer *customer_arr[]);
    friend bool accountValidation(Customer *customer_arr[], string tempFirstName, string tempLastName, int tempSSN, int tempAccountNumber);
    friend int exsistingCustomer(Customer *customer_arr[], string tempFirstName, string tempLastName, int tempSSN);
    friend bool closeAccount(Customer *customer_arr[]);
    friend bool findAccount(Customer *customer_arr[], int newAccountNumber);
    friend void customerInformation(Customer *customer_arr[]);
    friend void findCustomerViaSSN(Customer *customer_arr[]);
    friend void findCustomerViaLastName(Customer *customer_arr[]);
    friend void findCustomerViaAccountNumber(Customer *customer_arr[]);
    friend void bankInfo(Customer *customer_arr[]);
    friend void sortOnSSN(Customer *tempArr[]);
    friend bool transfereMoney(Customer *customer_arr[]);
    
    string doublePrinter(double value);
    bool setSavingsAccount(string newFirstName, string newLastName, int newSSN, int accountType, int newAccountNumber, double newBalance);
    bool setCheckingAccount(string newFirstName, string newLastName, int newSSN, int accountType, int newAccountNumber, double newBalance);
    
    string getFirstname(){return firstName;};
    int getSSN(){return ssn;};
private:
    string firstName;
    string lastName;
    int ssn;
    
    int checkingAccountCounter = 0;
    int savingsAccountCounter = 0;
    acc_ptr * checkingAccount = nullptr;
    acc_ptr * savingsAccount = nullptr;
};
// end of class declaration
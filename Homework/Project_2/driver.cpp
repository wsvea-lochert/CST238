/*
 * Title: driver.cpp / Project 2
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
#include "Customer.h"
using namespace std;

int main( )
{
    cout << "Welcome to CSUMB Bank" << endl;
    Customer * customer_arr[CUSTOMER_CAPASITY];
    
    for (int i = 0; i < CUSTOMER_CAPASITY; i++)
    {
        //delete customer_arr[i];
        customer_arr[i] = nullptr;
    }
    chooseOption(customer_arr);
    //c1.readFile();
  
    
    return 0;
}


/**
 * Title: hw2_3.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program reads a file from userinput. From more user input in looks if the person you are looking for
 *           are in the file, if so it displays the person with his or her account + balance. If they are not in the file
 *           an error is displayed.
 * ID: 1112
 * Date: 09.13.2018
 * */
 
#include <iostream>
#include <fstream>
using namespace std;

double average(double array[], int size);

struct Bank
{
    string name;
    int account;
    double balance;
};


int main()
{
    string file_name;
    bool controll = false;
    char cont = 'Y';

    cout << "Enter input file name: ";
    cin >> file_name;

    ifstream input_file(file_name);
    
    if (input_file.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
    
    Bank customers[30];
    int size = 30;
    int index = 0;
    int teller = 0;
    string searchName;
    
   while(cont == 'Y' || cont == 'y')
   {
        cout << "---------------------------------------------------" << endl;
        cout << "Record Finder - Enter a customer name: ";
        cin >> searchName;
        cout << "---------------------------------------------------" << endl;
        
        while(!controll)
        {
            Bank customer;
            input_file >> customer.name;
            input_file >> customer.account;
            input_file >> customer.balance;
            
            if(customer.name == "STOP")
            {
                controll = true;
            }
            customers[index] = customer;
            
            if(index == size)
            {
                controll = true;
            }
            index++;
        }
        
        for(int i = 0; i < index; i++)
        {
            if(customers[i].name == searchName)
            {
                cout << "Name: " << customers[i].name << endl 
                     << "Account: " << customers[i].account << endl
                     << "Balance: " << customers[i].balance << endl << endl;
            }
            else
            {
                teller++;
            }
        }
        if(teller == index)
        {
            cout << "Fail. " << searchName << " doesn’t exist." << endl;
        }
    
        cout << "--------------------------------------------------" << endl << endl;
        cout << "Do you want to continue?  (Y/N) " << index << " " << teller;
        cin >> cont;
        cout << endl;
        teller = 0;
        
        if(cont == 'n' || cont == 'N')
        {
            cout << "BYE!" << endl;
            
        }
    }
    return 0;
}
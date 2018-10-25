/*
 * Title: hw5_1.cpp
 * Abstract: This program prints a paralelogram and a diamond, 
             using only pointers and dynamic memory, with some user input
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/18/2018
 */
#include <iostream>
using namespace std;

int main()
{
    int * star = new int;
    int * spaces = new int;
    int * i = new int;
    int * ptrSize = new int;
    int * ptrLines = new int;
    
    //*ptrLines = *i;
    cout << "Enter a number: ";
    cin >> *ptrSize;
    *spaces = *ptrSize;
    //*star = *ptrSize;
    
    //==================== paralelogram print ======================//
    // lines print
    for(*ptrLines = 0; *ptrLines < *ptrSize; (*ptrLines)++)
    { 
        //space print
        for(*i = 0; *i < *spaces; (*i)++)
        {
            cout << " ";
        }
        
        //star print
        for(*i = 0; *i < *ptrSize; (*i)++)
        {
            cout << "*";
        }
        
        (*spaces)--;
        cout << endl;
    }
    
    cout << endl;
    
    //==================== diamond print ======================//
    
    *spaces = (*ptrSize) - 1;
    
    for (*ptrLines = 1; *ptrLines <= *ptrSize; (*ptrLines)++)
    {
        for (*i = 1; *i<= *spaces; (*i)++)
        {
            cout<<" ";
        }
        
        (*spaces)--;
        
        for (*i = 1; *i <= 2 * (*ptrLines) - 1; (*i)++)
        {
            cout<<"*";
        }
        cout << endl;
    }
      
    *star = 1;
    *spaces = 1;
     
    for (*star = 1; *star <= (*ptrSize) - 1; (*star)++)
    {
        for (*i = 1; *i <= *spaces; (*i)++)
        {
            cout << " ";
        }
      
        (*spaces)++;
      
        for (*i = 1 ; *i <= 2 * ((*ptrSize)-(*star)) - 1; (*i)++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    delete star;
    delete spaces;
    delete i;
    delete ptrSize;
    delete ptrLines;
    
    star = nullptr;
    spaces = nullptr;
    i = nullptr;
    ptrSize = nullptr;
    ptrLines = nullptr;
    
}
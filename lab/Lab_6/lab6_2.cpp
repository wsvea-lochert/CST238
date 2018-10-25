/*
 * Title: lab6_2.cpp
 * Abstract: This program uses pointer and 
             dynamic memory to find the max and min number from a user
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/12/2018
 */

#include <iostream>
using namespace std;

int main()
{
    const int mySize = 4;
    int * ptrInpNumber = new int[mySize];
    int * ptrInput = new int;
    int * ptrMin = new int;
    int * ptrMax = new int;
    
    cout << "Enter 4 numbers: ";
    
    for(int i = 0; i < mySize; i++)
    {
        cin >> *ptrInput;
        ptrInpNumber[i] = *ptrInput;
        
        cout << ptrInpNumber[i] << " ";
    }
    
    *ptrMin = ptrInpNumber[0];
    *ptrMax = ptrInpNumber[0];
    
    for(int i = 0; i < mySize; i++)
    {
        if(ptrInpNumber[i] < *ptrMin)
        {
            *ptrMin = ptrInpNumber[i];
        }
        if(ptrInpNumber[i] > *ptrMax)
        {
            *ptrMax = ptrInpNumber[i];
        }
    }
    
    cerr << endl;
    
    cout << "Min value: " << *ptrMin << endl;
    
    cout << "Max value: " << *ptrMax << endl;
    
    delete ptrInpNumber;
    delete ptrInput;
    delete ptrMax;
    delete ptrMin;
    
    ptrInpNumber = nullptr;
    ptrInput = nullptr;
    ptrMax = nullptr;
    ptrMin = nullptr;
}
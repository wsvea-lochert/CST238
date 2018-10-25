/*
 * Title: lab6_2.cpp
 * Abstract: This program takes in 5 exam scores from the user, ignores the lowest score and prints
             a average grade. The program is using pointers and dynamic memory
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/12/2018
 */
#include <iostream>
using namespace std;

int main()
{
    int * mySize = new int;
    int * i = new int;
    *mySize = 5;
    double * ptrInpNumber = new double[*mySize];
    double * ptrInput = new double;
    double * ptrAvg = new double;
    double * ptrMin = new double;
    
    cout << "Enter 5 scores: ";
    
    for(*i = 0; *i < *mySize; *i+=1)
    {
        cin >> *ptrInput;
        ptrInpNumber[*i] = *ptrInput;
        *ptrAvg += *ptrInput;
        
        //cout << ptrInpNumber[*i] << " ";
    }
    
    *ptrMin = ptrInpNumber[0];
    for(*i = 0; *i < *mySize; *i+=1)
    {
      if(ptrInpNumber[*i] < *ptrMin)
      {
          *ptrMin = ptrInpNumber[*i];
      }
    }
    
    *ptrAvg = *ptrAvg - *ptrMin;
    
    *ptrAvg = *ptrAvg / 4;
    
    if(*ptrAvg >= 90)
    {
        cout << "Average: " << *ptrAvg << " (A)" << endl; 
    }
    else if(*ptrAvg >= 80)
    {
        cout << "Average: " << *ptrAvg << " (B)" << endl; 
    }
    else if(*ptrAvg >= 70)
    {
        cout << "Average: " << *ptrAvg << " (C)" << endl; 
    }
    else if(*ptrAvg < 70)
    {
        cout << "Average: " << *ptrAvg << " (F)" << endl; 
    }
    
    cerr << endl;
    
    
    delete ptrInpNumber;
    delete ptrInput;
    delete mySize;
    delete ptrAvg;
    delete ptrMin;
    delete i;

    ptrInpNumber = nullptr;
    ptrInput = nullptr;
    mySize = nullptr;
    ptrAvg = nullptr;
    ptrMin = nullptr;
    i = nullptr;
    
    
}
/*
 * Title: lab7_1.cpp
 * Abstract: This program reads numbers from a file entered by the user and then quicksorts the numbers using dynamic array.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/19/2018
 */

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int * ptrSize = new int;
    int * ptrNext = new int;
    string filename;
    
    cout << "Enter a filename: ";
    cin >> filename;
    string line;
    
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        myfile >> *ptrSize;
        int * ptrArray = new int[*ptrSize];
        for(int i = 0; i < *ptrSize; i++)
        {
            myfile >> *ptrNext;
            *(ptrArray + i) = *ptrNext;
            
        }
        
        int front = 0;
        int back = *ptrSize;
        int temp;
        
        /*==== quicksort ====*/
        while(front < back)
        {
            if(*(ptrArray + front) < 0 && *(ptrArray + back) > 0)
            {
                back--;
                front++;
            }
            else if(*(ptrArray + front) > 0 && *(ptrArray + back) < 0)
            {
                temp = *(ptrArray + back);
                *(ptrArray + back) = *(ptrArray + front);
                *(ptrArray + front) = temp;
                back--;
                front++;
            }
            else if(*(ptrArray + front) > 0 && *(ptrArray + back) > 0)
            {
                back--;
            }
            else if(*(ptrArray + front) < 0 && *(ptrArray + back) < 0)
            {
                front++;
            }
        }
        
        for(int i = 0; i < *ptrSize; i++)
        {
            cout << *(ptrArray + i) << " ";
        }
        cout << endl;
        
        myfile.close();
            
        delete ptrArray;
        delete ptrNext;
        delete ptrSize;
    
        ptrArray = nullptr;
        ptrNext = nullptr;
        ptrSize = nullptr;
    }
}


/*String array trenger size + 1*/
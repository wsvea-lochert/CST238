/*
 * Title: hw5_1.cpp
 * Abstract: This program combines two arrays only using pointers and dynamic memmory with some userinput.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/17/2018
 */
#include <iostream>
using namespace std;

void validation(int n);

int main()
{
    int * n = new int; //Size for first array
    int * i = new int; //Itterator pointer
    int * j = new int; //Itterator pointer
    int * ptrInput = new int; //Input to put into array

    // Input for 1.st array
    cout << "Enter the size of first array: ";
    cin >> *n;
    //if *n is less than 0 kill the program
    validation(*n);
    cout << "Enter the array content: ";
    int * ptr1 = new int[*n]; // First Array
    
    for(*i = 0; *i < *n; *i+=1)
    {
        cin >> *ptrInput;
        ptr1[*i] = *ptrInput;
    }
    
    *i = 0;
    
    // Input for 2.nd array
    int * m = new int; //initializing Size of second array
    int * ptr2 = new int[*m]; //initializing Second Array
    cout << "Enter the size of second array: ";
    cin >> *m;
    //if *m is less than 0 kill the program
    validation(*m);
    cout << "Enter the array content: ";
    
    
    
    for(*i = 0; *i < *m; *i+=1)
    {
        cin >> *ptrInput;
        ptr2[*i] = *ptrInput;
    }
    
    *i = 0;
    *j = 0;
    
    int * ptr3 = new int[*n+*m]; //Final Array to fill
    //combining arrays
    cout << "The combined array is: ";
    for(*i = 0; *i < *n+*m; *i+=1)
    {
        if(*i < *n)
        {
            ptr3[*i] = ptr1[*i];
        } 
        else
        {
            ptr3[*i] = ptr2[*j];
            *j+=1;
        }
        cout << ptr3[*i] << " ";
    }
    cout << endl;
    
    //Deleting pointers and setting them to nullptr
    delete n;
    delete m;
    delete i;
    delete j;
    delete ptrInput;
    delete ptr1;
    delete ptr2;
    delete ptr3;
    
    n = nullptr;
    m = nullptr;
    i = nullptr;
    j = nullptr;
    ptrInput = nullptr;
    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;
    
    return 0;
    
}

void validation(int n){
    if(n < 0){
        cerr << "Unvalid number, killing program..." << endl;
        exit(-1);
    }
}
/*
 * Title: hw6_1.cpp
 * Abstract: This program reads from two files, then alocates a dynamic array to hold values. The user can add,
             remove and find numbers in the array.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/23/2018
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

void readFile(string filename, int array[], int * ptrSize);
void sort(int array[], int * ptrSize);
void display(int array[], int * ptrSize);
void clearCin();
void addValue(int array[], int * ptrSize, int maxSize);
bool findNumber(int array[], int * ptrSize, int searchValue);
void deleteNumber(int array[], int *ptrSize);
void search(int array[], int * ptrSize);

int main()
{
    
    string file;
    int * ptrSize = new int;
    int myArray[*ptrSize];
    char continueOption = 'Y';
    int maxSize;
    
    //read first file
    cout << "Enter first filename: ";
    cin >> file;
    clearCin();
    readFile(file, myArray, ptrSize);
    
    //read second file
    cout << "Enter second filename: ";
    cin >> file;
    clearCin();
    readFile(file, myArray, ptrSize);
   
    //sort array and display the array
    sort(myArray, ptrSize);
    cout << "Merged Result: ";
    maxSize = *ptrSize;
    display(myArray, ptrSize);
    
    cout << "This is a list of options" << endl 
         << "   1. Add a number"        << endl
         << "   2. Delete a number"     << endl
         << "   3. Find a number"       << endl;
                 
    while(continueOption == 'Y' || continueOption == 'y')
    {
        int option;
        char checker = 'y';
        bool continueCheck = false;
        
        cout << "Enter your option: ";
        cin >> option;
        clearCin();
        
        //Add a number
        if(option == 1)
        {
            addValue(myArray, ptrSize, maxSize);
        }
        
        //Delete a number
        else if(option == 2)
        {
           deleteNumber(myArray, ptrSize);
        }
        
        //find a number
        else if(option == 3)
        {
            search(myArray, ptrSize);
        }
        
        //error handeling.
        else
        {
            cerr << "error, invalid input" << endl;
        }
        
        while(!continueCheck)
        {
            cout << "continue? (Y/N): ";
            cin >> checker;
            
            if(checker == 'Y' || checker == 'y')
            {
                cout << endl;
                continueOption = checker;
                continueCheck = true;
            }
            else if(checker == 'N' || checker == 'n')
            {
                cout << endl;
                continueOption = checker;
                continueCheck = true;
            }
            else
            {
                cerr << "invalid input, try agien.." << endl;
            }
        }
    }
    
    delete ptrSize;
    ptrSize = nullptr;
    
    return 0;
}

//adds a number to the array if there is space
void addValue(int array[], int * ptrSize, int maxSize)
{
    if(*ptrSize == maxSize)
    {
        cerr << "No space to add a new number." << endl;
    }
    
    else
    {
        //reading in new value
        int newValue;
        cout << "Enter a number to add: ";
        cin >> newValue;
        clearCin();
        
        *ptrSize += 1;
        *(array + *ptrSize-1) = newValue;
        
        //Sorting array to get the number in the right place
        sort(array, ptrSize);
        display(array, ptrSize);
    }
}

//delete a number function, uses findNumber() alose.
void deleteNumber(int array[], int * ptrSize)
{
    if(*ptrSize == 0)
    {
        cerr << "Can't delete number, the array is empty" << endl;
    }
    
    else
    {
        int deleteIndex;
        int deleteValue;
        
        cout << "Enter a number you want to delete: ";
        cin >> deleteValue;
        
        if(!findNumber(array, ptrSize, deleteValue))
        {
            cerr << deleteValue << ": Not found." << endl;
            return;
        }
        
        //making deleteIndex the index of where the number is found.
        for (int i = 0; i < *ptrSize; i++)
        {
            if(*(array + i) == deleteValue)
            {
                deleteIndex = i;
            }
        }
        
        for(int index = deleteIndex; index < *ptrSize; index++)
        {
            *(array + index) = *(array + index + 1);
        }
        
        *ptrSize-=1;
        display(array, ptrSize);
    }
}

bool findNumber(int array[], int * ptrSize, int searchValue)
{
    for(int i = 0; i < *ptrSize; i++)
    {
        if(*(array + i) == searchValue)
        {
            return true;
        }
    }
    return false;
}

//reads a file
void readFile(string filename, int array[], int * ptrSize)
{
    ifstream myfile (filename);
    
    if(myfile.fail())
    {
        cerr << "Error: file not found" << endl;
        return;
    }

    int size;
    int nextInt = 0;

    myfile >> size;
    for(int i = 0; i < size; i++)
    {
        myfile >> nextInt;
        *(array + (*ptrSize + i)) = nextInt;
    }
    *ptrSize += size;
}

//sorts the array
void sort(int array[], int * ptrSize)
{
    for(int i = 0; i < *ptrSize-1; i++)
    {
        for(int j = 0; j < *ptrSize-i-1; j++)
        {
            if(*(array + j) > *(array + j+1))
            {
                int temp = *(array + j);
                *(array + j) = *(array + j+1);
                *(array + j+1) = temp;
            }
        }
    }
}

//displays the array
void display(int array[], int * ptrSize)
{
    cout << "New array values: ";
    
    for(int i = 0; i < *ptrSize; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

//search function for printing result
void search(int array[], int * ptrSize)
{
    int searchValue;
    cout << "Enter a number to find: ";
    cin >> searchValue;
                
    for(int i = 0; i < *ptrSize; i++)
    {
        if(*(array + i) == searchValue)
        {
            cout << searchValue << ": Found." << endl;
            return;
        }
    }
    cerr << searchValue << ": Not Found." << endl;
    return;
}

//clear Cin function
void clearCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
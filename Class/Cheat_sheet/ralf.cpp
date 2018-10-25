/*
 * TITLE: hw6_1.cpp
 * ABSTRACT: This program prompts the user for two files, then it reads the values into an array before sorting it.
             Then the user is prompted with three options, add, delete or find.
 * AUTHOR: Ralf Leistad
 * ID: 1995
 * DATE: 10/21/2018
 */

#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(string filename, int arr[], int * ptrSize);
void bubble(int arr[], int * ptrSize);
void print(int arr[], int * ptrSize);
bool find(int arr[], int * ptrSize, int value);
void add(int arr[], int * ptrSize, int value);
void deleteNum(int arr[], int * ptrSize, int value);

int main()
{
    
    string file;
    int * ptrSize = new int;
    int merged[*ptrSize];
    
    cout << "Enter first filename: ";
    cin >> file;
    readFromFile(file, merged, ptrSize);
    
    cout << "Enter second filename: ";
    cin >> file;
    readFromFile(file, merged, ptrSize);

    // CALL SORTING AND PRINT FUNCTION
    bubble(merged, ptrSize);
    cout << "Merged result: ";
    print(merged, ptrSize);
    
    int maxSize = *ptrSize;
    
    cout << "This is a list of operations" << endl;
    cout << "\t1. Add a number\n\t2. Delete a number\n\t3. Find a number\n";
    
    char proceed = 'Y';
        
    while(proceed == 'Y' || proceed == 'y')
    {
        int option = 0;

        cout << "\nEnter your option: ";
        cin >> option;
        
        int addValue = 0;
        int deleteValue = 0;
        int findValue = 0;
        
        switch(option)
        {
            case 1:
                if(*ptrSize == maxSize)
                {
                    cout << "No space to add a new number." << endl;
                    break;
                }
                else
                {
                    cout << "Enter a number to add: ";
                    cin >> addValue;
                    add(merged, ptrSize, addValue);
                }
                break;
                
            case 2:
                if(*ptrSize == 0)
                {
                    cout << "Array is empty..." << endl;
                    break;
                }
                
                cout << "Enter a number to delete: ";
                cin >> deleteValue;
                deleteNum(merged, ptrSize, deleteValue);
                break;
                
            case 3:
                cout << "Enter a number to find: ";
                cin >> findValue;

                cout << findValue << (find(merged, ptrSize, findValue) ? ": Found." : ": Not Found.") << endl;
                break;
                
            default:
                cout << "You entered an invalid option...\n";
        }
        
        cout << "Continue? (Y/N): ";
        cin >> proceed;
    }
    
    
    delete ptrSize;
    ptrSize = nullptr;
    
    return 0;
}

void readFromFile(string filename, int arr[], int * ptrSize)
{
    fstream in_file(filename);
    
    if (in_file.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return;
    }
    
    int tempSize = 0;
    in_file >> tempSize;
    
    int tempNum = 0;
    
    for(int i = 0; i < tempSize; i++)
    {
        in_file >> tempNum;
        *(arr + (*ptrSize + i)) = tempNum;
    }
    
    *ptrSize += tempSize;
}

void bubble(int arr[], int * ptrSize)
{
    
    int temp1 = 0;
    int temp2 = 0;
    
    for(int i = 0; i < *ptrSize - 1; i++)
    {
        for(int j = 0; j < *ptrSize - i - 1; j++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                temp1 = *(arr + j);
                temp2 = *(arr + j + 1);
                
                *(arr + j) = temp2;
                *(arr + j + 1) = temp1;
            }
        }
    }
}

void print(int arr[], int * ptrSize)
{
    for(int i = 0; i < *ptrSize; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

bool find(int arr[], int * ptrSize, int value)
{
    for(int i = 0; i < *ptrSize; i++)
    {
        if(*(arr + i) == value)
        {
            return true;
        }
    }
    return false;
}

void add(int arr[], int * ptrSize, int value)
{
    *ptrSize += 1;
    
    *(arr + *ptrSize - 1) = value;
    
    bubble(arr, ptrSize);
    
    cout << "New array values: ";
    print(arr, ptrSize);
}

void deleteNum(int arr[], int * ptrSize, int value)
{
    if(!find(arr, ptrSize, value))
    {
        cout << value << ": Not found." << endl;
        return;
    }
    
    int index = 0;
    
    for(int i = 0; i < *ptrSize; i++)
    {
        if(*(arr + i) == value)
        {
            index = i;
        }
    }
    
    for(int i = index; i < *ptrSize; i++)
    {
        *(arr + i) = *(arr + i + 1);
        
    }
    
    *ptrSize -= 1;
    
    cout << "New array values: ";
    print(arr, ptrSize);
}
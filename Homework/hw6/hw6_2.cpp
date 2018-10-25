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
#include <limits>
using namespace std;

void readFile(string filename, char array[], int * ptrSize);
void substringSearch(char array[], int * ptrSize);
void clearCin();

int main() 
{
    int * ptrSize = new int;
    char myArray[*ptrSize];
    string file;
    
    cout << "Enter first filename: ";
    cin >> file;
    clearCin();
    readFile(file, myArray, ptrSize);
    
    substringSearch(myArray, ptrSize);
    
    delete ptrSize;
    ptrSize = nullptr;
    
    return 0;
}

void readFile(string filename, char array[], int * ptrSize)
{
    ifstream myfile (filename);
    
    if(myfile.fail())
    {
        cerr << "Error: file not found" << endl;
        return;
    }

    int size;
    char nextChar;

    myfile >> size;
    for(int i = 0; i < size; i++)
    {
        myfile >> nextChar;
        *(array + i) = nextChar;
    }
    
    *ptrSize += size;
    size--;
    *(array + size) = '\0';
}

void substringSearch(char array[], int * ptrSize)
{
    int counter = 0;
    
    for(int indexFront = 0; indexFront < *ptrSize; indexFront++)
    {
        if(*(array + indexFront) == 'A')
        {
            for(int indexBack = indexFront; indexBack < *ptrSize; indexBack++)
            {
                if(*(array + indexBack) == 'B')
                {
                    counter++;
                    cout << "Substring " << counter << ": ";
                    
                    //print
                    int index = indexFront;
                    while(index <=indexBack)
                    {
                        cout << *(array + index);
                        index++;
                    }
                    cout << endl;
                }
            }
        }
    }
    cout << "Total " << counter << " Substrings" << endl;
}

void clearCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
/*
 * Title: lab7_1.cpp
 * Abstract: This program reads a char array from a file, then the user can search for a substring
             of the char array.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/28/2018
 */

#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

void readFile(string filename, char array[], int * ptrSize);
bool substringSearch(char array[], int * ptrSize, char substring[], int substringSize);
int substringCall(char substring[]);

int main() 
{
    int * ptrSize = new int;
    char myArray[*ptrSize];
    string file;
    char * substring = new char[*ptrSize];
    int substringSize = 0;
    
    cout << "Enter first filename: ";
    cin >> file;
    readFile(file, myArray, ptrSize);
    substringSize = substringCall(substring);
    
    if(substringSearch(myArray, ptrSize, substring, substringSize))
    {
        cout << "Substring " << substring << " is found." << endl;
    }
    else
    {
         cout << "Substring " << substring << " is not found." << endl;
    }
    
    delete ptrSize;
    delete substring;
    
    substring = nullptr;
    ptrSize = nullptr;
    
    return 0;
}




int substringCall(char substring[])
{
    cout << "Enter a substring: ";
    
    char ch;
    int i = 0;
    
    char garbage = getchar();
    
    do 
    {
        ch = getchar();
        *(substring+i) = toupper(ch);
        i++;
    } while (ch != '\n');
    
    i--;
    *(substring+i) = '\0';
    return i;
}

void readFile(string filename, char array[], int * ptrSize)
{
    ifstream myfile (filename);
    
    if(myfile.fail())
    {
        cerr << "Error: file not found, exiting program" << endl;
        exit(1);
    }

    int size;
    char nextChar;

    myfile >> size;
    
    for(int i = 0; i < size; i++)
    {
        myfile >> nextChar;
        *(array + i) = nextChar;
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    *ptrSize += size;
    *(array + size) = '\0';
}


bool substringSearch(char array[], int * ptrSize, char substring[], int substringSize)
{
    bool check = false;
    
    for(int i = 0; i < *ptrSize; i++)
    {
        if(array[i] == substring[0])
        {
            int index = i + 1;
            
            if(substringSize == 1){
                check = true;
                break;
            }
            
            for(int j = 1; j < substringSize; j++)
            {
                if(substring[j] == array[index])
                {
                    check = true;
                }
                
                else
                {
                    check = false;
                    break;
                }
                index++;
            }
        }
    }
    return check;
    
}
/*
 * Title: hw6_2.cpp
 * Abstract: This program reads a file of characters and attempt to find substrings from A - B
 * Author: Sander Hellesoe
 * ID: 7337
 * Date: 10.22.2018
 */


#include <iostream>
#include <fstream>

using namespace std;

void readNumbers(ifstream &inFile, char characters[], int * ptrSize);
void findSubString(char characters[], int * ptrSize);
void printSubString(char characters[], int start, int end, int counter);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the characters from file
    int * ptrSize = new int;
    *ptrSize = 0;
    char characters[*ptrSize + 1];

    // Open the file.
    string fileName;
    cout << "Enter a filename: ";
    cin >> fileName;
    
    // Open file
    inFile.open(fileName);
   
    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, characters, ptrSize);
    
    // Search for substrings
    findSubString(characters, ptrSize);

    // Close the file.
    inFile.close();
    
    delete ptrSize;
    ptrSize = nullptr;
    

    return 0;
}

void readNumbers(ifstream &inFile, char characters[], int * ptrSize)
{  
    
    // get size (first index num in file)
    inFile >> *ptrSize;
    
    
    // front and back
    for (int i = 0; i < *ptrSize; i++)
    {
        inFile >> *(characters + i);
    }
}

// search for substrings and print if found
void findSubString(char characters[], int * ptrSize) 
{
    
    // count occurences of substrings
    int substringCounter = 0;
    
    for (int i = 0; i < *ptrSize; i++) 
    {
        
        // found start of potensial substring
        if (*(characters + i) == 'A') 
        {
            
            for (int j = i + 1; j < *ptrSize; j++) 
            {
                
                // substring found, increment counter and print
                if (*(characters + j) =='B') 
                {
                    substringCounter++;
                    printSubString(characters, i, j, substringCounter);

                }
            }
        }
    }
    
    cout << "Total " << substringCounter << " substrings\n";
}

// print out substrings
void printSubString(char characters[], int start, int end, int counter) 
{
    cout << "Substring " << counter << ": ";
    for (start; start <= end; start++) 
    {
        cout << *(characters + start);
    }
    cout << endl;
}
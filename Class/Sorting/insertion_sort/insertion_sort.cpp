// A sample program for insertion sort development.

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Global constant for the array size.
const int ARRAY_SIZE = 10;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int size);
void insertion_sort (int values[], int size);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    inFile.open("ten_numbers.txt");

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, numbers, ARRAY_SIZE);
    
    cout << "===== First 10 Numbers from Input File =====\n";
    for (int i=0; i < 10; i++)
        cout << numbers[i] << " ";
    cout << endl << endl;

    // Close the file.
    inFile.close();

    // Timer variables to measure the running time.
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the bubble sorting..." << endl;
    
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    insertion_sort(numbers, ARRAY_SIZE);
    
    // Measure the elapsed time after the starting clock.
    elapsedTime = clock() - startClock;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) << " seconds" << endl;
    
    cout << "\n===== First 10 Sorted Numbers =====\n";
    for (int i=0; i < 10; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    return 0;
}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************
void readNumbers(ifstream &inFile, int numbers[], int size)
{
   for (int i = 0; i < size; i++)
      inFile >> numbers[i];
}



// Sort an array of integer values in ascending order.
void insertion_sort (int values[], int size) 
{
    int temp;
    for(int i = 1; i < size; i++)
    {
        temp = values[i];
        for(int j = i-1; j >= 0; j--)
        {
            //unsure about this if statemen HERE TEST LATER
            if(values[j] > temp)
            {
                
            }
        }
    }
}
// Original source: Gaddis Book: Chapter 7: Programming Challenge #7
// Updated by Dr. Byun for CST238.

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Global constant for the array size.
const int ARRAY_SIZE = 50000;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int size);
void bubble_sort (int values[], int size);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    inFile.open("t1.txt");

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, numbers, ARRAY_SIZE);
    
    cout << "=== First 10 numbers for debugging purpose... ===\n";
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
    bubble_sort(numbers, ARRAY_SIZE);
    
    // Measure the elapsed time after the starting clock.
    elapsedTime = clock() - startClock;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) << " seconds" << endl;
    
    cout << "\n=== First 10 sorted numbers for debugging purpose... ===\n";
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
void bubble_sort (int values[], int size) 
{
   for(int i = 0; i < size-1; i++)
   {
       for(int j = 0; j < size-i-1; j++)
       {
           if(values[j] > values[j+1])
           {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                
           }
       }
   }
}

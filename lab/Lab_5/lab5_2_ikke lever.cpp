// Gaddis Book: Chapter 7, Programming Challenge 7: Number Analysis Program
// Updated by Dr. Byun for time measurement in CST238

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Global constant for the array size
const int ARRAY_SIZE = 1000000;

// Function prototypes
void readNumbers(ifstream &, int [], int);
int linearSearch(int data[], int size, int value);
int binarySearch(int data[], int size, int value);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the file.
    inFile.open("one_million_numbers_sorted.txt");
   
    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, numbers, ARRAY_SIZE);

    // Close the file.
    inFile.close();

    // Timer variables
    time_t start, end;
    double timediff;
    
    clock_t startClock, elapsedTime;
    
    int target, result;

    cout << "Enter a number to search: ";
    cin >> target;

    // Conduct the linear search and measure the time
    cout << "Start the linear search..." << endl;
    startClock = clock();
    result = linearSearch(numbers, ARRAY_SIZE, target);
    elapsedTime = clock() - startClock;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) << " seconds" << endl;
    cout << "Search result: " << result << endl;

    // Conduct the binary search and measure the time
    cout << "\nStart the binary search..." << endl;
    startClock = clock();
    result = binarySearch(numbers, ARRAY_SIZE, target);
    elapsedTime = clock() - startClock;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) << " seconds" << endl;
    cout << "Search result: " << result << endl;
    
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


//*****************************************************************
// The linearSearch function performs a linear search on an       *
// integer array. The array data, which has a maximum of size      *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
int linearSearch(int data[], int size, int value)
{
   int index = 0;       
   int position = -1;   
   bool found = false;  

   while ((index < size) && !found)
   {
      if (data[index] == value)  
      {
         found = true;         
         position = index; 
      }
      index++;
   }
   return position;
}


//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. The array named data has a maximum of size    *
// elements and is searched for the number stored in value.     *
// If the number is found, its array subscript is returned.     *
// Otherwise, -1 is returned to indicate the value was not in   *
// the array.                                                   *
//***************************************************************

int binarySearch(int data[], int size, int value)
{
    bool found = false;
    
    int first = 0;
    int last = size-1;
    int middle = last/2;

    while(!found){
        //if item is found
      if(data[middle] == value)
      {
          found = true;
          return middle;
      }
      if(data[middle] > value)
      {
          last = middle - 1;
          middle = (first+last)/2;
      }
      if(data[middle] < value)
      {
          first = middle + 1;
          middle = (first+last)/2;
      }
      //its not in the array
      if(first > last)
      {
          found = true;
          return -1;
      }
  }
}
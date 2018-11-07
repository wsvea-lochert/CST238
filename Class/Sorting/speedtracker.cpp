// A sample program for insertion sort development.

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Global constant for the array size.
const int ARRAY_SIZE = 1000000;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int size);
void insertion_sort (int values[], int size);
void insertion_sort_2 (int values[], int size);

void quick_sort(int x[], int first, int last);
int partition(int list[], int low, int high);
void swap(int &x, int &y);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    inFile.open("fifty_thousand_numbers.txt");

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
    
    cout << "Start the insertion sorting..." << endl;
    
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    quick_sort(numbers, 0, ARRAY_SIZE-1);
    
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



void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int s = partition(list, left, right);
        quick_sort(list, left, s - 1);
        quick_sort(list, s + 1, right);
    }
}


int partition(int list[], int left, int right)
{
    int pivot = list[left];
    int i = left;
    int j = right + 1;
  
    while (i < j)
    {
        do
        {
            i++;
        } while (list[i] < pivot);

        do
        {
            j--;
        } while (list[j] > pivot);

        swap(list[i], list[j]);
    }
    // undo the last swap which happened at i >= j
    swap(list[i], list[j]);
    
    // swap the pivot and list[j] to finish the partitioning.
    swap(list[left], list[j]);
    
    return j;
}


void swap(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}





// Sort an array of integer values in ascending order.
void insertion_sort (int values[], int size) 
{
   int i, j; 
   int temp;
   
   // Note that i starts from 1 to size-1.
   for (i = 1; i < size; i++) 
   { 
       temp = values[i];
       
       // Find the insertion position by searching
       // from the index i-1 to 0.
       j = i-1;
       while ((j >= 0) && (values[j] > temp)) 
       { 
           values[j+1] = values[j]; 
           j = j-1; 
       } 
       values[j+1] = temp; 
   } 
   return;
}


// Insertion sort with an inside for loop.
void insertion_sort_2 (int values[], int size) 
{
   int i, j; 
   int temp;
   
   for (i = 1; i < size; i++) 
   { 
       temp = values[i];
       for (j = i-1; j >= 0; j--)
       {
            if (values[j] > temp)
            {
                values[j+1] = values[j];        
            }
            else
            {
                values[j+1] = temp;
                break;
            }
       }
       
       // If the positon of temp value is the index 0, 
       // we should insert it here.
       if ((j == -1) && (values[0] > temp))
       {
           values[0] = temp; 
       }
   } 
   
   return;
}

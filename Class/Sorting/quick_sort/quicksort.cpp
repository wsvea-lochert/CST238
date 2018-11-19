// A sample quicksort program.
// Original pseudocode from Larry Nyhoff: ADTs, Data Structures, and Problem Solving with C++.
// Updated by Dr. Byun for CST238.
#include <iostream>
using namespace std;

// Function prototypes
void quick_sort(int x[], int first, int last);
int partition(int list[], int low, int high);
void swap(int &x, int &y);

int main()
{
   const int SIZE = 12; 
   int list[SIZE] = {75, 70, 65, 84, 98, 78, 100, 93, 55, 61, 81, 68};

   cout << "Initial list: ";
   for (int i = 0; i < SIZE; i++)
      cout << list[i] << " ";
   cout << endl;
   
   // Sort the array.
   quick_sort(list, 0, SIZE-1);
   
   cout << "Sorted list: ";
   for (int i = 0; i < SIZE; i++)
      cout << list[i] << " ";
   cout << endl;
   
   return 0;
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